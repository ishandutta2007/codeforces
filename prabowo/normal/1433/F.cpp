#include <bits/stdc++.h>
using namespace std;

const int N = 70;

int n, m, k;
int a[N][N];

int dp[N][N][N][N];
int f(int x, int y, int sum, int take) {
  if (take < 0) return -1e9;
  if (x == n) return sum == 0 ? 0 : -1e9;
  if (y == m) return f(x+1, 0, sum, m/2);
  if (~dp[x][y][sum][take]) return dp[x][y][sum][take];

  int ret = f(x, y + 1, sum, take);
  ret = max(ret, f(x, y + 1, (sum + a[x][y]) % k, take - 1) + a[x][y]);
  return dp[x][y][sum][take] = ret;
}

int solve() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &a[i][j]);
    }
  }

  memset(dp, -1, sizeof dp);
  printf("%lld\n", f(0, 0, 0, m/2));
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}