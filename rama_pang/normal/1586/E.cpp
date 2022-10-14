#include <bits/stdc++.h>
using namespace std;

const int MAX = 3e5 + 5;
int dsu[MAX];

int Find(int x) {
  return dsu[x] < 0 ? x : dsu[x] = Find(dsu[x]);
}

void Main() {
  memset(dsu, -1, sizeof(dsu));
  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> edges;
  vector<vector<int>> adj(N);
  while (M--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    if (Find(x) == Find(y)) {

    } else {
      edges.emplace_back(min(x, y), max(x, y));
      dsu[Find(x)] = Find(y);
      adj[x].emplace_back(y);
      adj[y].emplace_back(x);
    }
  }
  map<pair<int, int>, int> edge;
  const auto Toggle = [&](int x, int y) {
    if (x > y) swap(x, y);
    edge[{x, y}] ^= 1;
  };
  int Q;
  cin >> Q;
  vector<vector<int>> ans;
  while (Q--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    ans.emplace_back();
    const auto Dfs = [&](const auto &self, int u, int p) -> int {
      if (u == x) {
        ans.back().emplace_back(u);
        return 1;
      }
      for (auto v : adj[u]) if (v != p) {
        int r = self(self, v, u);
        if (r == 1) {
          Toggle(u, v);
          ans.back().emplace_back(u);
          return 1;
        }
      }
      return 0;
    };
    Dfs(Dfs, y, -1);
  }

  int ok = 1;
  for (auto [u, v] : edges) {
    if (edge[{u, v}] == 1) {
      ok = 0;
    }
  }
  if (ok) {
    cout << "YES\n";
    for (auto a : ans) {
      cout << a.size() << '\n';
      for (auto i : a) {
        cout << i + 1 << ' ';
      }
      cout << '\n';
    }
    return;
  }
  cout << "NO\n";
  int root = -1;
  for (int i = 0; i < N; i++) {
    if (adj[i].size() == 1) {
      root = i;
    }
  }
  const auto Dfs = [&](const auto &self, int u, int p, int on) -> int {
    int res = 0;
    for (auto v : adj[u]) if (v != p) {
      int e = edge[{min(u, v), max(u, v)}];
      if (e == 1 && on == 1) {
        on = 0;
        res += self(self, v, u, 1);
      } else if (e == 1 && on == 0) {
        on = 1;
        res += 1;
        res += self(self, v, u, 1);
      } else {
        res += self(self, v, u, 0);
      }
    }
    return res;
  };
  cout << Dfs(Dfs, root, -1, 0) << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}