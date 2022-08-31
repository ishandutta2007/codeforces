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

const int N = 5e5+10;
vector<pii> g[N];
int val[N];
int n,k,a,b,w;
int dp[N][2]; 

bool cmp(pii & a,pii & b)
{
  return (a.F-a.S) > (b.F-b.S);   
}

void dfs(int node,int par)
{
  vector<pii> dat;  
    
  for(auto x : g[node])
     if(x.S!=par)
     {
      dfs(x.S,node);  
      dat.pb({dp[x.S][0]+x.F,dp[x.S][1]});  
     }
      
  sort(dat.begin(),dat.end(),cmp);
    
  dp[node][0] = dp[node][1] = 0;  
  
  int cn = 0;  
    
  for(auto x : dat)
  { 
      if(x.S >= x.F) dp[node][0]+=x.S,dp[node][1]+=x.S;
      else if(cn < k-1)
      {
       dp[node][1]+=x.F;
       dp[node][0]+=x.F;
       cn++;
      }
      else if(cn == k-1)
      {
       dp[node][1]+=x.F;
       dp[node][0]+=x.S;   
       cn++;
      }
      else dp[node][0]+=x.S,dp[node][1]+=x.S;
  }
}

void solve()
{
    cin >> n >> k;
    
    f(i,n-1)
    {
      cin >> a >> b >> w;
        g[a].pb({w,b});
        g[b].pb({w,a});
    }
    
    dfs(1,0);
    
    cout << max(dp[1][0],dp[1][1]) << "\n";
    
    f(i,n) g[i].clear();
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}