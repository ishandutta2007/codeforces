#include <bits/stdc++.h>
using namespace std;
const int maxn = 2200;
long long dp[maxn][maxn];
int a[maxn],c[maxn],l[maxn*2];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  for(int i = 0; i < maxn; i++) for(int j = 1; j < maxn; j++) dp[i][j] = -1e18;
  int n,m;
  cin >> n >> m;
  for(int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for(int i = 0; i < n; i++) cin >> c[i];
  for(int i = 0; i < n+m; i++) cin >> l[i];
  long long ans = 0;
  for(int i = n-1; i >= 0; i--)
  {
    int x = a[i];
    for(int j = maxn-1; j > 0; j--)
    {
      int lb = j-1,num = 0,cnt = x;
      while(lb&1)
      {
        cnt++;
        num += l[cnt-1];
        lb /= 2;
      }
      dp[x][j] = max(dp[x][j],dp[x][j-1] + l[x-1] - c[i] + num);
      ans = max(ans, dp[x][j]);
    }
    for(int k = 1; (1<<k) < maxn; k++)
    {
      for(int j = 0; j <= (maxn-1)/(1<<k); j++)
      {
        dp[x+k][j] = max(dp[x+k][j], max(dp[x+k-1][j*2],dp[x+k-1][j*2+1]));
        ans = max(ans,dp[x+k][j]);
      }
    }
    for(int j = 1; j < maxn; j++) dp[j][0] = max(dp[j][0],max(dp[j-1][1],dp[j-1][0]));
  }
  cout << ans << endl;
  return 0;
}