#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1010;
long long a[maxn];
long long dp[1010][1010], sum[1010][1010];
const int MOD = 998244353;
int main()
{
  int n,k;
  cin >> n >> k;
  for(int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a+1, a+n+1);
  int cut = 100000/max(k-1,1);
  long long res = 0, last = 0;
  for(int l = cut; l > 0; l--)
  {
    for(int i = 1; i <= n; i++)
    {
      dp[i][1] = 1;
      sum[i][1] = sum[i-1][1] + 1;
    }
    for(int i = 1; i <= n; i++)
    {
      for(int j = 2; j <= k; j++)
      {
        int t = upper_bound(a+1, a+n+1, a[i] - l) - a - 1;
        dp[i][j] = sum[t][j-1];
        sum[i][j] = sum[i-1][j] + dp[i][j];
        dp[i][j] %= MOD;
        sum[i][j] %= MOD;
      }
    }
    res += (sum[n][k] - last) * l;
    last = sum[n][k];
    res %= MOD;
  }
  res = (res % MOD + MOD) % MOD;
  cout << res << endl;
  return 0;
}