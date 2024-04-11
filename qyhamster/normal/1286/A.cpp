
#include <bits/stdc++.h>
using namespace std;
int dp[110][110][110][2],a[110];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int odd = (n+1)/2, even = n / 2;
  for(int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }
  memset(dp,0x3f,sizeof(dp));
  dp[0][0][0][0] = dp[0][0][0][1] = 0;
  for(int i = 1; i <= n; i++)
  {
    for(int j = 0; j <= n; j++)
    for(int k = 0; k <= n; k++)
    {
      if(a[i])
      {
        if(a[i]&1)
        {
          if(j) dp[i][j][k][1] = min(dp[i-1][j-1][k][1],dp[i-1][j-1][k][0]+1);
        }
        else
        {
          if(k) dp[i][j][k][0] = min(dp[i-1][j][k-1][0],dp[i-1][j][k-1][1]+1);
        }
        continue;
      }
      if(j) dp[i][j][k][1] = min(dp[i-1][j-1][k][1],dp[i-1][j-1][k][0]+1);
      if(k) dp[i][j][k][0] = min(dp[i-1][j][k-1][0],dp[i-1][j][k-1][1]+1);
    }
  }
  cout << min(dp[n][odd][even][0], dp[n][odd][even][1]) << '\n';
}