#include <bits/stdc++.h>
using namespace std;
 
const int LN = 19;
const int N = 300005;

int n, m;
vector<int> edges[N];
pair<int, int> e[N];

vector<int> paths[N];
vector<int> lcas[N];

int par[LN][N];
int depths[N];
void dfs(int u, int p) {
  par[0][u] = p;
  for (int v : edges[u]) {
    if (v == p) continue;
    depths[v] = depths[u] + 1;
    dfs(v, u);
  }
}

void initLca() {
  for (int i = 1; i < LN; ++i) {
    for (int u = 0; u < n; ++u) {
      par[i][u] = par[i - 1][par[i - 1][u]];
    }
  }
}

vector<int> lca(int u, int v) {
  if (u == v) return {u};
  if (depths[u] < depths[v]) swap(u, v);
  while (depths[u] - 1 > depths[v]) u = par[__builtin_ctz(depths[u] - 1 - depths[v])][u];
  if (par[0][u] == v) return {v, u};
  if (depths[u] != depths[v]) u = par[0][u];
  for (int i = LN - 1; i >= 0; --i) {
    if (par[i][u] == par[i][v]) continue;
    u = par[i][u];
    v = par[i][v];
  }
  return {par[0][u], u, v};
}

int ups[N];
long long dfsAns(int u, int p) {
  long long ret = 0;
  for (int v : edges[u]) {
    if (v == p) continue;
    ret += dfsAns(v, u);
    ups[u] += ups[v];
  }
  ups[u] -= paths[u].size() * 2;

  map<int, int> oneChild;
  map<pair<int, int>, int> twoChildren;
  int cnt = 0;
  for (int path : paths[u]) {
    ret += cnt;
    if (lcas[path].size() > 1) {
      ret -= oneChild[lcas[path][1]];
      if (lcas[path].size() > 2) {
        pair<int, int> twos = {lcas[path][1], lcas[path][2]};
        ret -= oneChild[twos.second];
        ret += twoChildren[twos];
        ++twoChildren[twos];
        ++oneChild[twos.second];
      }
      ++oneChild[lcas[path][1]];
    }
    ++cnt;
  }

  ret += 1LL * ups[u] * paths[u].size();
  for (int path : paths[u]) {
    for (int i = 1; i < lcas[path].size(); ++i) {
      ret -= ups[lcas[path][i]] - oneChild[lcas[path][i]];
    }
  }
  return ret;
}

int solve() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;

    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", &e[i].first, &e[i].second);
    --e[i].first, --e[i].second;
  }

  dfs(0, 0);
  initLca();

  for (int i = 0; i < m; ++i) {
    int u, v;
    tie(u, v) = e[i];

    lcas[i] = lca(u, v);
    if (lcas[i].size() == 3 && lcas[i][1] > lcas[i][2]) swap(lcas[i][1], lcas[i][2]);
    paths[lcas[i][0]].push_back(i);
    ++ups[u]; ++ups[v];
  }

  printf("%lld\n", dfsAns(0, 0));
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