#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M, C, Q;
  cin >> N >> M >> C >> Q;

  vector<int> p;
  vector<set<int>> adj; // reachable v if we add final edge (v, c) -> (v, 0)
  map<pair<int, int>, int> id;
  const auto GetId = [&](int u, int c) {
    if (id.count({u, c}) == 0) {
      id[{u, c}] = id.size();
      p.push_back(-1);
      adj.push_back({});
    }
    return id[{u, c}];
  };

  const auto Find = [&](const auto &self, int u) -> int {
    return p[u] < 0 ? u : p[u] = self(self, p[u]);
  };

  const auto Unite = [&](int x, int y) {
    x = Find(Find, x);
    y = Find(Find, y);
    if (x == y) {
      return;
    }
    if (-p[x] < -p[y]) {
      swap(x, y);
    }
    p[x] += p[y];
    p[y] = x;
    if (adj[x].size() < adj[y].size()) {
      swap(adj[x], adj[y]);
    }
    for (auto i : adj[y]) {
      adj[x].insert(i);
    }
    adj[y].clear();
  };

  const auto Add = [&](int x, int y) {
    x = Find(Find, x);
    adj[x].insert(y);
  };

  const auto AddEdge = [&](int u, int v, int c) {
    Add(GetId(u, c), GetId(u, 0));
    Add(GetId(v, c), GetId(v, 0));
    Unite(GetId(u, 0), GetId(v, c));
    Unite(GetId(u, c), GetId(v, 0));
  };

  for (int i = 0; i < N; i++) {
    GetId(i, 0);
  }

  while (M--) {
    int x, y, z;
    cin >> x >> y >> z;
    x--, y--;
    AddEdge(x, y, z);
  }
  while (Q--) {
    char t;
    int x, y;
    cin >> t >> x >> y;
    x--, y--;
    if (t == '+') {
      int z;
      cin >> z;
      AddEdge(x, y, z);
    } else if (t == '?') {
      if (Find(Find, GetId(x, 0)) == Find(Find, GetId(y, 0)) || adj[Find(Find, GetId(x, 0))].count(y) == 1) {
        cout << "Yes\n";
      } else {
        cout << "No\n";
      }
    }
  }
  return 0;
}