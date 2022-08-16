#include <bits/stdc++.h>
using namespace std;
  
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 2e5 + 10;

vector<pii> und;
vi g[N];
vi topo;
int ord[N];
int vis[N];
int flag = 0;

void dfs(int node)
{
    vis[node] = 1;
    
    for(auto x : g[node])
        if(vis[x] == 0) dfs(x);
        else if(vis[x] == 1) flag = 1;
        
   vis[node] = 2;    
        
    topo.pb(node);
}
        
void solve()
{
   int n,m;
    cin >> n >> m;
       
   int t,u,v; 
    
   f(i,m)
   {
       cin >> t >> u >> v;
       
       if(t == 0) und.pb({u,v});
       else g[u].pb(v);
   }
    
   int cnt = 0; 
    
   for(int i=1;i<=n;i++) if(vis[i] == 0)
   {
       dfs(i); 
       for(auto x : topo) ord[x] = cnt++;
       topo.clear(); 
   }
  
   if(flag == 0) 
   {
   for(auto & x : und) 
       if(ord[x.F] < ord[x.S]) swap(x.F,x.S);
    
   cout <<"YES\n";
   
   for(int i=1;i<=n;i++)
       for(auto x : g[i]) cout << i << ' ' << x << '\n';
    
   for(auto x : und) cout << x.F << ' ' << x.S << '\n';
   }
   else cout <<"NO\n"; 
    
   und.clear();
   for(int i=1;i<=n;i++) g[i].clear();
   topo.clear();
   for(int i=1;i<=n;i++) vis[i] = 0;
   flag = 0;
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}