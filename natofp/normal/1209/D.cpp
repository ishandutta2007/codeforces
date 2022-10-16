#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int roz=1;

const int nax=1e5+5;
vector<int> adj[nax];

bool czy[nax];

void dfs(int v)
{
    czy[v]=true;
    roz++;
    for(int i=0;i<adj[v].size();i++)
    {
        int cel=adj[v][i];
        if(czy[cel]==false) dfs(cel);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k; cin>>n>>k;
    vector<ll> a;
    for(int i=0;i<k;i++)
    {
        ll x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int res=0;
   for(int i=1;i<=n;i++)
   {
       if(czy[i]==false)
       {
           roz=0;
           dfs(i);
            res+=roz-1;
       }
   }
   cout<<k-res;
    return 0;
}