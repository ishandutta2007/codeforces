#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, m;
int a[N];
double dp[N][N];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (a[i] > a[j]) {
        dp[i][j] = 1.0;
      }
    }
  }
  while (m--) {
    int u, v;
    scanf("%d %d", &u, &v);
    if (u > v) {
      swap(u, v);
    }
    for (int i = 1; i < u; i++) {
      double foo = (dp[i][u] + dp[i][v]) * 0.5;
      dp[i][u] = dp[i][v] = foo;
    }
    for (int i = v + 1; i <= n; i++) {
      double foo = (dp[u][i] + dp[v][i]) * 0.5;
      dp[u][i] = dp[v][i] = foo;
    }
    for (int i = u + 1; i < v; i++) {
      double foo1 = 0.5 * (dp[u][i] + 1.0 - dp[i][v]);
      double foo2 = 0.5 * (dp[i][v] + 1.0 - dp[u][i]);
      dp[u][i] = foo1;
      dp[i][v] = foo2;
    }
    dp[u][v] = 0.5;
  }
  double res = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      res += dp[i][j];
    }
  }
  printf("%0.17f", res);
  return 0;
}