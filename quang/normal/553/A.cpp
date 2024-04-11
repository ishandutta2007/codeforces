#include <bits/stdc++.h>

using namespace std;

const int N = 1010, MOD = 1000000007;

int k, n;
int a[N];
int dp[N][N], c[N][N];

int C(int x, int y) {
  if (x < 0 || x > y) {
    return 0;
  }
  return c[x][y];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> k;
  for (int i = 1; i <= k; i++) {
    cin >> a[i];
    n += a[i];
  }
  for (int j = 0; j <= 1000; j++) {
    for (int i = 0; i <= j; i++) {
      if (i == 0 || i == j) {
        c[i][j] = 1;
      } else {
        c[i][j] = (1ll * c[i - 1][j - 1] + c[i][j - 1]) % MOD;
      }
    }
  }
  dp[0][0] = 1;
  for (int j = 1; j <= n; j++) {
    for (int i = 0; i <= k; i++) {
      if (i == 0) {
        dp[i][j] = (j <= n - k);
      } else {
        dp[i][j] = dp[i][j - 1];
        if (j >= a[i]) {
          dp[i][j] = (1ll * dp[i - 1][j - a[i]] * C(a[i] - 1, j - 1) + dp[i][j]) % MOD;
        }
      }
    }
  }
  cout << dp[k][n] << endl;
  return 0;
}