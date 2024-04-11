#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
vector<int> edges[N];

int dp[N][4];
int par[N];
int dfs(int u, int p, int st) {
  if (~dp[u][st]) return dp[u][st];
  par[u] = p;

  vector<int> v0 = {0, 0}, v1 = {0, 0};
  int child = 0;
  for (int v: edges[u]) {
    if (v == p) continue;
    ++child;

    int m0 = max(dfs(v, u, 0), dfs(v, u, 1));
    int m1 = dfs(v, u, 1);

    if (m0 > v0[1]) v0[1] = m0;
    else if (m0 > v0[0]) v0[0] = m0;

    if (m1 > v1[1]) v1[1] = m1;
    else if (m1 > v1[0]) v1[0] = m1;

    if (v0[0] < v0[1]) swap(v0[0], v0[1]);
    if (v1[0] < v1[1]) swap(v1[0], v1[1]);
  }

  if (st == 0) {
    return dp[u][st] = max(v1[0]+1, child-1);
  }

  if (st == 1) {
    return dp[u][st] = max(0, v0[0] + child-1);
  }

  if (u > 0) ++child;

  if (st == 2) {
    return dp[u][st] = max(v1[0] + v1[1] + 1, child-2);
  }

  if (st == 3) {
    return dp[u][st] = max(0, v0[0] + v0[1] + child-2);
  }

  return -1;
}

int solve() {
  scanf("%d", &n);
  int u, v;
  for (int i = 1; i < n; ++i) {
    scanf("%d %d", &u, &v);
    --u, --v;

    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  memset(dp, -1, sizeof dp);

  int ans = max(max(dfs(0, 0, 0), dfs(0, 0, 1)), max(dfs(0, 0, 2), dfs(0, 0, 3)));
  for (int i = 1; i < n; ++i) {
    for (int k = 0; k < 4; ++k) {
      ans = max(ans, dfs(i, par[i], k));
    }
  }

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