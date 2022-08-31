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
#define all(x) x.begin(),x.end()

const int N = 2e5 + 10;
vi g[N];
int a[N];
vi go[N];
int dp[N];
int p[N];

void dfs(int node,int par = -1,int dep = 1)
{
    go[dep].pb(node);
    p[node] = par;
    
    for(auto x : g[node])
        if(x != par) dfs(x,node,dep + 1);
}

void solve()
{
   int n;
   cin >> n;
    
   f(i,n) g[i].clear() , go[i].clear() , dp[i] = 0;
    
   int x;
   
   for(int i=2;i<=n;i++)
   {
       cin >> x;
       g[i].pb(x);
       g[x].pb(i);
   }
   
   for(int i=2;i<=n;i++) cin >> a[i];
    
   dfs(1,-1);
    
   int res = 0;
    
   dp[1] = 0; 
    
   for(int i=2;i<=n;i++)
   {
       if(go[i].empty()) break;
       
       int mx = 0,mn = 2e9;
       
       for(auto x : go[i])
           mx = max(mx, a[x]) , mn = min(mn,a[x]);
       
       for(auto x : go[i])
       {
           dp[x] = max(dp[x] , dp[p[x]] + abs(a[x] - mx));
           dp[x] = max(dp[x] , dp[p[x]] + abs(a[x] - mn));
           
           res = max(res,dp[x]);
       }
       
       //now also put the result here , if swap happens.
       int mx1 = -2e9,mx2 = -2e9;
       
       for(auto x : go[i])
           mx1 = max(mx1, dp[p[x]] + a[x]) , 
           mx2 = max(mx2, dp[p[x]] - a[x]);
       
       for(auto x : go[i])
       {
           dp[x] = max(dp[x] , mx1 - a[x]);
           dp[x] = max(dp[x] , mx2 + a[x]);
           
           res = max(res,dp[x]);
       }
       
   }
    
    
   cout << res << '\n'; 
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}