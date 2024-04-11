#include <bits/stdc++.h>
using namespace std;

template<class flow_t>
class Flow {
 public:
  int n;
  struct Edge {
    int to;
    flow_t cap;
    Edge(int to, flow_t cap) : to(to), cap(cap) {}
  };
  vector<Edge> e;
  vector<vector<int>> g;
  vector<int> cur, h;
  Flow(int n) : n(n), g(n) {}
  bool bfs(int s, int t) {
    h.assign(n, -1);
    queue<int> q;
    h[s] = 0;
    q.emplace(s);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto i : g[u]) {
        auto [v, c] = e[i];
        if (c > 0 && h[v] == -1) {
          h[v] = h[u] + 1;
          q.emplace(v);
          if (v == t) {
            return true;
          }
        }
      }
    }
    return false;
  }
  flow_t dfs(int u, int t, flow_t f) {
    if (u == t) {
      return f;
    }
    flow_t r = f;
    for (int &i = cur[u]; i < int(g[u].size()); i++) {
      int j = g[u][i];
      auto [v, c] = e[j];
      if (c > 0 && h[v] == h[u] + 1) {
        flow_t a = dfs(v, t, min(r, c));
        e[j].cap -= a;
        e[j ^ 1].cap += a;
        r -= a;
        if (r == 0) {
          return f;
        }
      }
    }
    return f - r;
  }
  void add_edge(int u, int v, flow_t c) {
    g[u].emplace_back(e.size());
    e.emplace_back(v, c);
    g[v].emplace_back(e.size());
    e.emplace_back(u, 0);
  }
  flow_t max_flow(int s, int t) {
    flow_t ans = 0;
    while (bfs(s, t)) {
      cur.assign(n, 0);
      ans += dfs(s, t, numeric_limits<flow_t>::max());
    }
    return ans;
  }
  vector<pair<int, int>> min_cut(int s, int t) {
    assert(!bfs(s, t));
    vector<pair<int, int>> cut;
    for (int i = 0; i < n; i++) {
      if (h[i] != -1) {
        for (auto j : g[i]) {
          auto [v, c] = e[j];
          if (h[v] == -1) {
            cut.emplace_back(i, v);
          }
        }
      }
    }
    return cut;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, m;
  cin >> n >> m;
  vector<int> c(n);
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    c[u] += w;
    c[v] -= w;
    g[u].emplace_back(v);
  }
  Flow<long long> f(n * (n + 1) + 2);
  int source = n * (n + 1);
  int sink = n * (n + 1) + 1;
  const auto get = [&](int i, int k) {
    return i * (n + 1) + k;
  };
  const long long MAX = 1e9;
  const long long INF = 1e18;
  for (int i = 0; i < n; i++) {
    f.add_edge(source, get(i, 0), INF);
    for (int j = 0; j < n; j++) {
      f.add_edge(get(i, j), get(i, j + 1), MAX + j * c[i]);
    }
    f.add_edge(get(i, n), sink, INF);
  }
  for (int i = 0; i < n; i++) {
    for (auto j : g[i]) {
      for (int k = 0; k < n; k++) {
        f.add_edge(get(j, k), get(i, k + 1), INF);
      }
    }
  }
  long long ans = f.max_flow(source, sink) - 1ll * MAX * n;
  auto cut = f.min_cut(source, sink);
  vector<int> answer(n, -1);
  for (auto [u, v] : cut) {
    if (u + 1 == v) {
      int id = u / (n + 1);
      int ai = u % (n + 1);
      answer[id] = ai;
    }
  }
  cerr << "score: " << ans << '\n';
  for (int i = 0; i < n; i++) {
    cout << answer[i] << " \n"[i + 1 == n];
  }
  return 0;
}