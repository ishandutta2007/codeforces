#include <bits/stdc++.h>
using namespace std;

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

const int MOD = 998244353;
using Mint = ModInt<MOD>;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> pattern(27 * 27 * 27 * 27, -1);
    const auto Hash = [&](string s) {
      int h = 0;
      for (auto i : s) {
        h *= 27;
        if (i != '_') {
          h += i - 'a' + 1;
        }
      }
      assert(h < 27 * 27 * 27 * 27);
      return h;
    };
    vector<string> pat(n);
    for (int i = 0; i < n; i++) {
      cin >> pat[i];
      pattern[Hash(pat[i])] = i;
    }
    bool bad = false;
    string s, t;
    vector<pair<int, string>> inp(m);
    for (int i = 0; i < m; i++) {
      cin >> inp[i].second >> inp[i].first;
    }
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
      s = inp[i].second;
      int mt = inp[i].first;
      mt--;
      int cnt = 0;
      for (int mask = 0; mask < (1 << k); mask++) {
        t = s;
        for (int j = 0; j < k; j++) {
          if ((mask >> j) & 1) {
            t[j] = '_';
          }
        }
        int h = Hash(t);
        if (pattern[h] != -1) {
          cnt += pattern[h] == mt;
          if (mt != pattern[h]) {
            edges.emplace_back(mt, pattern[h]);
          }
        }
      }
      if (cnt == 0) {
        cout << "NO\n";
        return 0;
      }
    }
    vector<int> topo;
    vector<vector<int>> adj(n);
    for (auto [u, v] : edges) adj[u].emplace_back(v);
    vector<int> vis(n);
    const auto Dfs = [&](const auto &self, int u) -> void {
      vis[u] = 1;
      for (auto v : adj[u]) if (!vis[v]) self(self, v);
      topo.emplace_back(u);
    };
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        Dfs(Dfs, i);
      }
    }
    reverse(begin(topo), end(topo));
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
      pos[topo[i]] = i;
    }
    for (auto [u, v] : edges) {
      if (pos[u] < pos[v]) {
        continue;
      }
      cout << "NO\n";
      return 0;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
      cout << topo[i] + 1 << ' ';
    }
    cout << '\n';
  }
  return 0;
}