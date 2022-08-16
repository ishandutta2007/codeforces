#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 5004;
vi g[N];

int depth[N];
int par[N];
vi edge(N,1);
int c = 0;

void dfs(int node,int p = -1)
{
    if(p == -1) depth[node] = 0;
    else depth[node] = depth[p] + 1;
    
    par[node] = p;

    for(auto z : g[node]) if(z != p) dfs(z,node);
}

void go(int & a,int b)
{
  if(b>a) a = b;
}
    
void apply(int l,int r,int x)
{
    while(depth[l] > depth[r])
    {
        go(edge[l],x);
        l = par[l];
    }
    
    while(depth[l] < depth[r])
    {
        go(edge[r],x);
        r = par[r];
    }
    
    while(l != r)
    {
        go(edge[r],x);
        go(edge[l],x);
        l = par[l];
        r = par[r];
    }
}


void check(int l,int r,int x)
{   
    while(depth[l] > depth[r])
    {  
        if(edge[l] == x) return;
        l = par[l];    
    }

    while(depth[l] < depth[r])
    {
       if(edge[r] == x) return;  
       r = par[r];
    }
    
    while(l != r)
    {
        if(edge[l] == x) return;       
        if(edge[r] == x) return;        
        l = par[l];
        r = par[r];
    }
    
        cout << -1;
        exit(0);   
}

void solve()
{
    int n;
    cin >> n;
    
    int a,b;
    
    pii ed[n-1];

    f(i,n-1)
    {
    cin >> a >> b;
    g[a].pb(b);
    g[b].pb(a);
    ed[i] = {a,b};
    }
    
    dfs(1);
    
    int q;
    cin >> q;
    
    int l,r,x;
    
    pair<pii,int> data[q];
    
    f(i,q) cin >> data[i].F.F >> data[i].F.S >> data[i].S;
    f(i,q) apply(data[i].F.F,data[i].F.S,data[i].S);
    f(i,q) check(data[i].F.F,data[i].F.S,data[i].S);

    f(i,n-1)
    {   
       if(ed[i].F == par[ed[i].S]) cout << edge[ed[i].S] << " ";
       else cout << edge[ed[i].F] << " ";
    }
}

signed main()
{
    fast;
    solve();
}