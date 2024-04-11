#include <bits/stdc++.h>
using namespace std;

void Solve() {
  int N;
  cin >> N;
  vector<vector<int>> adj(N);

  auto Query = [&](vector<int> q) {
    if (q.empty()) {
      return pair<int, int>{-1, -1};
    }
    cout << "? " << q.size();
    for (auto i : q) {
      cout << " " << i + 1;
    }
    cout << endl;
    int x, d;
    cin >> x >> d;
    return pair<int, int>{x - 1, d};
  };

  for (int i = 1; i < N; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  vector<int> all(N);
  iota(begin(all), end(all), 0);
  int r, dist;
  tie(r, dist) = Query(all);

  vector<vector<int>> nodes(N + 1);
  function<void(int, int, int)> Dfs = [&](int u, int p, int d) {
    nodes[d].emplace_back(u);
    for (auto v : adj[u]) if (v != p) {
      Dfs(v, u, d + 1);
    }
  };
  Dfs(r, -1, 0);
  int a = r, b = r;
  int lo = (dist + 1) / 2, hi = dist;
  while (lo <= hi) {
    int md = (lo + hi) / 2;
    int x, d;
    tie(x, d) = Query(nodes[md]);
    if (d == dist) {
      a = x;
      lo = md + 1;
    } else {
      hi = md - 1;
    }
  }

  nodes.clear();
  nodes.resize(N + 1);
  Dfs(a, -1, 0);
  int d;
  tie(b, d) = Query(nodes[dist]);
  cout << "! " << a + 1 << " " << b + 1 << "\n";
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    Solve();
    string s;
    cin >> s;
    if (s != "Correct") {
      break;
    }
  }
}