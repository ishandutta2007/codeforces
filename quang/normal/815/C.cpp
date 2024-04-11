#include <bits/stdc++.h>

using namespace std;

const int N = 5010, INF = 1e9 + 10;

int n, b;
int c[N], d[N];
vector <int> a[N];
int dp[2][N][N];
int sz[N];

void dfs(int u) {
  for (int i = 0; i <= n; i++) {
    dp[0][u][i] = dp[1][u][i] = INF;
  }
  dp[0][u][0] = 0;
  dp[0][u][1] = c[u];
  dp[1][u][1] = c[u] - d[u];
  sz[u] = 1;
  for (int v : a[u]) {
    dfs(v);
    for (int i = sz[u]; i >= 0; i--) {
      for (int j = 0; j <= sz[v]; j++) {
        dp[0][u][i + j] = min(dp[0][u][i + j], dp[0][u][i] + dp[0][v][j]);
        dp[1][u][i + j] = min(dp[1][u][i + j], dp[1][u][i] + min(dp[0][v][j], dp[1][v][j]));
      }
    }
    sz[u] += sz[v];
  }
}

int main() {
  scanf("%d %d", &n, &b);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", c + i, d + i);
    if (i > 1) {
      int u;
      scanf("%d", &u);
      a[u].push_back(i);
    }
  }
  dfs(1);
  int res = 0;
  for (int i = 1; i <= n; i++) {
    if (dp[0][1][i] <= b || dp[1][1][i] <= b) {
      res = max(res, i);
    }
  }
  cout << res << endl;
  return 0;
}