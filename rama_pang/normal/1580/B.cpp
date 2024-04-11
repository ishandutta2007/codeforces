#include <bits/stdc++.h>
using namespace std;

int MOD;

// template <int MOD>
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
  // ModInt operator++() const { return *this += 1; }
  // ModInt operator--() const { return *this -= 1; }

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

// const int MOD = 998244353;
using lint = long long;
using Mint = ModInt;

Mint dp[105][105][105];

void Main() {
  int N, M, K;
  cin >> N >> M >> K >> MOD;
  M--;
  // K good, a good have M maximas
  // if x is good, then all maximas >= x
  // so if we fix all numbers > x first, we can determine
  // so we choose where to place b, will affect differently
  // left and right independent
  // choose position where to place biggest number
  // dp[len][bigger on left or right][k good]
  
  vector<vector<Mint>> C(N + 1, vector<Mint>(N + 1));
  for (int i = 0; i <= N; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  }
  for (int big = 0; big <= N; big++) {
    dp[0][big][0] = 1 % MOD;
  }
  for (int len = 1; len <= N; len++) {
    for (int big = 0; big <= N - len; big++) {
      for (int k = 0; k <= len; k++) {
        for (int i = 1; i <= len; i++) {
          if (big == M) {
            for (int x = max(k - len + i, 0); x <= k && x - 1 <= i - 1; x++) {
              dp[len][big][k] += C[len - 1][i - 1] * dp[i - 1][big + 1][x - 1] * dp[len - i][big + 1][k - x];
            }                 
          } else {
            // k - x <= len - i
            // k - len + i <= x
            for (int x = max(k - len + i, 0); x <= k && x <= i - 1; x++) {
              dp[len][big][k] += C[len - 1][i - 1] * dp[i - 1][big + 1][x] * dp[len - i][big + 1][k - x];
            }            
          }
        }
        // if (dp[len][big][k] != 0) {
        //   cout << dp[len][big][k] << ' ' << len << ' ' << big << ' ' << k << '\n';
        // }
      }
    }
  }
  cout << dp[N][0][K] << '\n';
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