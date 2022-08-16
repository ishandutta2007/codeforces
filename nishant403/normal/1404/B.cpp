#include <bits/stdc++.h>
using namespace std;
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 1e5 + 10;

vi g[N];
int n,da,db,a,b;
int dep[N];
int dp[N];
int p[N];
int res = 0;

void dfs(int node,int par = 0)
{
    dep[node] = dep[par] + 1;
    
    p[node] = par;
    
    dp[node] = 0;
    
    vi go;
    
    for(auto x : g[node])
    {
        if(x == par) continue;
        dfs(x,node);
        dp[node] = max(dp[node],dp[x] + 1);
        go.pb(dp[x]);
    }
    
    sort(go.begin(),go.end());
    reverse(go.begin(),go.end());
    
    if(go.size() > 1) res = max(res, go[0] + go[1] + 2);
    
    res = max(res,dp[node]);
}

void solve()
{
  cin >> n >> a >> b >> da >> db;
    
  res = 0;  
    
  for(int i=1;i<=n;i++) g[i].clear();
    
  int u,v;
    
  f(i,n-1)
  {
      cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
  }
    
  dfs(1);
   
  if(da >= db)
  {
      cout <<"Alice\n";
      return;
  }  
    
  if(db <= da + da)
  {
      cout <<"Alice\n";
      return;
  }
   
  int dis = 0;
    
  while(dep[a] > dep[b])
  {
     dis++;
     a = p[a];
  }
   
  while(dep[a] < dep[b])
  {
     dis++;
     b = p[b];
  } 
    
  while(a != b)
  {
      dis+=2;
      a = p[a];
      b = p[b];
  }
    
  if(dis <= da)
  {
      cout << "Alice\n";
      return;
  }
    
  if(res <= da + da) 
  {
      cout <<"Alice\n";
      return;
  }
    
  cout <<"Bob\n";  
    
    
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}