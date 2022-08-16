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
#define all(x) x.begin(),x.end()
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int N = 2e5 + 10;
const int LN = 18;

vi graph[N];
int par[N][LN],dep[N];
int sz[N];

int c2(int x)
{
    return (x*(x-1))/2;
}

void dfs(int node,int p=-1)
{
    sz[node] = 1;
    
    par[node][0] = p;
    
    if(p == -1) dep[node] = 0;
    else dep[node] = dep[p] + 1;
    
    for(auto x : graph[node]) if(x!=p)
    {
        dfs(x,node);
        sz[node] += sz[x];
    }
}

int lca(int a,int b)
{
 if(dep[a] > dep[b]) swap(a,b);  
 
 int z = dep[b] - dep[a];
   
 for(int i=LN-1;i>=0;i--) if(1LL<<i & z) b = par[b][i];   
     
 if(a==b) return a;    
     
 for(int i=LN-1;i>=0;i--) if(par[a][i] != par[b][i]) a=par[a][i],b=par[b][i];  
 
 return par[a][0];  
}

int dis(int u,int v)
{
    return dep[u] + dep[v] - 2*dep[lca(u,v)];
}

void add(int & u,int & v,int w)
{
    //case w is in the path
    if(dis(u,w) + dis(v,w) == dis(u,v)) return;
    
    //w is outside u
    if(dis(w,u) + dis(v,u) == dis(w,v)) 
    {
        u = w;
        return;
    }
    
    //w is outside v
    if(dis(w,v) + dis(u,v) == dis(w,u))
    {
        v = w;
        return;
    }
    
    u = v = -1;
}

int kdis(int u,int k)
{
   for(int i=LN-1;i>=0;i--) if(1LL<<i & k) u = par[u][i];   
   return u;
}

int n;

//number of paths that cover path of u and v
int cc(int & u,int & v)
{
    int lc = lca(u,v);
    
    if(lc == v) swap(u,v);
    
    if(lc == u)
    {
        int dd = dep[v] - dep[u];
        int kk = kdis(v,dd-1);
        return sz[v]*(n - sz[kk]);
    }
    else
    {
        return sz[u]*sz[v];
    }
}

int res[N];

void solve()
{
   cin >> n;
    
   for(int i=0;i<LN;i++)
       f(j,n) par[j][i] = -1;
    
   int u,v;
    
   f(i,n-1)
   {
       cin >> u >> v;
       graph[u].pb(v);
       graph[v].pb(u);
   }
    
   dfs(0); 
    
   for(int i=1;i<LN;i++)
      for(int j=0;j<n;j++)
        if(par[j][i-1] != -1)  
           par[j][i] = par[par[j][i-1]][i-1];  
       
   int tot = c2(n);   
       
   int path = 0;
   for(auto x : graph[0]) path += c2(sz[x]);
   res[0] = path; 
    
   tot -= path; 
    
   u = 0;
   v = 1;
    
   for(int i=1;i<n;i++)
   {
       if(u == -1)
       {
           res[i] = tot;
           tot = 0;
           break;
       }
       
       int jo = cc(u,v);
       
       res[i] = tot - jo;
       
       tot = jo;
      
       add(u,v,i+1);
   }
    
   res[n] = tot;
    
   f(i,n+1) cout << res[i] << ' ';
    cout << '\n';
    
   f(i,n+1) res[i] = 0; 
   f(i,n) graph[i].clear();
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}