#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int n;
vector<int> a;
ll x,y,xa,yb;
ll k;

bool ok(ll v)
{
    ll duze=v/(x*y/__gcd(x,y));
    ll jedne=v/x-duze;
    ll drugie=v/y-duze;
    ll sum=0;
    ll sumka1=0;
    ll sumka2=0;
    for(int i=a.size()-1;i>=a.size()-duze;i--)
    {
        sum+=a[i];
    }
    sum*=(xa+yb);
    if(xa>=yb)
    {
        for(int i=a.size()-duze-1;i>=a.size()-duze-jedne;i--)
        {
            sumka1+=(a[i]);
        }
        for(int i=a.size()-duze-jedne-1;i>=a.size()-duze-jedne-drugie;i--)
        {
            sumka2+=a[i];
        }
    }
    else
    {
        for(int i=a.size()-duze-1;i>=a.size()-duze-drugie;i--)
        {
            sumka1+=(a[i]);
        }
        for(int i=a.size()-duze-drugie-1;i>=a.size()-duze-jedne-drugie;i--)
        {
            sumka2+=a[i];
        }
    }
    ll res=0;
    res+=sum;
    if(xa>=yb)
    {
        res+=xa*sumka1;
        res+=yb*sumka2;
    }
    else
    {
        res+=xa*sumka2;
        res+=yb*sumka1;
    }
    res/=100;
    if(res>=k) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q; cin>>q;
    while(q--)
    {
        cin>>n;
        a.clear();
        for(int i=0;i<n;i++)
        {
            int x; cin>>x;
            a.push_back(x);
        }
        sort(a.begin(),a.end());
        cin>>xa>>x>>yb>>y;
        cin>>k;
        bool czy=ok(n);
        if(czy==false)
        {
            cout<<-1<<endl; continue;
        }
        int lo=1;
        int hi=n;
        while(lo+1<hi)
        {
            int mid=(lo+hi)/2;
            bool czy=ok(mid);
            if(czy) hi=mid;
            else lo=mid;
        }
        if(ok(lo)) cout<<lo<<endl;
        else cout<<lo+1<<endl;


    }
    return 0;
}