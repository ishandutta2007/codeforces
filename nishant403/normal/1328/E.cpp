#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int MOD = 1e9+7;

int mod_pow(int a,int b,int M = MOD)
{
    int res = 1;
    
    while(b)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}

const int N = 2e5+10;
vi g[N];
int dep[N];
vi que[N];
vi qq[N];
int res[N];
int vis[N];

void dfs(int node,int par = -1)
{
    if(par == -1) dep[node] = 0;
    else dep[node] = dep[par] + 1;
    
    for(auto x : g[node])
        if(x != par) dfs(x,node);
}

void dfs2(int node,int par = -1)
{
    vis[node] = 1;
    for(auto x : g[node]) vis[x] = 1;
      
    // solve queries here
    for(auto x : qq[node])
    {
        int flag = 1;
        
        for(auto y : que[x])
            if(vis[y] == 0) flag = 0;
            
        res[x] = flag;
    }
        
    for(auto x : g[node])
        if(x != par) dfs2(x,node);
        
    for(auto x : g[node])
        if(x != par) vis[x] = 0;
}

void solve()
{
   int n,q;
   cin >> n >> q;
     
   int u,v;
    
   f(i,n-1)
   {
       cin >> u >> v;
       g[u].pb(v);
       g[v].pb(u);
   }
    
   dfs(1); 
    
   f(i,q)
   { 
      int k;
      cin >> k;
       
      int x;
       
      f(j,k) 
      {
          cin >> x;
          que[i].pb(x);
      }
      
      int nd = 0;
       
      f(j,k)
      {
          if(dep[que[i][j]] > dep[que[i][nd]]) nd = j;
      }
       
      qq[que[i][nd]].pb(i);
   }
   
   dfs2(1);
    
   f(i,q) if(res[i] == 1) cout <<"YES\n";
       else cout <<"NO\n";
}

signed main()
{
    fast;
    solve();
}