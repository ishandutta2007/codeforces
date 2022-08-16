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

const int N = 2e5 + 10;
vi g[N];
int c[N];
int b[N];
int a[N];
int go0[N];
int go1[N];
int dp[N];
int dp2[N];

void dfs(int node,int p=-1)
{
  if(b[node] == 0 && c[node] == 1) go1[node]++;
  if(b[node] == 1 && c[node] == 0) go0[node]++;
    
  if(p == -1) dp2[node] = a[node];
  else dp2[node] = min(a[node],dp2[p]);
    
  for(auto x : g[node])
  if(x!=p) 
  {
      dfs(x,node);
      go0[node]+=go0[x];
      go1[node]+=go1[x];
  }   
}

void dfs2(int node,int p = -1)
{
    for(auto x : g[node]) if(x != p) dfs2(x,node);
 
    int on = 0;
    int zr = 0;
    
    if(b[node] == 0 && c[node] == 1) on++;
    if(b[node] == 1 && c[node] == 0) zr++;
     
    dp[node] = 0;
    
    for(auto x : g[node]) if(x != p)
    {
        int oo = go0[x];
        int ii = go1[x];
        
        if(oo > ii) zr+=oo-ii;
        else on+=ii-oo;
        
        dp[node]+=min(dp[x],dp2[node]*min(oo,ii)*2);
    }
        
    dp[node]+=dp2[node]*min(zr,on)*2;
}

void solve()
{
   int n,u,v;
    cin >> n;
    
   f(i,n) cin >> a[i] >> b[i] >> c[i];
       
   f(i,n-1)
   {
       cin >> u >> v;
       g[u].pb(v);
       g[v].pb(u);
   }
    
   int cnt = 0;
    
   f(i,n) cnt+=b[i]-c[i];
   
   if(cnt != 0)
   {
       cout << -1;
       return;
   }
    
   dfs(1); 
   dfs2(1);
    
   cout << dp[1]; 
}

signed main()
{
    fast;
    solve();
}