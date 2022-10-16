#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool por(pair<ll,ll> a,pair<ll,ll> b)
{
    return a.first-a.second>b.first-b.second;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        vector<pair<ll,ll> > a;
        ll hp;
        ll n;
        cin>>n>>hp;
        for(int i=0;i<n;i++)
        {
            ll x; cin>>x;
            ll y; cin>>y;
            a.push_back({x,y});
        }
        sort(a.begin(),a.end(),por);
        ll maxx=0;
        for(int i=0;i<n;i++) maxx=max(maxx,a[i].first);
        ll diff=a[0].first-a[0].second;
        if(maxx<hp && diff<=0)
        {
            cout<<-1<<endl;
            continue;
        }
        hp-=maxx;
        ll ile=1;
        if(hp<=0)
        {
            cout<<ile<<endl; continue;
        }
        ile+=(hp+diff-1)/diff;
        cout<<ile<<endl;
    }
    return 0;
}