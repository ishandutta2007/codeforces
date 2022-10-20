#include <bits/stdc++.h>

using namespace std;

const int N = 110, K = 30, MOD = 1000000007;

int n, k;
vector <int> a[N];
int dp[N][K][K];
int foo[K][K];

inline int mul(int u, int v) {
  return (long long)u * v % MOD;
}

inline int add(int u, int v) {
  u += v;
  if (u >= MOD) {
    u -= MOD;
  }
  return u;
}

void join(int u, int v) {
  memset(foo, 0, sizeof foo);
  for (int i = 0; i <= k + 1; i++) {
    for (int j = 0; j <= k + 1; j++) {
      for (int ii = 0; ii <= k + 1; ii++) {
        for (int jj = 0; jj <= k + 1; jj++) {
          int nxtMax = 0;
          if (j + ii - 1 > k) {
            nxtMax = max(nxtMax, j);
          }
          if (jj + i - 1 > k) {
            nxtMax = max(nxtMax, jj + 1);
          }
          int nxtMin = min(i, ii + 1);
          nxtMax = min(nxtMax, k + 1);
          nxtMin = min(nxtMin, k + 1);
          foo[nxtMin][nxtMax] = add(foo[nxtMin][nxtMax], mul(dp[u][i][j], dp[v][ii][jj]));
        }
      }
    }
  }
  for (int i = 0; i <= k + 1; i++) {
    for (int j = 0; j <= k + 1; j++) {
      dp[u][i][j] = foo[i][j];
    }
  }
}

void dfs(int u, int p) {
  for (int v : a[u]) {
    if (v == p) {
      continue;
    }
    dfs(v, u);
  }
  dp[u][k + 1][1] = dp[u][1][0] = 1;
  for (int v : a[u]) {
    if (v == p) {
      continue;
    }
    join(u, v);
  }
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    a[u].push_back(v);
    a[v].push_back(u);
  }
  dfs(1, 0);
  int res = 0;
  for (int i = 0; i <= k + 1; i++) {
    res = add(res, dp[1][i][0]);
  }
  cout << res << endl;
  return 0;
}