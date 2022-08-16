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

const int N = 1003;
const int inf = 1e8;

int dp[N][N][2];
int cn[N];

void solve()
{
  int n,m,x,y;
    cin >> n >> m >> x >> y;
   
  string s;  
      
  for(int i=1;i<=n;i++)
  {
      cin >> s;
      for(int j=0;j<m;j++)
          if(s[j] == '#') cn[j+1]++;
  }
    
  for(int i=2;i<=m;i++)
      for(int j=0;j<=m;j++)
        for(int k=0;k<=1;k++)
            dp[i][j][k] = inf;
         
  dp[1][1][0] = cn[1];
  dp[1][1][1] = n - cn[1];
      
  for(int i=2;i<=m;i++)
  {
    for(int j=x;j<=min(i-1,y);j++)
    {
      dp[i][1][0] = min(dp[i][1][0],dp[i-1][j][1]+cn[i]);        
      dp[i][1][1] = min(dp[i][1][1],dp[i-1][j][0]+(n-cn[i]));
    } 
      
    for(int j=2;j<=min(i,y);j++)  
    {
      dp[i][j][0] = dp[i-1][j-1][0] + (cn[i]);
      dp[i][j][1] = dp[i-1][j-1][1] + (n-cn[i]);    
    }      
  }
     
  int ans = inf;
    
  for(int i=x;i<=min(m,y);i++)
  {
      ans = min(ans,dp[m][i][0]); 
      ans = min(ans,dp[m][i][1]);   
  }
    
  cout << ans;  
}

signed main()
{
    fast;
    solve();
}