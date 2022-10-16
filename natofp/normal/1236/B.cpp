#include <iostream>
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const int mod=1e9+7;

ll pp(ll a,ll b)
{
    if(b==0) return 1;
    ll res=pp(a,b/2);
    res%=mod;
    res*=res;
    res%=mod;
    if(b%2==1) res*=a;
    res%=mod;
    return res;

}

int main()
{
    long long int n,m; cin>>n>>m;
    ll akt=pp(2LL,m);
    akt--;
    if(akt<0) akt+=mod;
    akt=pp(akt,n);
    cout<<akt;
    return 0;
}