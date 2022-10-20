#include <bits/stdc++.h>

using namespace std;

int x, k;
long double dp[2][300][2][300];
long double p;

void pre(int u) {
  if (u < (1 << 8)) {
    dp[0][0][0][u] = 1;
  } else {
    int v = u >> 8;
    int e = u - (v << 8);
    int last = v & 1;
    int d = 1;
    while (((v >> d) & 1) == last) {
      d++;
    }
    dp[0][d][last][e] = 1;
  }
}

int main() {
  cin >> x >> k >> p;
  int cur, next;
  p = 1.0 * p / 100;
  cur = 0;
  pre(x);
  for (int it = 1; it <= k; it++) {
    next = cur ^ 1;
    for (int i = 0; i < 300; i++) {
      for (int j = 0; j < 2; j++) {
        for (int mask = 0; mask < (1 << 8); mask++) {
          dp[next][i][j][mask] = 0;
        }
      }
    }
    for (int i = 0; i < 300; i++) {
      for (int j = 0; j < 2; j++) {
        for (int mask = 0; mask < (1 << 8); mask++) {
          if (abs(dp[cur][i][j][mask]) < 0.0000000000000001) {
            continue;
          }
          //multiple
          int f = (mask >> 7) & 1;
          int e = (mask * 2) % (1 << 8);
          if (i == 0) {
            dp[next][f][f][e] += p * dp[cur][i][j][mask];
          } else {
            if (f == j) {
              dp[next][i + 1][f][e] += p * dp[cur][i][j][mask];
            } else {
              dp[next][1][f][e] += p * dp[cur][i][j][mask];
            }
          }
          //add
          if (mask + 1 == (1 << 8)) {
            if (j == 0) {
              dp[next][1][1][0] += (1.0 - p) * dp[cur][i][j][mask];
            } else {
              dp[next][i][0][0] += (1.0 - p) * dp[cur][i][j][mask];
            }
          } else {
            dp[next][i][j][mask + 1] += (1.0 - p) * dp[cur][i][j][mask];
          }
        }
      }
    }
    cur = next;
  }
  long double res = 0;
  for (int i = 0; i < 300; i++) {
    for (int j = 0; j < 2; j++) {
      for (int mask = 0; mask < (1 << 8); mask++) {
        if (mask == 0) {
          if (j == 0) {
            res += dp[cur][i][j][mask] * (8 + i);
          } else {
            res += dp[cur][i][j][mask] * 8;
          }
          continue;
        }
        int x = mask & (-mask);
        int f = log2(x);
        res += dp[cur][i][j][mask] * f;
      }
    }
  }
  printf("%0.17f", (double)res);
  return 0;
}