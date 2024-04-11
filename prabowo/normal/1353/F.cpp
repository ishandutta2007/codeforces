#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const long long INFLL = 4e18;

int n, m;
long long a[N][N];

long long dp[N][N];

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%lld", &a[i][j]);
    }
  }

  long long ans = INFLL;
  for (int ii = 0; ii < n; ++ii) {
    for (int jj = 0; jj < m; ++jj) {
      if (a[ii][jj] - ii - jj > a[0][0]) continue;
      long long tmp = a[0][0];
      a[0][0] = a[ii][jj] - ii - jj;

      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (i == 0 && j == 0) {
            dp[i][j] = tmp - a[0][0];
            continue;
          }

          dp[i][j] = INFLL;
          if (a[0][0] + i + j > a[i][j]) continue;

          long long d = a[i][j] - (a[0][0] + i + j);
          if (i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + d);
          if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + d);
        }
      }

      ans = min(ans, dp[n-1][m-1]);
      a[0][0] = tmp;
    }
  }

  printf("%lld\n", ans);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}