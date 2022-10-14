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

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, K;
  cin >> N >> K;

  vector<vector<int>> adj(N);
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  vector<vector<Mint>> dp(N);

  const auto Dfs = [&](const auto &self, int u, int p) -> void {
    dp[u] = {1};
    for (auto v : adj[u]) if (v != p) {
      self(self, v, u);
      dp[v].insert(begin(dp[v]), 0);
      vector<Mint> ndp(min(dp[u].size() + dp[v].size(), (size_t) K + 1));
      for (int i = 0; i < (int) dp[u].size(); i++) {
        ndp[i] += dp[u][i] * accumulate(begin(dp[v]), end(dp[v]), Mint(0)); // edge (u, v) doesn't exist
        for (int j = 0; j < (int) dp[v].size() && i + j <= K; j++) {
          ndp[max(i, j)] += dp[u][i] * dp[v][j]; // edge (u, v) exist
        }
      }
      dp[u] = ndp;
    }
  };

  Dfs(Dfs, 0, -1);

  cout << accumulate(begin(dp[0]), end(dp[0]), Mint(0)) << '\n';
  return 0;
}