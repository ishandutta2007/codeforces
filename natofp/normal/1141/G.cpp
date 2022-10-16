#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=2e5+5;
int r;
vector<pair<int,int> > adj[nax];
int kolor[nax];
void dfs(int v,int p,int jaka)
{
    int akt=1;
    for(int i=0;i<adj[v].size();i++)
    {
        if(akt==jaka) akt++;
        if(akt>r) akt=r;
        if(adj[v][i].second==p) continue;
        int krawedz=adj[v][i].first;
        int syn=adj[v][i].second;
        kolor[krawedz]=akt;
        dfs(syn,v,akt);
        akt++;
        if(akt>r) akt=r;
    }
}

int main()
{
    int n,k; cin>>n>>k;
    for(int i=0;i<n-1;i++)
    {
        int a,b; cin>>a>>b;
        adj[a].push_back({i,b});
        adj[b].push_back({i,a});
    }
    vector<int> a;
    for(int i=1;i<=n;i++)
    {
        if(adj[i].size()!=0) a.push_back(adj[i].size());
    }
    sort(a.begin(),a.end());
    int idx=max(0,n-k-1);
    r=a[idx];
    cout<<r<<endl;
    dfs(1,1,-1);
    for(int i=0;i<=n-2;i++) cout<<kolor[i]<<" ";
    return 0;
}