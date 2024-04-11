#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=3e5+5;
vector<pair<int,int> > a(nax);
int n,m;
int solve(int x)
{
    vector<int> idx;
    for(int i=2;i<=m;i++)
    {
        if(a[i].first!=x && a[i].second!=x) idx.push_back(i);
    }
    if(idx.size()==0) return -1;
    int val1=a[idx[0]].first;
    int val2=a[idx[0]].second;
    int ile1=0;
    int ile2=0;
    for(int i=0;i<idx.size();i++)
    {
        int akt=idx[i];
        if(a[akt].first==val1) ile1++;
        if(a[akt].second==val1) ile1++;
        if(a[akt].first==val2) ile2++;
        if(a[akt].second==val2) ile2++;
    }
    if(ile1<idx.size() && ile2<idx.size()) return 0;
    if(ile1==idx.size())
    {
        return val1;
    }
    return val2;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y; cin>>x>>y;
        a[i]={x,y};
    }
    int wyn=solve(a[1].first);
    if(wyn!=0)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    wyn=solve(a[1].second);
    if(wyn!=0)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
    return 0;
}