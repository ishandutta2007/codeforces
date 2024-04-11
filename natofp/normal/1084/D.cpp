#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N=3e5+5;
vector<pair<int,long long int>> adj[N];
vector<long long int> a(N,0);

vector<bool> visited(N,false);
vector<long long int> dp(N,0);
vector<int> childrens[N];
long long int ans=0;

void dfs(int v,int kt)
{
    long long int w=0;
    visited[v]=true;
    int ile=0;

        for(int i=0;i<adj[v].size();i++)
        {
            if(visited[adj[v][i].first]==false)
            {
                ile++;
                childrens[v].push_back(adj[v][i].first);
                dfs(adj[v][i].first,v);
            }
        }
        if(ile==0)
        {
            dp[v]=a[v];
            ans=max(ans,dp[v]);
        }
        dp[v]=a[v];
        long long int x,y;
        x=0; y=0;
        for(int i=0;i<adj[v].size();i++)
        {
            if(adj[v][i].first!=kt)
            {
                if(x<=y)
                {
                    if(dp[adj[v][i].first]-adj[v][i].second>x)
                    {
                        x=dp[adj[v][i].first]-adj[v][i].second;
                    }
                }
                else
                {
                    if(dp[adj[v][i].first]-adj[v][i].second>y)
                    {
                        y=dp[adj[v][i].first]-adj[v][i].second;
                    }
                }
                dp[v]=max(dp[v],dp[adj[v][i].first]+a[v]-adj[v][i].second);
            }
        }
        ans=max(ans,x+y+a[v]);

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   int n; cin>>n;
   for(int i=0;i<n;i++) cin>>a[i+1];
   for(int i=0;i<n-1;i++)
   {
       int u,v,c;
       cin>>u>>v>>c;
       adj[u].push_back(make_pair(v,c));
       adj[v].push_back(make_pair(u,c));
   }
   dfs(1,-1);
   cout<<ans;

    return 0;
}