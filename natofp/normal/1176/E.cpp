#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=2e5;

vector<int> adj[nax];
int n,m;
vector<pair<int,int> > xd;
vector<bool> vis(nax,false);
vector<int> akt;
vector<int> kolor(nax,0);
void czysc()
{
    for(int i=0;i<m;i++)
    {
        adj[xd[i].first].clear();
        adj[xd[i].second].clear();
    }
    for(int i=0;i<=n;i++)
    {
       vis[i]=false;
    }
}

void dfs(int v,int color)
{
    color%=2;
    kolor[v]=color;
    vis[v]=true;
    for(int i=0;i<adj[v].size();i++)
    {
        if(vis[adj[v][i]]==true) continue;
        dfs(adj[v][i],color+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--)
    {
        xd.clear();
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            int a,b; cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            xd.push_back({a,b});
        }
        dfs(1,1);
        int a,b;
        a=b=0;
        for(int i=1;i<=n;i++)
        {
            if(kolor[i]==1) a++;
            else b++;
        }
        if(a<b)
        {
            cout<<a<<endl;
            for(int i=1;i<=n;i++)
            {
                if(kolor[i]==1) cout<<i<<" ";
            }
            cout<<endl;
        }
        else
        {

            cout<<b<<endl;
            for(int i=1;i<=n;i++)
            {
                if(kolor[i]!=1) cout<<i<<" ";
            }
            cout<<endl;
        }
        czysc();
    }
    return 0;
}