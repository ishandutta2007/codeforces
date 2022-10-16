#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int N=2e5+5;
vector<int> G[N];

struct node
{
    int val;
    int prio;
};
node tab[N];
bool por(int a,int b)
{
    return tab[a].prio<tab[b].prio;
}
vector<int> odp;
queue<int> kol;

vector<bool> visited(N,0);
void BFSS(int v)
{
    odp.push_back(v);
    visited[v]=true;
    for(int i=0;i<G[v].size();i++)
    {
        if(visited[G[v][i]]==false) kol.push(G[v][i]);
    }
}

int main()
{
    vector<int> BFS;
    int n;
    cin>>n;

    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        BFS.push_back(x);
        tab[x].val=x;
        tab[x].prio=i;
    }
    for(int i=1;i<=n;i++)
    {
        sort(G[i].begin(),G[i].end(),por);
    }
    kol.push(1);
    while(kol.empty()==false)
    {
        int x=kol.front();
        kol.pop();
        BFSS(x);
    }
    for(int i=0;i<n;i++)
    {
        if(BFS[i]!=odp[i]) {cout<<"No"; return 0;}
    }
    cout<<"Yes";




    return 0;
}