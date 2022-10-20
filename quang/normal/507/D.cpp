#include <bits/stdc++.h>

#define Task "B"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 1010;

int n, k, m;
long long dp[N][110][2];
long long mu[N], ans = 0;

int main() {
  ios_base::sync_with_stdio(0);
  //fi, fo;
  cin >> n >> k >> m;
  mu[0] = 1;
  for (int i = 1; i <= n; i++) mu[i] = (mu[i - 1] * 10) % k;
  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < k; j++)
      for (int ok = 0; ok <= 1; ok++)
        for (int d = 0; d <= 9; d++) {
          int flag = ok;
          int z = (j + (d * mu[i]) % k) % k;
          if (!z && d)
            flag = 1;
          dp[i + 1][z][flag] = (dp[i + 1][z][flag] + dp[i][j][ok]) % m;
          if (flag && d && i == n - 1)
            ans = (ans + dp[i][j][ok]) % m;
        }
  cout << ans;
  return 0;
}