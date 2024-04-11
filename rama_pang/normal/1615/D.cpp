#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> tree(n), adj(n);
  vector<array<int, 3>> edges;
  for (int i = 1; i < n; i++) {
    int x, y, v;
    cin >> x >> y >> v;
    x--, y--;
    edges.push_back({x, y, v});
    tree[x].emplace_back(y, v);
    tree[y].emplace_back(x, v);
    if (v != -1) {
      adj[x].emplace_back(y, 0);
      adj[y].emplace_back(x, 0);
    } else {

    }
  }
  vector<int> cntNeg(n);
  vector<int> Xor(n);
  const auto Dfs = [&](const auto &self, int u, int p) -> void {
    for (auto [v, val] : tree[u]) {
      if (v != p) {
        cntNeg[v] = cntNeg[u] + (val == -1);
        Xor[v] = Xor[u] ^ max(0, val);
        self(self, v, u);
      }
    }
  };
  Dfs(Dfs, 0, -1);
  while (m--) {
    int a, b, p;
    cin >> a >> b >> p;
    a--, b--;
    int XOR = Xor[a] ^ Xor[b];
    if ((__builtin_popcount(XOR) & 1) == p) {
      // the unknown edges must have even parity
      adj[a].emplace_back(b, 0);
      adj[b].emplace_back(a, 0);
    } else {
      // the known edges must have odd parity
      adj[a].emplace_back(b, 1);
      adj[b].emplace_back(a, 1);
    }
  }
  // All cycles in adj[] must be even length

  vector<int> color(n, -1);
  vector<int> que;    
  for (int s = 0; s < n; s++) {
    if (color[s] != -1) continue;
    que = {s};
    color[s] = 0;
    for (int q = 0; q < int(que.size()); q++) {
      int u = que[q];
      for (auto [v, c] : adj[u]) {
        if (color[v] == -1) {
          color[v] = color[u] ^ c;
          que.emplace_back(v);
        }
        if (color[v] != (color[u] ^ c)) {
          cout << "NO\n";
          return;
        }
      }
    }
  }
  cout << "YES\n";
  for (int i = 0; i < n - 1; i++) {
    auto [u, v, w] = edges[i];
    cout << u + 1 << ' ' << v + 1 << ' ';
    if (w == -1) {
      if (color[u] == color[v]) cout << 0 << '\n';
      else cout << 1 << '\n';
    } else {
      cout << w << '\n';
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}