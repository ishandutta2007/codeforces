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

const int M = 1e9+7;

int pw(int a,int b)
{
    int res = 1;
    
    while(b)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}

const int N = 1e3+20;
int dp[N][11];

void solve()
{
  int n,m;
  cin >> n >> m;
    
  dp[0][0] = 1;
    
  for(int i=1;i<=n+m;i++)
  {
      dp[i][0] = 1;
      for(int j=1;j<=m;j++)
          dp[i][j] = (dp[i-1][j] + dp[i-1][j-1])%M;
  }
          
  int res = 0;  
    
  for(int i=1;i<=n;i++)
  {
      res+=(((dp[i+m-1][m]-dp[i+m-2][m]+M)%M)*dp[n-i+m][m])%M;
      res%=M;
  } 
    
  cout << res;
    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}