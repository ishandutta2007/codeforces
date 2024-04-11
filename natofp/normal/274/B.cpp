#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=1e5+5;
vector<int> adj[N];
vector<bool> visited(N,false);
vector<ll> a(N,0);
ll dp[N][2];
void dfs(int v,int p=-1)
{
    visited[v]=true;
    int t=adj[v].size();
    if(t==1 && v!=1)
    {
        if(a[v]<0) dp[v][1]=abs(a[v]);
        else dp[v][0]=a[v];
        return ;
    }
    for(int i=0;i<adj[v].size();i++)
    {
        if(visited[adj[v][i]]==false) dfs(adj[v][i],v);
    }
    ll l,r;
    l=0; r=0;
    for(int i=0;i<adj[v].size();i++)
    {
        if(adj[v][i]==p) continue;
        int x=adj[v][i];
        r=max(r,dp[x][1]);
        l=max(l,dp[x][0]);
    }

    ll sum=r-l;
    ll ile=sum+a[v];
    if(ile>=0LL)
    {
        l+=ile;
        dp[v][0]=l;
        dp[v][1]=r;
    }
    else
    {
        r+=-ile;
        dp[v][0]=l;
        dp[v][1]=r;
    }

}

int main()
{
    int n; cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<2;j++)
        {
            dp[i][j]=0LL;
        }
    }
    if(n==1) return abs(a[0]);
    dfs(1);
    cout<<dp[1][0]+dp[1][1];
    return 0;
}