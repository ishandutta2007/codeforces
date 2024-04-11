#include <bits/stdc++.h>

using namespace std;

const int N = 5010;

int n;
int dp[N][N], cnt[N];
vector <int> a[N];

void dfs(int u, int p) {
  cnt[u] = (a[u].size() == 1);
  for (int i = 1; i <= n; i++) {
    dp[u][i] = 1e9;
  }
  dp[u][0] = 0;
  for (int v : a[u]) {
    if (v == p) {
      continue;
    }
    dfs(v, u);
    for (int i = cnt[u]; i >= 0; i--) {
      for (int j = 0; j <= cnt[v]; j++) {
        dp[u][i + j] = min(dp[u][i + j], dp[u][i] + dp[v][j]);
      }
    }
    cnt[u] += cnt[v];
  }
  for (int i = 0; i <= cnt[u]; i++) {
    dp[u][i] = min(dp[u][i], dp[u][cnt[u] - i] + 1);
  }
}

int main() {
  scanf("%d", &n);
  if (n == 2) {
    cout << 1 << endl;
    return 0;
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    a[u].push_back(v);
    a[v].push_back(u);
  }
  int root = 1;
  while (a[root].size() == 1) {
    root++;
  }
  dfs(root, 0);
  cout << dp[root][cnt[root] / 2] << endl;
  return 0;
}