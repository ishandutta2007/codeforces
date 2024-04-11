#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> adj[101];
vector<bool> visited(101,false);

void dfs(int v)
{
    visited[v]=true;
    for(int i=0;i<adj[v].size();i++)
    {
        if(visited[adj[v][i]]==false) dfs(adj[v][i]);
    }
}

int main()
{

 int n; cin>>n;
 vector<pair<int,int> > a;
 for(int i=0;i<n;i++)
 {
     int x,y; cin>>x>>y;
     a.push_back({x,y});
 }

 for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j) continue;
            else
            {
                int x,y;
                x=a[i].first;
                y=a[i].second;
                if(x==a[j].first || y==a[j].second)
                {
                    adj[i].push_back(j);
                }
            }
        }
    }
    int ile=0;
  for(int i=0;i<n;i++)
  {
     if(visited[i]==false)
     {
         ile++;
         dfs(i);
     }
  }
  cout<<ile-1;
    return 0;
}