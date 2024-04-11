#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool por(pair<int,int> a,pair<int,int> b)
{
    int zmiana=a.first-a.second-b.first+b.second;
    return bool(zmiana>0);
}

int main()
{
    int n; cin>>n;
    vector<pair<int,int> > a;
    for(int i=0;i<n;i++)
    {
        int x,y; cin>>x>>y;
        a.push_back({x,y});
    }
    sort(a.begin(),a.end(),por);
    long long int koszt=0;
    for(int i=0;i<n;i++)
    {
        koszt+=(long long int)(i)*a[i].first;
        koszt+=(long long int)(n-i-1)*a[i].second;
    }
    cout<<koszt;
    return 0;
}