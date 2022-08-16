#include <bits/stdc++.h>
using namespace std;
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=1;i<=n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 2e5 + 10;
vi g[N];
pii dsu[N];

int find(int x)
{
    if(dsu[x].F == x) return x;
    return dsu[x].F = find(dsu[x].F);
}

bool merge(int a,int b)
{
    int x = find(a);
    int y = find(b);
    
    if(x == y) return 0;
    
    if(dsu[x].S > dsu[y].S) swap(x,y);
    dsu[x].F = dsu[y].F;
    dsu[y].S += dsu[x].S;

    g[a].pb(b);
    g[b].pb(a);
    
    return 1;
}

int sz[N];
int p[N];

void dfs(int node,int par = -1)
{
    sz[node] = 1;
    p[node] = par;
    
    for(auto x : g[node])
        if(x != par) dfs(x,node),sz[node]+=sz[x];
}

int c2(int x)
{
    return (x*(x-1))/2;
}

void solve()
{
   int n;
    cin >> n;
   
   f(i,n) dsu[i] = {i,1};
    
   int u,v;
   pii ext = {-1,-1};
    
   f(i,n)
   {
       cin >> u >> v;
       if(!merge(u,v)) 
       {
           ext = {u,v};
       }
   }
   
   u = ext.F;
   v = ext.S;
    
   dfs(u); 
   
   int res = c2(n);
   res+=c2(n);
   res-=c2(sz[v]); 
   
   while(u != v)
   {
       int prev = v;
       v = p[v];
       
       int tt = 1;
       
       for(auto x : g[v])
         if(x != p[v] && x != prev) tt += sz[x];
       
       res-=c2(tt);    
   }
    
    cout << res << '\n';
    
   f(i,n) g[i].clear(); 
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}