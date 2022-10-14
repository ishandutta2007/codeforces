#include <bits/stdc++.h>
using namespace std;

template <int MOD>
class ModInt {
 public:
  int v;

  ModInt() : v(0) {}
  ModInt(long long _v) {
    v = int((-MOD < _v && _v < MOD) ? (_v) : (_v % MOD));
    if (v < 0) v += MOD;
  }

  friend bool operator==(const ModInt &a, const ModInt &b) { return a.v == b.v; }
  friend bool operator!=(const ModInt &a, const ModInt &b) { return a.v != b.v; }
  friend bool operator<(const ModInt &a, const ModInt &b) { return a.v < b.v; }
  friend bool operator<=(const ModInt &a, const ModInt &b) { return a.v <= b.v; }
  friend bool operator>(const ModInt &a, const ModInt &b) { return a.v > b.v; }
  friend bool operator>=(const ModInt &a, const ModInt &b) { return a.v >= b.v; }

  ModInt &operator+=(const ModInt &a) {
    if ((v += a.v) >= MOD) v -= MOD;
    return *this;
  }
  ModInt &operator-=(const ModInt &a) {
    if ((v -= a.v) < 0) v += MOD;
    return *this;
  }
  ModInt &operator*=(const ModInt &a) {
    v = 1ll * v * a.v % MOD;
    return *this;
  }
  ModInt &operator/=(const ModInt &a) {
    return (*this) *= inverse(a);
  }

  friend ModInt pow(ModInt a, long long x) {
    ModInt res = 1;
    assert(x >= 0);
    for (; x; x /= 2, a *= a)
      if (x & 1) res *= a;
    return res;
  }
  friend ModInt inverse(ModInt a) {
    assert(a.v != 0);
    return pow(a, MOD - 2);
  }

  ModInt operator+() const { return ModInt(v); }
  ModInt operator-() const { return ModInt(-v); }
  ModInt operator++() const { return *this += 1; }
  ModInt operator--() const { return *this -= 1; }

  friend ModInt operator+(ModInt a, const ModInt &b) { return a += b; }
  friend ModInt operator-(ModInt a, const ModInt &b) { return a -= b; }
  friend ModInt operator*(ModInt a, const ModInt &b) { return a *= b; }
  friend ModInt operator/(ModInt a, const ModInt &b) { return a /= b; }

  friend istream &operator>>(istream &is, ModInt &v) {
    is >> v.v;
    return is;
  }
  friend ostream &operator<<(ostream &os, const ModInt &v) {
    os << v.v;
    return os;
  }
};

const int MOD = 998244353;
using Mint = ModInt<MOD>;

void Main() {
  int N, K;
  cin >> N >> K;

  const auto Brute = [&]() {
    vector<pair<int, int>> ed;
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        ed.emplace_back(i, j);
      }
    }
    int ans = 0;
    vector<vector<int>> adj(N, vector<int>(N));
    const auto Dfs = [&](const auto &self, int u) -> void {
      if (u == ed.size()) {
        int mst = 0, mst2 = 0;
        for (int i = 1; i < N; i++) mst += adj[0][i];
        vector<int> dsu(N, -1);
        function<int(int)> Find = [&](int x) {
          return dsu[x] < 0 ? x : dsu[x] = Find(dsu[x]);
        };
        for (int k = 1; k <= K; k++) {
          for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
              if (adj[i][j] == k) {
                if (Find(i) != Find(j)) {
                  dsu[Find(i)] = j;
                  mst2 += k;
                }
              }
            }
          }
        }
        ans += mst == mst2;
        return;
      }
      for (int k = 1; k <= K; k++) {
        adj[ed[u].first][ed[u].second] = k;
        self(self, u + 1);
      }
    };
    Dfs(Dfs, 0);
    return ans;
  };
  // cout << Brute() << '\n';
  vector<vector<Mint>> choose(N + 1, vector<Mint>(N + 1));
  for (int i = 0; i <= N; i++) {
    choose[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
    }
  }
  vector<vector<Mint>> dp(N + 1, vector<Mint>(K + 1));
  dp[1][0] = 1;
  for (int k = 0; k <= K; k++) {
    for (int n = 1; n <= N; n++) {
      // cout << dp[n][k] << " \n"[n == N];
      for (int n2 = 0; n + n2 <= N; n2++) {
        if (k < K) {
          dp[n + n2][k + 1] += dp[n][k] * choose[N - n][n2] * pow(Mint(K - k), n * n2 - n2 + n2 * (n2 - 1) / 2);
        }
      }
    }
  }
  // Mint ans = 0;
  // for (int k = 1; k <= K; k++) ans += dp[N][k];
  // cout << ans << '\n';
  cout << dp[N][K] << '\n';
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