#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll a,b; cin>>a>>b;
    ll ile=1;
    int t=1;
    while(1)
    {
        if(t%2==1)
        {
            if(ile>a)
            {
                cout<<"Vladik";
                return 0;
            }
            a-=ile;
            ile++;
            t++;
        }
        else
        {
            if(ile>b)
            {
                cout<<"Valera";
                return 0;
            }
            b-=ile;
            ile++;
            t++;
        }
    }
    return 0;
}