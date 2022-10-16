#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N=1e5+5;
vector<int> adj[N];
bool czy[N];

int main()
{
    memset(czy,false,sizeof czy);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> res;
    res.push_back(1);
    czy[1]=true;
    set<int> a;
    for(int i=0;i<adj[1].size();i++)
    {
       a.insert(adj[1][i]);
    }
    while(res.size()<n)
    {
        auto it=a.begin();
        while(czy[*it]==true)
        {
            a.erase(it); it=a.begin();
        }
        int t=*it;
        czy[t]=true;
        res.push_back(t);
        for(int i=0;i<adj[t].size();i++)
        {
            a.insert(adj[t][i]);
        }
    }
    for(int i=0;i<n;i++) cout<<res[i]<<" ";
    return 0;
}