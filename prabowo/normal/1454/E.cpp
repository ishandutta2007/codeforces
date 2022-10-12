#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
vector<int> edges[N];

vector<int> roots;
bool rs[N];
int par[N];
bool vis[N];
void dfs(int u, int p) {
  vis[u] = true;
  par[u] = p;
  for (int v: edges[u]) {
    if (v == p) continue;
    if (vis[v]) {
      if (roots.size() > 0) continue;
      // cerr << u << " " << v << endl;
      for (int cur = u; cur != v; cur = par[cur]) {
        roots.push_back(cur);
        rs[cur] = true;
      }
      roots.push_back(v);
      rs[v] = true;
    } else {
      dfs(v, u);
    }
  }
}

int dfs2(int u, int p) {
  int ret = 1;
  for (int v: edges[u]) {
    if (v == p) continue;
    if (rs[v]) continue;
    ret += dfs2(v, u);
  }
  return ret;
}

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    rs[i] = false;
    edges[i].clear();
    vis[i] = false;
    par[i] = -1;
  }
  roots.clear();

  for (int i = 0; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  long long ans = 1LL * n * (n - 1);

  dfs(0, 0);

  for (int r: roots) {
    int sz = dfs2(r, r);
    ans -= 1LL * sz * (sz - 1) / 2;
  }
  printf("%lld\n", ans);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    solve();
  }
  return 0;
}