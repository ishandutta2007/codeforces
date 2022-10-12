#include <bits/stdc++.h>
using namespace std;

const int N = 500005;

int n, m;
vector<int> edges[N];

bool vis[N];
int par[N], depth[N];
void dfs(int u) {
  vis[u] = true;
  for (int v: edges[u]) {
    if (vis[v]) continue;
    depth[v] = depth[u] + 1;
    par[v] = u;
    dfs(v);
  }
}

int pairing[N];

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    vis[i] = false;
    pairing[i] = 0;
    edges[i].clear();
  }
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;

    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  dfs(0);

  for (int i = 0; i < n; ++i) {
    if (depth[i] + 1 < (n+1) / 2) continue;
    printf("PATH\n");
    printf("%d\n", depth[i] + 1);
    for (int u = i; u > 0; u = par[u]) {
      printf("%d ", u+1);
    }
    printf("%d\n", 1);
    return 0;
  }

  vector<pair<int, int>> pairs;
  for (int i = 0; i < n; ++i) {
    if (pairing[depth[i]] > 0) {
      pairs.emplace_back(pairing[depth[i]], i+1);
      pairing[depth[i]] = 0;
    } else {
      pairing[depth[i]] = i+1;
    }
  }

  printf("PAIRING\n%d\n", (int) pairs.size());
  for (pair<int, int> p: pairs) {
    printf("%d %d\n", p.first, p.second);
  }
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}