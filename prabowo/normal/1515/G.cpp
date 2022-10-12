#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m;

vector<pair<int, int>> edges[N];
vector<pair<int, int>> redges[N];

int scc[N];
long long g[N];

long long gcd(long long x, long long y) {
  while (y) {
    long long t = x;
    x = y;
    y = t % y;
  }
  return x;
}

long long dist[N];
void dfs(int u, vector<pair<int, int>> edges[], vector<int> &order) {
  for (pair<int, int> p : edges[u]) {
    int v, w;
    tie(v, w) = p;
    if (dist[v] != -1) continue;
    dist[v] = dist[u] + w;
    dfs(v, edges, order);
  }
  order.push_back(u);
}

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    --u, --v;
    edges[u].emplace_back(v, w);
    redges[v].emplace_back(u, w);
  }

  memset(dist, -1, sizeof dist);

  vector<int> order;
  for (int u = 0; u < n; ++u) {
    if (dist[u] >= 0) continue;
    dist[u] = 0;
    dfs(u, edges, order);
  }
  reverse(order.begin(), order.end());

  memset(dist, -1, sizeof dist);
  for (int u : order) {
    if (dist[u] >= 0) continue;
    vector<int> comp;
    dist[u] = 0;
    dfs(u, redges, comp);
    for (int v : comp) scc[v] = u;
  }

  for (int u = 0; u < n; ++u) {
    for (pair<int, int> p : redges[u]) {
      int v = p.first, w = p.second;
      if (scc[u] != scc[v]) continue;
      g[scc[u]] = gcd(g[scc[u]], abs(dist[u] + w - dist[v]));
    }
  }

  int q;
  scanf("%d", &q);
  while (q--) {
    int u, s, t;
    scanf("%d %d %d", &u, &s, &t);
    --u;

    if (s % gcd(g[scc[u]], t) == 0) printf("YES\n");
    else printf("NO\n");
  }

  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc + 1);
    solve();
  }
  return 0;
}