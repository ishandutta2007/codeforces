#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int,int> > a1;
vector<pair<int,int> > a2;

bool por(pair<int,int> a,pair<int,int> b)
{
    if(a.first+a.second==b.first+b.second) return a.first<b.first;
    return a.first+a.second>b.first+b.second;
}

bool por2(pair<int,int> a,pair<int,int> b)
{
    if(a.first+a.second==b.first+b.second) return a.first>b.first;
    return a.first+a.second<b.first+b.second;
}

const int nax=6e5+5;

int poz[nax];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y; cin>>x>>y;
        if(x>y) a1.push_back({x,y});
        else a2.push_back({x,y});
        poz[x]=poz[y]=i+1;
    }
    if(a2.size()>=a1.size())
    {
        sort(a2.begin(),a2.end(),por);
        cout<<a2.size()<<endl;
        for(int i=0;i<a2.size();i++)
        {
            cout<<poz[a2[i].first]<<" ";
        }
        return 0;
    }
    else
    {
        sort(a1.begin(),a1.end(),por2);
        cout<<a1.size()<<endl;
        for(int i=0;i<a1.size();i++)
        {
            cout<<poz[a1[i].first]<<" ";
        }
        return 0;
    }
    return 0;
}