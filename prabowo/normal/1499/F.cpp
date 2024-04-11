#include <bits/stdc++.h>
using namespace std;
 
const int N = 5005;
const int MOD = 998244353;

int n, k;
vector<int> edges[N];

int sz[N];
int dp[N][N];
int ndp[N];
void dfs(int u, int p) {
  sz[u] = 1;
  dp[u][0] = 1;
  for (int v : edges[u]) {
    if (v == p) continue;
    dfs(v, u);

    for (int d1 = 0; d1 <= min(k, sz[u]); ++d1) {
      for (int d2 = 0; d2 <= min(k, sz[v]); ++d2) {
        if (d1 + d2 + 1 <= k) {
          // dont cut
          ndp[max(d1, d2 + 1)] = (ndp[max(d1, d2 + 1)] + 1LL * dp[u][d1] * dp[v][d2]) % MOD;
        }

        // cut
        ndp[d1] = (ndp[d1] + 1LL * dp[u][d1] * dp[v][d2]) % MOD;
      }
    }

    sz[u] += sz[v];
    for (int i = 0; i <= min(k, sz[u]); ++i) {
      dp[u][i] = ndp[i];
      ndp[i] = 0;
    }
  }
}

int solve() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;

    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  dfs(0, 0);

  int ans = 0;
  for (int i = 0; i <= k; ++i) ans = (ans + dp[0][i]) % MOD;

  printf("%d\n", ans);
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