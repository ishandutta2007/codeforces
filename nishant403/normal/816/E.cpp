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

const int N = 5006;
const int inf = 1e14;

vector<int> g[N];
int n,b;
int val[N];
int dis[N];
int dp[N][N]; //dp[i][j] = cost for j goods at subtree of node i
int dp2[N][N]; //dp2[i][j] = cost for j goods at subtree of node i and val[i] is considered here
int sz[N];

void dfs(int node,int par = -1)
{
    sz[node] = 1;
    
    for(int i=0;i<=n;i++) dp[node][i] = dp2[node][i] = inf;
    
    dp[node][0] = 0;
    dp[node][1] = val[node];
    dp2[node][1] = val[node] - dis[node];
    
    if(node == 1) dp[node][1] -= dis[node]; 
    
    for(auto x : g[node])
    {
        if(x == par) continue;
     
        dfs(x,node);
     
        for(int i=sz[node];i>=0;i--)
            for(int j=0;j<=sz[x];j++)
        {  
             dp[node][i+j] = min(dp[node][i+j],dp[node][i] + dp[x][j]);      
             dp2[node][i+j] = min(dp2[node][i+j],dp2[node][i] + min(dp[x][j],dp2[x][j]));
        }   
    
        sz[node]+=sz[x]; 
    }
}

signed main()
{
    fast;
    
    cin >> n >> b;
    
    int x;
    
    for(int i=1;i<=n;i++)
    {
        cin >> val[i] >> dis[i];
        
        if(i > 1)
        {
            cin >> x;
            g[x].pb(i);
        }
    }
    
    dfs(1);
    
    int res = 0;
    
    for(int i=1;i<=n;i++)
           if(dp[1][i] <= b || dp2[1][i] <= b) res = max(res,i);
        
    cout << res;
}