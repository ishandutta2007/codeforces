#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

class Flow {
 public:
  int n;
  struct Edge {
    int to, cap;
    Edge(int to, int cap) : to(to), cap(cap) {}
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
  int dfs(int u, int t, int f) {
    if (u == t) {
      return f;
    }
    int r = f;
    for (int &i = cur[u]; i < int(g[u].size()); i++) {
      int j = g[u][i];
      auto [v, c] = e[j];
      if (c > 0 && h[v] == h[u] + 1) {
        int a = dfs(v, t, min(r, c));
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
  void add_edge(int u, int v, int c) {
    g[u].emplace_back(e.size());
    e.emplace_back(v, c);
    g[v].emplace_back(e.size());
    e.emplace_back(u, 0);
  }
  int max_flow(int s, int t) {
    int ans = 0;
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
  
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  int ans = 0;
  Flow F(n + 2);
  vector<int> last(101, -1);
  for (int i = 0; i < n; i++) {
    if (b[i] > 0) {
      ans += b[i];
      F.add_edge(n, i, b[i]);
    } else {
      F.add_edge(i, n + 1, -b[i]);
    }
    for (int j = 1; j <= a[i]; j++) {
      if (a[i] % j == 0 && last[j] != -1) {
        F.add_edge(i, last[j], inf);
      }
    }
    last[a[i]] = i;
  }
  
  ans -= F.max_flow(n, n + 1);
  cout << ans << '\n';
  return 0;
}