#include <bits/stdc++.h>

using namespace std;

const int N = 5010;

int n, t;
double p[N];
int a[N];
double dp[2][N];
double res = 0.0;

int main() {
 // freopen("B.inp", "r" ,stdin);
  scanf("%d %d", &n, &t);
  for (int i = 1; i <= n; i++) {
    scanf("%lf %d", p + i, a + i);
    p[i] /= 100;
  }
  int cur = 0;
  dp[cur][0] = 1.0;
  for(int i = 1; i <= t; i++) {
    dp[cur][i] = 0.0;
  }
  for (int i = 1; i <= n; i++) {
    int next = cur ^ 1;
    if (a[i] > 1) {
      double sum = 0, q = 1.0;
      for (int j = 1; j < a[i]; j++) {
        q *= (1.0 - p[i]);
      }
      for (int j = 0; j <= t; j++) {
        if (j >= a[i]) {
          sum -= dp[cur][j - a[i]] * p[i] * q;
        }
        dp[next][j] = sum;
        if (j >= a[i]) {
          dp[next][j] += dp[cur][j - a[i]] * q;
        }
        sum = sum * (1.0 - p[i]) + dp[cur][j] * p[i];
      }
    } else {
      for (int j = 1; j <= t; j++) {
        dp[next][j] = dp[cur][j - 1];
      }
      dp[next][0] = 0;
    }
    if (i < n) {
      double foo = 1.0;
      for (int j = 0; j < a[i + 1]; j++) {
        res += foo * dp[next][t - j] * i;
        foo *= (1.0 - p[i + 1]);
      }
    } else {
      for (int j = 0; j <= t; j++) {
        res += 1.0 * i * dp[next][j];
      }
    }
    cur ^= 1;
  }
  printf("%0.10f\n", res);
  return 0;
}