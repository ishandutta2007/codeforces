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

using lint = long long;
using Mint = ModInt<MOD>;

const int MAXN = 1e5 + 5;

int N, K;
vector<int> adj[MAXN];

pair<int, int> Dfs(int u, int p) {
  pair<int, int> res = {0, u};
  for (auto v : adj[u]) if (v != p) {
    auto q = Dfs(v, u);
    res = max(res, {q.first + 1, q.second});
  }
  return res;
}

vector<int> diam;
int Get(int u, int p, int target) {
  if (u == target) {
    diam.emplace_back(u);
    return 1;
  }
  for (auto v : adj[u]) if (v != p) {
    if (Get(v, u, target)) {
      diam.emplace_back(u);
      return 1;
    }
  }
  return 0;
}

int dep[MAXN];

void Depth(int u, int p) {
  int ch = 0;
  for (auto v : adj[u]) if (v != p) {
    dep[v] = dep[u] + 1;
    Depth(v, u);
    ch++;
  }
  if (ch == 0) {
    if (dep[u] != K) {
      cout << "NO\n";
      exit(0);
    }
  } else if (ch < 3) {
    cout << "NO\n";
    exit(0);
  }
}

void Main() {
  cin >> N >> K;
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  int R1 = Dfs(1, 0).second;
  int R2 = Dfs(R1, 0).second;
  Get(R1, 0, R2);

  if (diam.size() != 2 * K + 1) {
    cout << "NO\n";
    return;
  }

  int center = diam[K];
  Depth(center, 0);

  cout << "YES\n";
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