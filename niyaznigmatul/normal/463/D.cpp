#include <cstdio>

int const N = 1234;

int dp[N];
int a[N];
int c[N][N];
int n;
int dfs(int v) {
  if (dp[v] >= 0) return dp[v];
  dp[v] = 1;
  for (int i = 0; i < n; i++) {
    if (c[v][i]) if (dp[v] < dfs(i) + 1) dp[v] = dfs(i) + 1;
  }
  return dp[v];
}

int main() {
  int k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", a + j);
      --a[j];
    }
    for (int j = 0; j < n; j++) {
      for (int e = j + 1; e < n; e++) {
        c[a[j]][a[e]]++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) c[i][j] /= k;
  }
  for (int i = 0; i < n; i++) dp[i] = -1;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int cur = dfs(i);
    if (ans < cur) ans = cur;
  }
  printf("%d\n", ans);
}