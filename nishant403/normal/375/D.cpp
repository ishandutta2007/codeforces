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

const int MOD = 1e9+7;

int mod_pow(int a,int b,int M = MOD)
{
    if(a == 0) return 0;
    b %= (M - 1);  //M must be prime here
    
    int res = 1;
    
    while(b > 0)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}


const int N = 1e5 + 10;

vi g[N];
int a[N];
int tin[N],tout[N],ord[N],tim = 0;
int sz[N];

vector<pii> qq[N];
int res[N];

int fre[N];

void dfs(int node,int par = -1)
{
    sz[node] = 1;
    
    ord[tim] = node;
    tin[node] = tout[node] = tim++;
    
    for(auto x : g[node])
    {
        if(x == par) continue;
        dfs(x,node);
        sz[node] += sz[x];
        tout[node] = tout[x];
    }
}

int ft[N];

void add(int col,int flag)
{
    if(flag == -1) ft[fre[col]]--;
    
    fre[col] += flag;
    
    if(flag == 1) ft[fre[col]]++;
}

void dfs2(int node,int par = -1,int save = 1)
{
    int heavy = -1;
    
    for(auto x : g[node])
      if(x != par)
    {
        if(heavy == -1) heavy = x;
        else if(sz[x] > sz[heavy]) heavy = x;
    }
    
    for(auto x : g[node])
        if(x != par && x != heavy) dfs2(x,node,-1);
        
    if(heavy != -1)
        dfs2(heavy,node,1);
        
    for(auto x : g[node])
        if(x != par && x != heavy) 
          for(int i=tin[x];i<=tout[x];i++) add(a[ord[i]] , 1);
    
    //add current vertex
    add(a[node],1);   
     
    //get the answer
    for(auto z : qq[node])
    {
         res[z.S] = ft[z.F];
    }
    
    if(save == -1) 
        for(int i=tin[node];i<=tout[node];i++) add(a[ord[i]] , -1);
}

void solve()
{
    int n,q;
    cin >> n >> q;
    
    for(int i=1;i<=n;i++) cin >> a[i];
    
    int u,v;
    
    f(i,n-1)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    f(i,q)
    {
        cin >> u >> v;
        qq[u].pb({v,i});
    }
    
    dfs(1);
    dfs2(1);
    
    f(i,q) cout << res[i] << '\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}