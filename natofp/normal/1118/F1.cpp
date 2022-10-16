#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
const int N=3e5+5;
vector<int> adj[N];
vector<int> a;
int dp[N][2];
int res=0;
int ile0=0;
int ile1=0;
void dfs(int v,int p)
{
    for(int i=0;i<adj[v].size();i++)
    {
        if(adj[v][i]!=p)
        {
            dfs(adj[v][i],v);
            dp[v][0]+=dp[adj[v][i]][0];
            dp[v][1]+=dp[adj[v][i]][1];
        }
    }
    if(a[v]==1) dp[v][0]++;
    if(a[v]==2) dp[v][1]++;
}

void dfs2(int v,int p)
{
    for(int i=0;i<adj[v].size();i++)
    {
        if(adj[v][i]==p) continue;
        int to=adj[v][i];
        if(dp[to][0]==0 && dp[to][1]==ile1) {res++;}
        if(dp[to][0]==ile0 && dp[to][1]==0) {res++;}
        dfs2(adj[v][i],v);
    }
}

int main()
{
    memset(dp,0,sizeof dp);
    a.push_back(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        a.push_back(x);
        if(x==1) ile0++;
        if(x==2) ile1++;
    }
    for(int i=0;i<n-1;i++)
    {
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,1);
    dfs2(1,1);
    cout<<res;
    return 0;
}