#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
 
const int N = 2e5+10;
int st[2*N],val[N];
int A[N];
int n,q,a,b;
vi graph[N];

int dp[N];
int dp2[N];

void dfs(int node,int p=-1)
{
  dp[node] = A[node];
    
  int add = 0;
    
  for(auto x : graph[node])
  if(x!=p) 
  {
      dfs(x,node);
      if(dp[x] > 0) add+=dp[x];
  }
   
  dp[node]+=add;  
}

void dfs2(int node,int par = -1,int add = 0)
{
      dp2[node] = add;
    
      for(auto x : graph[node])
          if(x != par)       
      {
          int send = dp2[node] + dp[node];
          if(dp[x] > 0) send-=dp[x];
          dfs2(x,node,max(0,send));
      }
}
 
void solve()
{
    
cin >> n;
    
f(i,n) cin >> val[i+1];
f(i,n) if(val[i+1] == 0) val[i+1]--;   
    
f(i,n) A[i+1] = val[i+1];    
    
f(i,n-1)
{
  cin >> a >> b;
  graph[a].pb(b);
  graph[b].pb(a);
}
 
 dfs(1);
 dfs2(1);
    
  f(i,n) cout << dp[i+1] + dp2[i+1] << " ";  
}
 
signed main()
{
    fast;
    solve();
}