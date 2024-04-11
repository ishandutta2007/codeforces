#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int nax=5005;
vector<pair<int,int> > adj[nax];
vector<int> deg(nax,0);
int n,m;

vector<bool> odw(nax,false);
vector<int> kraw(nax,0);


void dfs(int v)
{
    odw[v]=true;
    for(int i=0;i<adj[v].size();i++)
    {
        int cel=adj[v][i].first;
        int nr=adj[v][i].second;
        //cout<<cel<<endl;
        if(odw[cel]==false)
        {
            kraw[nr]=1;
            dfs(cel);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y; cin>>x>>y;
        adj[x].push_back({y,i+1});
        deg[y]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(odw[i]==false) dfs(i);
    }
    vector<int> ziomki;
    for(int i=1;i<=n;i++)
    {
        if(deg[i]==0) ziomki.push_back(i);
    }
    int wsk=0;
    while(wsk!=ziomki.size())
    {
        int akt=ziomki[wsk++];
        //cout<<akt<<endl;
        for(int i=0;i<adj[akt].size();i++)
        {
            int cel=adj[akt][i].first;
            deg[cel]--;
            if(deg[cel]==0) ziomki.push_back(cel);
        }
    }
    if(ziomki.size()==n)
    {
        cout<<1<<endl;
        for(int i=1;i<=m;i++) cout<<1<<" ";
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            int akt=adj[i][j].first;
            int nr=adj[i][j].second;
            if(akt>i) kraw[nr]=2;
            else kraw[nr]=1;
        }
    }
    cout<<2<<endl;
    for(int i=1;i<=m;i++) cout<<kraw[i]<<" ";
    return 0;
}