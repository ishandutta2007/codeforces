#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int ile[26];

string ss,tt;



int main()
{
    ll n; cin>>n;
    vector<ll> d;
    for(ll i=2;i<=1e6+5;i++)
    {
        if(n%i==0)
        {
            d.push_back(i);
        }
    }
    if(d.size()==0 || d[0]==n)
    {
        cout<<n<<endl; return 0;
    }
    while(n>1 && n%d[0]==0) n/=d[0];
    if(n!=1)
    {
        cout<<1<<endl; return 0;
    }
    cout<<d[0];
    return 0;
}