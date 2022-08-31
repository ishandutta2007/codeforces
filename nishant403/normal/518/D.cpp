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

const int N = 2005;
double dp[N][N];

void solve()
{
  int n,t;
  double p;
  cin >> n >> p >> t;
    
  dp[0][0] = 1.000000;
    
  for(int i=1;i<=t;i++)
  {
      dp[i][0] = dp[i-1][0]*(1-p);
      
      for(int j=1;j<n;j++)
          dp[i][j] = dp[i-1][j]*(1-p) + dp[i-1][j-1]*p;      
      
      dp[i][n] = (dp[i-1][n]) + (dp[i-1][n-1]*p);
  }
    
  double res = 0.00000000;
    
  for(int i=0;i<=n;i++) res+=(i*dp[t][i]);
    
  cout << fixed << setprecision(6) << res;
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}