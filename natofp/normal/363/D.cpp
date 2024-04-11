#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<ll> b;
vector<ll> c;
ll a;
bool czy(int n)
{
    ll t=a;
    for(int i=0;i<n;i++)
    {
        if(b[i]<c[n-i-1])
        {
            ll x=c[n-i-1]-b[i];
            if(x>t) return false;
            t-=x;
        }
    }
    return true;
}

ll getval(int n)
{
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=c[i];
    }
    return max(0LL,sum-a);
}

int BS(int lo,int hi)
{

    while(hi>lo+2)
    {
        int mid=(lo+hi)/2;
        if(czy(mid)==true)
        {
            lo=mid;
        }
        else
        {
            hi=mid-1;
        }
    }
    for(int i=hi;i>=lo;i--)
    {
        if(czy(i)==true) return i;
    }
    return 0;
}

int main()
{
    ll n,m; cin>>n>>m>>a;
    for(int i=0;i<n;i++)
    {
        ll x; cin>>x;
        b.push_back(x);
    }
    for(int i=0;i<m;i++)
    {
        ll x; cin>>x;
        c.push_back(x);
    }
    sort(b.begin(),b.end(),greater<int>());
    sort(c.begin(),c.end());
    ll r,s;
    r=BS(1,min(n,m));
    if(r==0)
    {
        cout<<0<<" "<<0<<endl; return 0;
    }
    s=getval(r);
    cout<<r<<" "<<s<<endl;
    return 0;
}