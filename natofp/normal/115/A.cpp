#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N=2e3+5;

vector<int> adj[N];
vector<int> indegree(N,0);

int ans=1;

void dfs(int v,int p)
{

    ans=max(ans,p);
    {
        for(int i=0;i<adj[v].size();i++)
        {
             dfs(adj[v][i],p+1);
        }
    }
}

int main()
{
    int n; cin>>n;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        if(x!=-1)
        {
            x--;
            adj[x].push_back(i);
            indegree[i]++;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            
            dfs(i,1);
        }
    }
    cout<<ans;
    return 0;
}