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
int sz[N];

void dfs(int node,int par = 0)
{
    dep[node] = dep[par] + 1;
    sz[node]  = 1;
    
    for(auto x : g[node])
       if(x != par) 
    {
        dfs(x,node);
        sz[node]+=sz[x];
    }
}

void solve()
{
   int n;
    cin >> n;
    
   int k;
    cin >> k;
    
   int u,v;
    
   f(i,n-1)
   {
      cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
   }
    
   dfs(1); 
    
   vector<pii> go;
    
   for(int i=1;i<=n;i++) go.pb({dep[i]-sz[i],i});
    
   sort(go.begin(),go.end());
   reverse(go.begin(),go.end());
    
   int res = 0;
    
   f(i,k)
   {
         res+=go[i].F;
   }
    
   cout << res << '\n'; 
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}