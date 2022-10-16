#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;



int main()
{
    int t; cin>>t;
    while(t--)
    {
        ll x; cin>>x;
        if(x<100)
        {
            while(x>20)
            {
                x-=14;
            }
            if(x>=15)
            {
                cout<<"YES"<<endl;
            }
            else cout<<"NO"<<endl;
        }
        else
        {
            x%=14;
            x+=14;
            if(x>=15 && x<=20) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}