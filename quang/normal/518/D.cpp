#include <bits/stdc++.h>

#define Task "D"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 2020;

int n, t;
double d;
long double dp[N][N];

int main() {
  ios_base::sync_with_stdio(0);
 // fi, fo;
  cin >> n >> d >> t;
  dp[0][0] = 1.0;
  for (int i = 1; i <= t; i++) {
    for (int j = 0; j <= min(i, n); j++) {
      if (j == 0) {
        dp[i][j] = dp[i - 1][j] * ((long double)1.0 - d);
      }
      if (j == n) {
        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] * d;
      }
      if (j && j < n) {
        dp[i][j] = dp[i - 1][j] * ((long double)1.0 - d);
        dp[i][j] += dp[i - 1][j - 1] * d;
      }
    }
  }
  long double res = 0.0;
  for (int i = 1; i <= n; i++) {
    res += dp[t][i] * i;
  }
  printf("%0.15f", (double)res);
  return 0;
}