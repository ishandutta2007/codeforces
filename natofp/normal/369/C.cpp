#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N=1e5+5;
vector<pair<int,int> > adj[N];
vector<long long int> dp(N,0);
vector<bool>visited(N,false);
vector<int> ans;

void dfs(int v,int p=-1)
{
    visited[v]=true;
    for(int i=0;i<adj[v].size();i++)
    {
        if(visited[adj[v][i].first]==false) dfs(adj[v][i].first,v);
    }
    for(int i=0;i<adj[v].size();i++)
    {
        if(adj[v][i].first==p) continue;
        dp[v]+=dp[adj[v][i].first];
        if(dp[adj[v][i].first]==0)
        {
            if(adj[v][i].second==2)
            {
                dp[v]++;
                ans.push_back(adj[v][i].first);
            }
        }
    }

}

int main()
{
    int n; cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int a,b,c; cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    dfs(1);
    cout<<dp[1]<<endl;
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    return 0;
}