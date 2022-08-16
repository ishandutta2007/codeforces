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
#define f(i,n) for(int i=1;i<=n;i++)
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

const int N = 2e5 + 10;
vi g[N];
vi gr[N];

int vis[N];
int d[N];
int res[N];
       
void solve()
{
   int n,m;
    cin >> n >> m;
    
   int u,v;
    
   f(i,m)
   {
       cin >> u >> v;
       g[u].pb(v);
       gr[v].pb(u);
   }
    
   queue<pii> q;
    q.push({0,1});
    
   f(i,n) vis[i] = 0;
    
   while(!q.empty())
   {
       auto x = q.front();
       q.pop();
       
       if(vis[x.S]) continue;
       vis[x.S] = 1;
       d[x.S] = x.F;
       
       for(auto v : g[x.S])
       {
           if(!vis[v]) q.push({x.F+1,v});
       }
   }
    
   f(i,n) res[i] = d[i];
   
   f(i,n)
   {
       for(auto x : g[i])
           if(d[x] <= d[i]) res[i] = min(res[i],d[x]);
   }
    
   vector<pii> go;
    f(i,n) go.pb({res[i],i});
    sort(go.begin(),go.end());
    
   for(auto x : go)
   {
       queue<int> q;
       
       for(auto v : gr[x.S])
           if(d[v] < d[x.S]) q.push(v);
       
       while(!q.empty())
       {
           auto v = q.front(); q.pop();  
        
           if(res[v] <= res[x.S]) continue;
           
           res[v] = res[x.S];
           
           for(auto h : gr[v])
               if(d[h] < d[v] && res[h] > res[v]) q.push(h);
       }
   }
    
   f(i,n) cout << res[i] << ' ';
    cout << '\n';
       
   f(i,n) g[i].clear();
   f(i,n) gr[i].clear();
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}