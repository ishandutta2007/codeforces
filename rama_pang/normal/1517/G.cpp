#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint inf = 1e18;

class Flow {
 public:
  int n;
  struct Edge {
    int to;
    lint cap;
    Edge(int to, lint cap) : to(to), cap(cap) {}
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
  lint dfs(int u, int t, lint f) {
    if (u == t) {
      return f;
    }
    lint r = f;
    for (int &i = cur[u]; i < int(g[u].size()); i++) {
      int j = g[u][i];
      auto [v, c] = e[j];
      if (c > 0 && h[v] == h[u] + 1) {
        lint a = dfs(v, t, min(r, c));
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
  void add_edge(int u, int v, lint c) {
    g[u].emplace_back(e.size());
    e.emplace_back(v, c);
    g[v].emplace_back(e.size());
    e.emplace_back(u, 0);
  }
  lint max_flow(int s, int t) {
    lint ans = 0;
    while (bfs(s, t)) {
      cur.assign(n, 0);
      ans += dfs(s, t, inf);
    }
    return ans;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  map<pair<int, int>, int> id;
  vector<int> X(N), Y(N), W(N);

  lint ans = 0;
  for (int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i] >> W[i];
    id[{X[i], Y[i]}] = i;
    ans += W[i];
  }

  Flow F(2 * N + 2);
  const int S = 2 * N, T = S + 1;

  for (int i = 0; i < N; i++) {
    F.add_edge(i, i + N, W[i]);
    if (X[i] % 2 != 0 && Y[i] % 2 == 0) {
      F.add_edge(S, i, inf);
      for (int dx : {-1, 1}) {
        if (id.count({X[i] + dx, Y[i]})) {
          F.add_edge(i + N, id[{X[i] + dx, Y[i]}], inf);
        }
      }
    } else if (X[i] % 2 == 0 && Y[i] % 2 == 0) {
      for (int dy : {-1, 1}) {
        if (id.count({X[i], Y[i] + dy})) {
          F.add_edge(i + N, id[{X[i], Y[i] + dy}], inf);
        }
      }
    } else if (X[i] % 2 == 0 && Y[i] % 2 != 0) {
      for (int dx : {-1, 1}) {
        if (id.count({X[i] + dx, Y[i]})) {
          F.add_edge(i + N, id[{X[i] + dx, Y[i]}], inf);
        }
      }
    } else {
      F.add_edge(i + N, T, inf);
    }
  }

  ans -= F.max_flow(S, T);
  cout << ans << '\n';
  return 0;
}