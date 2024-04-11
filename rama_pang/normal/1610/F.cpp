#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

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
    for (auto v : adj[u]) if (!vis[v]) Dfs(v);
    todo.emplace_back(u);
  }

  void Dfs2(int u, int x, vector<int> &vec) {
    comp[u] = x; vec.emplace_back(u);
    for (auto v : radj[u]) if (comp[v] == -1) Dfs2(v, x, vec);
  }

  void Kosaraju() {
    for (int i = 0; i < N; i++) if (!vis[i]) Dfs(i);
    reverse(begin(todo), end(todo));
    for (auto i : todo) if (comp[i] == -1) {
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

#define int lint

void Main() {
  // |out - in + heavyout - heavyin| = 1
  //
  // out + in = deg
  // heavyout + heavyin = heavy
  // 
  // out - in + heavyout - heavyin = -1
  //   2out + 2heavyout = deg + heavy - 1
  // out - in + heavyout - heavyin = 1
  //   2out + 2heavyout = deg + heavy + 1
  // deg + heavy

  int N, M;
  cin >> N >> M;
  TwoSat G(M);
  vector<int> W(M), U(M), V(M);
  vector<vector<array<int, 3>>> adj(N);
  for (int i = 0; i < M; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    U[i] = u;
    V[i] = v;
    W[i] = w;
    adj[u].push_back({v, w, ~i});
    adj[v].push_back({u, w, i});
  }

  int ans = 0;

  vector<int> state(N);
  for (int u = 0; u < N; u++) {
    int cur = 0;
    for (auto [a, b, c] : adj[u]) {
      cur += b;
    }
    if (cur & 1) state[u] = 1;
    if (state[u]) {
      ans += 1;
      vector<int> one, two;
      for (auto [a, b, c] : adj[u]) {
        if (b == 1) {
          one.emplace_back(c);
        } else {
          two.emplace_back(c);
        }
      }
      while (two.size() >= 2) {
        int x = two.back(); two.pop_back();
        int y = two.back(); two.pop_back();
        G.EitherOr(x, y);
        G.EitherOr(~x, ~y);      
      }
      while (one.size() >= 2) {
        int x = one.back(); one.pop_back();
        int y = one.back(); one.pop_back();
        G.EitherOr(x, y);
        G.EitherOr(~x, ~y);
      }
      assert(one.size() == 1);
      if (two.size() == 1) {
        int x = two.back();
        int y = one.back();
        G.EitherOr(x, y);
        G.EitherOr(~x, ~y);
      }
    }
  }
  assert(G.Solve());
  auto res = G.ans;
  cout << ans << '\n';
  vector<int> deg(N);
  for (int i = 0; i < M; i++) {
    cout << res[i] + 1;
    if (res[i] == 1) {
      deg[U[i]] += W[i];
      deg[V[i]] -= W[i];
    } else {
      deg[U[i]] -= W[i];
      deg[V[i]] += W[i];
    }
  }
  cout << '\n';
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    cnt += abs(deg[i]) == 1;
  }
  assert(ans == cnt);

  // dp[pos][lev]
  // dp[pos + 1][lev] |= dp[pos][lev]
  // if A[pos] == "("
  //   dp[pos + 1][lev + 1] |= dp[pos][lev]
  // else
  //   dp[pos + 1][lev - 1] |= dp[pos][lev]
  // 
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}