#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, m, maxW;
int w[N], b[N];
int root[N], totW[N], totB[N];
int dp[N][N];
vector <int> a[N];

int getRoot(int u) {
  return root[u] == u ? u : root[u] = getRoot(root[u]);
}

int main() {
  scanf("%d %d %d", &n, &m, &maxW);
  for (int i = 1; i <= n; i++) {
    scanf("%d", w + i);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", b + i);
    root[i] = i;
    totW[i] = w[i];
    totB[i] = b[i];
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    int uu = getRoot(u);
    int vv = getRoot(v);
    if (uu == vv) {
      continue;
    }
    if (uu != vv) {
      root[uu] = vv;
      totW[vv] += totW[uu];
      totB[vv] += totB[uu];
    }
  }
  for (int i = 1; i <= n; i++) {
    a[getRoot(i)].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= maxW; j++) {
      dp[i][j] = dp[i - 1][j];
      if (root[i] != i) {
        continue;
      }
      if (j - totW[i] >= 0) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - totW[i]] + totB[i]);
      }
      for (int u : a[i]) {
        if (j - w[u] >= 0) {
          dp[i][j] = max(dp[i][j], dp[i - 1][j - w[u]] + b[u]);
        }
      }
    }
  }
  int res = 0;
  for (int i = 0; i <= maxW; i++) {
    res = max(res, dp[n][i]);
  }
  cout << res << endl;
  return 0;
}