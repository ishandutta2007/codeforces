#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int>G[400001];
bool visited[400001];

void DFS(int u)
{
    visited[u]=true;
    for(int i=0;i<G[u].size();i++)
    {
        if(visited[G[u][i]]==false)
        {

            DFS(G[u][i]);
        }
    }
}

int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=0;i<q;i++)
    {
        int r,c;
        cin>>r>>c;
        G[r].push_back(n+c);
        G[n+c].push_back(r);
    }
    int c=0;
    for(int i=1;i<=n+m;i++) visited[i]=false;
    for(int i=1;i<=n+m;i++)
    {
        if(visited[i]==false)
        {
            c++; DFS(i);
        }
    }
    cout<<c-1;

    return 0;
}