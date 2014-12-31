//
//  main.cpp
//  CounterGameHackerRank
//
//  Created by Raquel Alvarez on 12/31/14.
//  Copyright (c) 2014 R. All rights reserved.
//
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long int largestPowerOf2(unsigned long long int n)
{
    return pow(2,floor(log2(n)));
}

bool powerOf2(unsigned long long int n)
{
    for (int i = 0; i < 64; i++)
    {
        if (n == pow(2,i))
        {
            return true;
            //i = 64;
        }
    }
    return false;
}


string counter(unsigned long long int n)
{
    string Louise = "Louise";
    string Richard = "Richard";
    bool louise = false;
    
    while (n > 1)
    {
        louise = !louise;
        if (!powerOf2(n))
        {
            n = n - largestPowerOf2(n);
        }
        else
        {
            n = n/2;
        }
        
    }
    
    if (louise)
        return Louise;
    else
        return Richard;
}


int main()
{
    int t;
    unsigned long long int* n;
    string winner;
    
    cin >> t;
    
    n = new unsigned long long int[t]();
    
    for (int i = 0; i < t; i++)
    {
        cin >> n[i];
    }
    
    for (int j = 0; j < t; j++)
    {
        if (n[j] > 1)
        {
            winner = counter(n[j]);
            cout << winner << endl;
        }
        else
            cout << "Richard" << endl;
    }
    
    return 0;
}