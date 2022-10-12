#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, k;
int x, y;
vector<int> adj[N];

bool things[N];

int sum[N];
bool towardsY[N];

void dfs(int u, int p) {
  towardsY[u] = (u == y);
  for (int v : adj[u]) {
    if (v == p) continue;
    dfs(v, u);
    towardsY[u] |= towardsY[v];
    things[u] |= things[v];
    sum[u] += sum[v];
  }

  if (things[u]) {
    ++sum[u];
  }
}

int dfs2(int u, int p) {
  int ret = 0;
  for (int v : adj[u]) {
    if (v == p) continue;
    if (!towardsY[v]) {
      ret += sum[v] * 2;
    } else {
      ret += 1 + dfs2(v, u);
    }
  }

  // cerr << u + 1 << " " << ret << " " << sum[u] << endl;
  return ret;
}

int solve() {
  scanf("%d %d", &n, &k);

  for (int i = 0; i < n; ++i) {
    things[i] = false;
    sum[i] = 0;
    adj[i].clear();
    towardsY[i] = false;
  }

  scanf("%d %d", &x, &y);
  --x, --y;

  for (int i = 0; i < k; ++i) {
    int a;
    scanf("%d", &a);
    things[--a] = true;
  }

  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(x, x);

  int ans = dfs2(x, x);
  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc + 1);
    solve();
  }
}