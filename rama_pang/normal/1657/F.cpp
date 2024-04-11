#include <bits/stdc++.h>
using namespace std;

class StronglyConnected {
 public:
  int N;
  vector<bool> vis;
  vector<int> todo, comp;
  vector<vector<int>> adj, radj, comps;

  StronglyConnected(int N) : N(N), vis(N, false), comp(N, -1), adj(N), radj(N) {}

  void AddEdge(int x, int y) {
    adj[x].emplace_back(y);
    radj[y].emplace_back(x);
  }

  void Dfs(int u) {
    vis[u] = true;
    for (auto v : adj[u])
      if (!vis[v]) Dfs(v);
    todo.emplace_back(u);
  }

  void Dfs2(int u, int x, vector<int> &vec) {
    comp[u] = x;
    vec.emplace_back(u);
    for (auto v : radj[u])
      if (comp[v] == -1) Dfs2(v, x, vec);
  }

  void Kosaraju() {
    for (int i = 0; i < N; i++)
      if (!vis[i]) Dfs(i);
    reverse(begin(todo), end(todo));
    for (auto i : todo)
      if (comp[i] == -1) {
        comps.emplace_back();
        Dfs2(i, int(comps.size()) - 1, comps.back());
      }
  }
};

class TwoSat {
 public:
  int N;
  vector<int> ans;
  StronglyConnected S;

  TwoSat(int N) : N(N), ans(N, 0), S(2 * N) {}

  void EitherOr(int x, int y) {
    x = max(2 * x, -1 - 2 * x);
    y = max(2 * y, -1 - 2 * y);
    S.AddEdge(x ^ 1, y);
    S.AddEdge(y ^ 1, x);
  }

  bool Solve() {
    S.Kosaraju();
    for (int i = 0; i < N; i++) {
      if (S.comp[i * 2] == S.comp[i * 2 + 1]) {
        return false;
      }
    }
    for (int i = 0; i < N; i++) {
      ans[i] = S.comp[i * 2] > S.comp[i * 2 + 1];
    }
    return true;
  }
};

void Main() {
  int N, Q;
  cin >> N >> Q;
  vector<vector<int>> adj(N);
  for (int i = 1; i < N; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  vector<int> par(N);
  vector<int> dep(N);
  const auto Dfs = [&](const auto &self, int u, int p) -> void {
    par[u] = p;
    for (auto v : adj[u]) {
      if (v != p) {
        dep[v] = dep[u] + 1;
        self(self, v, u);
      }
    }
  };
  Dfs(Dfs, 0, -1);
  const auto GetPath = [&](int u, int v) {
    vector<int> uu, vv;
    while (u != v) {
      if (dep[u] >= dep[v]) {
        uu.emplace_back(u);
        u = par[u];
      } else {
        vv.emplace_back(v);
        v = par[v];
      }
    }
    reverse(begin(vv), end(vv));
    uu.emplace_back(u);
    for (auto i : vv) uu.emplace_back(i);
    return uu;
  };

  vector<vector<array<int, 3>>> can(N);
  for (int q = 0; q < Q; q++) {
    int X, Y;
    cin >> X >> Y;
    string S;
    cin >> S;
    X--, Y--;
    auto path = GetPath(X, Y);
    assert(path.size() == S.size());
    for (int i = 0; i < int(S.size()); i++) {
      can[path[i]].push_back({q, S[i] - 'a', S[int(S.size()) - 1 - i] - 'a'});
    }
  }

  TwoSat G(N + Q);
  vector<int> ans(N);
  vector<pair<char, char>> ops(N);
  for (int i = 0; i < N; i++) {
    if (can[i].empty()) {
      ops[i] = {'a', 'a'};
      continue;
    }
    vector<int> in(26);
    int cx = can[i][0][1];
    int cy = can[i][0][2];
    ops[i] = {char('a' + cx), char('a' + cy)};
    for (auto [j, x, y] : can[i]) {
      int cntx = (cx == x) + (cy == x);
      int cnty = (cx == y) + (cy == y);
      if (cx == cy && x == y) {
        if (x == cx) {
        } else {
          cout << "NO\n";
          return;
        }
      } else if (cx == cy) {
        if (x == cx)
          G.EitherOr(j, j);
        else if (y == cy)
          G.EitherOr(~j, ~j);
        else {
          cout << "NO\n";
          return;
        }
      } else if (x == y) {
        if (x == cx)
          G.EitherOr((Q + i), (Q + i));
        else if (x == cy)
          G.EitherOr(~(Q + i), ~(Q + i));
        else {
          cout << "NO\n";
          return;
        }
      } else if (cntx == 0 && cnty == 0) {
        cout << "NO\n";
        return;
      } else if (cntx != 0 && cnty == 0) {
        G.EitherOr(j, j);
        if (cx == x) {
          G.EitherOr(Q + i, Q + i);
        } else if (cy == x) {
          G.EitherOr(~(Q + i), ~(Q + i));
        }
      } else if (cntx == 0 && cnty != 0) {
        G.EitherOr(~j, ~j);
        if (cx == y) {
          G.EitherOr(Q + i, Q + i);
        } else if (cy == y) {
          G.EitherOr(~(Q + i), ~(Q + i));
        }
      } else {
        if (x == cx && y == cy) {
          G.EitherOr(Q + i, ~j);
          G.EitherOr(~(Q + i), j);
          // G.EitherOr()
          // (Q + i) or ~j
          // ~(Q + 1) or j
          // or
          // ~(Q + i) and ~j
          //
        } else if (x == cy && y == cx) {
          G.EitherOr(Q + i, j);
          G.EitherOr(~(Q + i), ~j);
        } else if (x == cx) {
          assert(false);
        }
      }
    }
  }

  if (G.Solve()) {
    cout << "YES\n";
    for (int i = 0; i < N; i++) {
      if (G.ans[Q + i]) {
        cout << ops[i].first;
      } else {
        cout << ops[i].second;
      }
    }
    cout << '\n';
  } else {
    cout << "NO\n";
  }
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