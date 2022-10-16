#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N=200005;

vector<bool> visited(N,0);
vector<int> G [N];
vector<bool> czy (N,0);
int par[N];
struct node
{
    int n;
    int depth;
};

node liscie[N];

void DFS(int n,int d,int parn)
{
    visited[n]=true;
    liscie[n].n=n;
    liscie[n].depth=d;
    par[n]=parn;
    for(int i=0;i<G[n].size();i++)
    {
        if(visited[G[n][i]]==false) DFS(G[n][i],d+1,n);
    }

}

bool por(node a,node b)
{
    return a.depth<b.depth;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    DFS(1,1,0);
    sort(liscie+1,liscie+n+1,por);
    int w=0;
    for(int i=n;i>=1;i--)
    {
        if(liscie[i].depth<=3) czy[liscie[i].n]=true;
        else
        {
            int j=liscie[i].n;
            if(czy[j]==false)
            {
                int t=par[j];
                w++;
                czy[t]=true;
                for(int k=0;k<G[t].size();k++)
                {
                    czy[G[t][k]]=true;
                }
            }
        }
    }
    cout<<w;
    return 0;
}