#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;


int main()
{
    ll n; cin>>n;
    ll d,e; cin>>d>>e;
    ll minmod=1e9+5;
    minmod=n%d;
    int cnt=0;
    while(n>=5*e)
    {
        cnt++;
        n-=5*e;
        minmod=min(minmod,n%d);
        if(cnt==200)break;
    }
    cout<<minmod;
    return 0;
}