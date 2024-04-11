#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x; cin>>x;
    for(int i=1;i<=100;i++)
    {
        for(int j=1;j<x;j++)
        {
            if(i<=x && i*j<=x && i*i*j>x) {cout<<i*j<<" "<<i; return 0;}
        }
    }
    cout<<-1;
    return 0;
}