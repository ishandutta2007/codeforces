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
#define all(x) x.begin(),x.end()

const int MOD = 1e9+7;
const int N = 2e5 + 10;

int n;
int a[N];
vi g[N];

int col[N];
int dp[N][2];

int res = 0;

void dfs(int node,int par = -1,int cc = 0)
{
    col[node] = cc;
    
    dp[node][0] = 1;
    
    for(auto x : g[node])
        if(x != par)
    {
        dfs(x,node,cc^1);
     
        dp[node][1] += dp[x][0];
        dp[node][0] += dp[x][1];
    }
}

void dfs2(int node,int par = -1)
{
    int temp = 0;
    
    for(auto x : g[node])
    {
        if(x == par) continue;
        
        dfs2(x,node);

        temp += dp[x][1]*(n - dp[x][0] - dp[x][1]);
        temp -= dp[x][0]*(n - dp[x][0] - dp[x][1]);
        
        temp %= MOD;
        if(temp < 0) temp += MOD;
    }
    
    if(col[1] == col[node])
    {
        temp += (dp[1][0] - dp[node][0])*(dp[node][0] + dp[node][1]);
        temp -= (dp[1][1] - dp[node][1])*(dp[node][0] + dp[node][1]);
    }
    else
    {
        temp += (dp[1][1] - dp[node][0])*(dp[node][0] + dp[node][1]);
        temp -= (dp[1][0] - dp[node][1])*(dp[node][0] + dp[node][1]);
    }
    
    //starting from this node
    temp += n;
    
    temp %= MOD;
    if(temp < 0) temp += MOD;
    
    temp*=a[node];
    temp %= MOD;
    if(temp < 0) temp += MOD;
    
    res += temp;
    res %= MOD;
}

void solve()
{
   cin >> n;
    
   f(i,n) cin >> a[i+1];
    
   int u,v;
    
   f(i,n-1)
   {
       cin >> u >> v;
       g[u].pb(v);
       g[v].pb(u);
   }
    
   dfs(1);
    
   //only considered paths of length > 1 
   dfs2(1);
    
   cout << res;
}

signed main()
{
    fast;
    solve();
}