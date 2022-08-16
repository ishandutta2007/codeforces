#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 5004;
const int inf = 1e9+10;

vector<pii> g[N];
pii dp[N][N];
int vis[N],vis2[N];

stack<int> topo;

void dfs(int node)
{
   vis[node] = 1; 
    
   for(auto x :  g[node])
       if(!vis[x.S]) dfs(x.S);
       
   topo.push(node);
}

void solve()
{
  int n,m,t,a,b,w;
    cin >> n >> m >> t;
    
  f(i,m)
  {
    cin >> a >> b >> w;
     g[a].pb({w,b});
  }
  
  f(i,n+1)
      f(j,n+1) dp[i][j].F = inf,dp[i][j].S = -1;
    
  for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);
      
  dp[1][1].F = 0;    
     
  while(!topo.empty())
  {
     auto v = topo.top(); topo.pop();
       
     for(auto x : g[v])
     {
         if(vis2[x.S]) continue;
         
         for(int i=1;i<=n;i++)
         {
             if(dp[x.S][i].F > dp[v][i-1].F + x.F)
             {
                 dp[x.S][i].F = dp[v][i-1].F+x.F;
                 dp[x.S][i].S = v;
             }
         }
     }
      
     vis2[v] = 1; 
  }  
   
  int ans = 10;
    
  for(int i=1;i<=n;i++) if(dp[n][i].F <= t) ans = i; 
          
  cout << ans << '\n';  
    
  vi x;  
  
  int temp = n;
    
  for(int i=ans;i>=1;i--)
  {
      x.pb(temp);
      temp = dp[temp][i].S;
  }
    
  reverse(x.begin(),x.end());
    
  for(auto z : x) cout << z <<" ";
    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}