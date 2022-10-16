#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool por(pair<int,int> a,pair<int,int> b)
{
    if(a.first!=b.first) return a.first<b.first;
    return a.second<b.second;
}

int main()
{
    int n; cin>>n;
    vector<pair<int,int> > a;
    vector<pair<int,int> > b;
    for(int i=0;i<n;i++)
    {
        int x,y; cin>>x>>y;
        a.push_back({x,y});
    }
    for(int i=0;i<n;i++)
    {
        int x,y; cin>>x>>y;
        b.push_back({x,y});
    }
    sort(a.begin(),a.end(),por);
    sort(b.begin(),b.end(),por);
    cout<<a[0].first+b[b.size()-1].first<<" ";
    cout<<a[0].second+b[b.size()-1].second<<" ";
    return 0;
}