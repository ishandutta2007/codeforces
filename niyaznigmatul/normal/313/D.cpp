#include <cstdio>

const long long INF = 1LL << 60;

long long dp[333][333], cost[333][333];

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++) 
    for (int j = 0; j < n; j++) cost[i][j] = INF;
  for (int i = 0; i < m; i++) {
    int l, r, c;
    scanf("%d%d%d", &l, &r, &c);
    --l;
    --r;
    if (cost[l][r] > c) cost[l][r] = c;
  }
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++) dp[i][j] = INF;
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    long long best = INF;
    for (int c = 0; c <= n; c++) if (dp[i][c] > dp[i - 1][c]) dp[i][c] = dp[i - 1][c];
    for (int j = 0; j < i; j++) {
      if (best > cost[j][i - 1]) best = cost[j][i - 1];
      if (best == INF) continue;
      int nc = i - j;
      for (int c = 0; c + nc <= n; c++) {
        long long val = dp[j][c];
        if (val == INF) continue;
        if (val + best < dp[i][c + nc]) dp[i][c + nc] = val + best;
      }
    }
    for (int c = 0; c <= n; c++) {
//      if (dp[i][c] != INF) printf("%d %d %I64d\n", i, c, dp[i][c]);
    }
  }
  printf("%I64d\n", dp[n][k] == INF ? -1 : dp[n][k]);
}