#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define mp make_pair

using namespace std;

const int nax = 1e5 + 5;
vector<int> adj[nax];
int dep[nax];
int par[nax];

void dfs(int v,int p,int lv)
{
    dep[v] = lv;
    par[v] = p;
    for(int x : adj[v])
    {
        if(x != p) dfs(x,v,lv+1);
    }
}

void solve()
{
    int n,a,b,da,db;
    cin>>n>>a>>b>>da>>db;
    for(int i=1;i<=n;i++)
    {
        adj[i].clear();
    }
    for(int i=1;i<n;i++)
    {
        int x,y; cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1,1,0);
    int root = 0;
    int g = 0;
    for(int i=1;i<=n;i++)
    {
        if(dep[i] > g)
        {
            g = dep[i];
            root = i;
        }
    }
    dfs(root,root,0);
    int diam = 0;
    for(int i=1;i<=n;i++) diam = max(diam,dep[i]);
    if(da * 2 >= db)
    {
        cout<<"Alice"<<"\n";
        return;
    }
    if(diam <= da * 2)
    {
        cout<<"Alice"<<"\n";
        return;
    }
    int dist = 0;
    while(a != b)
    {
        if(dep[a] > dep[b])
        {
            a = par[a];
        }
        else b = par[b];
        dist++;
    }
    if(dist <= da)
    {
        cout<<"Alice"<<"\n";
        return;
    }
    cout<<"Bob"<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}