#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N=5001;

vector<int> G[N];
vector<int> G2[N];
vector<int> SCC[N];
int odp[N];
vector<int> stos;

vector<bool> visited(N+1,0);

void DFS(int u)
{

    visited[u]=true;
    for(int i=0;i<G[u].size();i++)
    {
        if(visited[G[u][i]]==false) DFS(G[u][i]);
    }
    stos.push_back(u);
}

void DFS2(int u,int cn)
{

    visited[u]=true;
    odp[u]=cn;
    for(int i=0;i<G2[u].size();i++)
    {
        if(visited[G2[u][i]]==false) DFS2(G2[u][i],cn);
    }

}

int main()
{
    int s;
    int n,m;
    cin>>n>>m>>s;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
    }
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==false) DFS(i);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<G[i].size();j++)
        {
            int x=G[i][j];
            G2[x].push_back(i);
        }
    }
    for(int i=1;i<=N;i++) visited[i]=false;
    int cn=1;
    while(stos.empty()==false)
    {
        int x=stos.back();
        stos.pop_back();
        if(visited[x]==false) {DFS2(x,cn); cn++;}

    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<G[i].size();j++)
        {
            SCC[odp[i]].push_back(odp[G[i][j]]);
        }

    }

    vector<bool> nowe(N+1,0);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<SCC[i].size();j++)
        {
            if(SCC[i][j]!=i)   nowe[SCC[i][j]]=true;
        }
    }
    int w=0;
    for(int i=1;i<=(cn-1);i++) {if(nowe[i]==false) w++;}
    int x=odp[s];
    for(int i =1;i<=cn-1;i++)
    {
        for (int j=0;j<SCC[i].size();j++)
        {
            if(i!=x && SCC[i][j]==x) { cout<<w; return 0;}
        }
    }
    cout<<--w;
    return 0;
}