#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

template<int MOD>
class ModInt {
 public:
  int v;

  ModInt() : v(0) {}
  ModInt(long long _v) {
    v = int((-MOD < _v && _v < MOD) ? (_v) : (_v % MOD));
    if (v < 0) v += MOD; }

  friend bool operator==(const ModInt &a, const ModInt &b) { return a.v == b.v; }
  friend bool operator!=(const ModInt &a, const ModInt &b) { return a.v != b.v; }
  friend bool operator<(const ModInt &a, const ModInt &b) { return a.v < b.v; }
  friend bool operator<=(const ModInt &a, const ModInt &b) { return a.v <= b.v; }
  friend bool operator>(const ModInt &a, const ModInt &b) { return a.v > b.v; }
  friend bool operator>=(const ModInt &a, const ModInt &b) { return a.v >= b.v; }

  ModInt& operator+=(const ModInt &a) {
    if ((v += a.v) >= MOD) v -= MOD;
    return *this; }
  ModInt& operator-=(const ModInt &a) {
    if ((v -= a.v) < 0) v += MOD;
    return *this; }
  ModInt& operator*=(const ModInt &a) {
    v = 1ll * v * a.v % MOD;
    return *this; }
  ModInt& operator/=(const ModInt &a) {
    return (*this) *= inverse(a); }

  friend ModInt pow(ModInt a, long long x) {
    ModInt res = 1; assert(x >= 0);
    for (; x; x /= 2, a *= a) if (x & 1) res *= a;
    return res; }
  friend ModInt inverse(ModInt a) {
    assert(a.v != 0);
    return pow(a, MOD - 2); }

  ModInt operator+() const { return ModInt(v); }
  ModInt operator-() const { return ModInt(-v); }
  ModInt operator++() const { return *this += 1; }
  ModInt operator--() const { return *this -= 1; }

  friend ModInt operator+(ModInt a, const ModInt &b) { return a += b; }
  friend ModInt operator-(ModInt a, const ModInt &b) { return a -= b; }
  friend ModInt operator*(ModInt a, const ModInt &b) { return a *= b; }
  friend ModInt operator/(ModInt a, const ModInt &b) { return a /= b; }

  friend istream& operator>>(istream &is, ModInt &v) { is >> v.v; return is; }
  friend ostream& operator<<(ostream &os, const ModInt &v) { os << v.v; return os; }
};

const int MOD = 1e9 + 7;
using Mint = ModInt<MOD>;

void Main() {
  int N, M;
  cin >> N >> M;
  vector<string> G(N);
  for (int i = 0; i < N; i++) {
    cin >> G[i];
  }
  vector<int> A(M);
  for (int i = 0; i < M; i++) {
    cin >> A[i];
  }

  int nodes = 0;
  vector<vector<int>> X(N, vector<int>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (G[i][j] == '#') {
        X[i][j] = nodes++;
      } else {
        X[i][j] = -1;
      }
    }
  }
  vector<vector<int>> radj(nodes);
  vector<vector<int>> adj(nodes);
  const auto AddEdge = [&](int u, int v) {
    adj[u].emplace_back(v);
    radj[v].emplace_back(u);
  };
  vector<int> last(M, -1);
  for (int i = N - 1; i >= 0; i--) {
    for (int j = 0; j < M; j++) {
      if (X[i][j] != -1) {
        if (j > 0 && last[j - 1] != -1) {
          AddEdge(X[i][j], last[j - 1]);
        }
        if (last[j] != -1) {
          AddEdge(X[i][j], last[j]);
        }
        if (j + 1 < M && last[j + 1] != -1) {
          AddEdge(X[i][j], last[j + 1]);
        }
      }
    }
    for (int j = 0; j < M; j++) {
      if (X[i][j] != -1) {
        last[j] = X[i][j];
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (X[i][j] != -1) {
        if (i > 0 && X[i - 1][j] != -1) {
          AddEdge(X[i][j], X[i - 1][j]);
        }
        if (i + 1 < N && X[i + 1][j] != -1) {
          AddEdge(X[i][j], X[i + 1][j]);
        }
        if (j > 0 && X[i][j - 1] != -1) {
          AddEdge(X[i][j], X[i][j - 1]);
        }
        if (j + 1 < M && X[i][j + 1] != -1) {
          AddEdge(X[i][j], X[i][j + 1]);
        }
      }
    }
  }

  vector<int> vis(nodes), comp(nodes, -1), topo;
  const auto Dfs1 = [&](const auto &self, int u) -> void {
    vis[u] = 1;
    for (auto v : adj[u]) if (!vis[v]) self(self, v);
    topo.emplace_back(u);
  };
  for (int i = 0; i < nodes; i++) {
    if (!vis[i]) {
      Dfs1(Dfs1, i);
    }
  }

  reverse(begin(topo), end(topo));
  const auto Dfs2 = [&](const auto &self, int u, int c) -> void {
    comp[u] = c;
    for (auto v : radj[u]) if (comp[v] == -1) self(self, v, c);
  };

  int scc = 0;
  for (auto i : topo) {
    if (comp[i] == -1) {
      Dfs2(Dfs2, i, scc++);
    }
  }


  vector<int> indeg(scc);
  for (int i = 0; i < nodes; i++) {
    for (auto j : adj[i]) {
      if (comp[i] == comp[j]) continue;
      indeg[comp[j]]++;
    }
  }

  int ans = 0;
  for (int i = 0; i < scc; i++) {
    if (indeg[i] == 0) {
      ans += 1;
    }
  }

  cout << ans << '\n';
  return;
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