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

const int N = 3e5  + 10;
vi g[N];
int vis[N];
int col[N];

void dfs(int node,int par = -1)
{
    vis[node] =1 ;
    
    for(auto x : g[node])
        if(!vis[x]) dfs(x,node);
}

void solve()
{
   int n,m;
    cin >> n >> m;
    
   f(i,n) g[i].clear(); 
   int u,v;
    
   f(i,m)
   {
       cin >> u >> v;
       g[u].pb(v),g[v].pb(u);
   }
    
   f(i,n) col[i] = -1, vis[i] = 0; 
    
   dfs(1);
    
   f(i,n) if(vis[i]==0)
   {
       cout << "NO\n";
       return;
   }
    
   queue<int> q;
   q.push(1);
    
   f(i,n) vis[i] = 0,col[i] = -1;
    
   while(!q.empty())
   {
       auto x = q.front();
       q.pop();
       
       if(vis[x]) continue;
       vis[x] = 1;
       
       if(col[x] == -1)
       {
           col[x] = 1;
           for(auto v : g[x])  col[v] = 0;
       }
       
       for(auto v : g[x])
       {
           if(!vis[v])  q.push(v);
       }
   }
    
   cout <<"YES\n";
    
   vi go;
    f(i,n) if(col[i] == 1) go.pb(i);
        cout << go.size() << '\n';
    for(auto x : go) cout << x << ' ';
    cout << '\n';   
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}