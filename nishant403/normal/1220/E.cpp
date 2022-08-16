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

const int N = 2e5+10;
vi g[N],val(N),vis(N,0),cyc(N,0),dp(N,0);

void dfs(int node,int par = -1)
{
 vis[node] = 1;  
    
 for(auto x : g[node])
 {
     if(x==par) continue;
     else if(vis[x]==0) 
     {
         dfs(x,node);
         cyc[node]=cyc[x]|cyc[node];
     }
     else cyc[node] = 1;
     
 } 
      
 if(cyc[node] == 0)
 {  
  for(auto x : g[node])   
     if(x!=par) dp[node]=max(dp[node],dp[x]);
      
  dp[node]+=val[node];    
 }
    
}

void solve()
{
  int n,m,a,b,s,ans=0,doo=0;
  cin>>n>>m;
   
  f(i,n) cin >> val[i];
    
  f(i,m)
  {
      cin >> a >> b;
      g[a].pb(b);
      g[b].pb(a);
  }
  
  cin >> s;  
  dfs(s); 
   
  f(i,n)
  {
   if(cyc[i]==1) ans+=val[i];
   else  doo=max(doo,dp[i]);
  }
    
  cout << ans+doo;
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}