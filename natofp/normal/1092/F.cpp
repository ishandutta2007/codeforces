#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int N=2e5+5;
vector<long long int> a(N,-1);
vector<int> adj[N];
vector<long long int> h(N,-1);
vector<bool> visited(N,false);
vector<long long int> ans(N,0);
vector<long long int> sum(N,0);
long long int ful=0;
long long int dfs(int v,int d=0)
{
    visited[v]=true;
     sum[v]+=a[v];
    h[v]=d;
    for(int i=0;i<adj[v].size();i++)
    {
        if(visited[adj[v][i]]==false) sum[v]+=dfs(adj[v][i],d+1);

    }

    return sum[v];
}

void dfs2(int v,int par=-1)
{
    visited[v]=true;
    if(par!=-1)
    {
        ans[v]=ans[par]+ful-2*sum[v];
    }
    for(int i=0;i<adj[v].size();i++)
    {
        if(visited[adj[v][i]]==false) dfs2(adj[v][i],v);
    }
    return ;
}

int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
    int n; cin>>n;
    for(int i=0;i<n;i++) cin>>a[i+1];
    for(int i=1;i<=n;i++)
    {
        ful+=a[i];
    }
    for(int i=0;i<n-1;i++)
    {
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    long long int xd=0;
    for(int i=2;i<=n;i++)
    {
        xd+=a[i]*h[i];
    }
    ans[1]=xd;
    for(int i=1;i<=n;i++) visited[i]=false;
    dfs2(1);
    long long int wyn=0;
    for(int i=1;i<=n;i++) wyn=max(wyn,ans[i]);
    cout<<wyn;
    return 0;
}