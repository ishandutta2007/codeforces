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

Mint dp[2][405][405][3][3];
Mint sum[405][405];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  const int K = 26;
  vector<int> occ(K);
  for (int i = 0; i < K; i++) {
    cin >> occ[i];
  }

  for (int i = 0; i < K; i++) {
    for (int j = 0; j < K; j++) {
      for (int k = 0; k < K; k++) {
        if (i != k) {
          int cnt0 = (i == 0) + (j == 0) + (k == 0);
          int cnt1 = (i == 1) + (j == 1) + (k == 1);
          dp[0][cnt0][cnt1][min(j, 2)][min(k, 2)] += 1;
        }
      }
    }
  }

  for (int n = 4; n <= N; n++) {
    for (int i = 0; i <= n; i++) {
      for (int j = 0; i + j <= n; j++) {
        for (int k = 0; k < 3; k++) {
          for (int l = 0; l < 3; l++) {
            dp[1][i][j][k][l] = dp[0][i][j][k][l];
            dp[0][i][j][k][l] = 0;
          }
        }
      }
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 0; i + j <= n; j++) {
        for (int k = 0; k < 3; k++) {
          for (int l = 0; l < 3; l++) {
            for (int a = 0; a < 3; a++) {
              dp[0][i + (a == 0)][j + (a == 1)][l][a] += dp[1][i][j][k][l] * ((a == 2 ? 24 : 1) - (k == a));
            }
          }
        }
      }
    }
  }

  for (int i = 0; i <= N; i++) {
    for (int j = 0; i + j <= N; j++) {
      for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
          sum[i][j] += dp[0][i][j][k][l];
        }
      }
    }
  }
  for (int i = N; i >= 0; i--) {
    for (int j = N; j >= 0; j--) {
      sum[i][j] += sum[i + 1][j] + sum[i][j + 1] - sum[i + 1][j + 1];
    }
  }

  Mint ans = 0;

  // + All strings, no restrictions
  ans += sum[0][0];

  // - All strings, restrict 1 character
  for (int a = 0; a < K; a++) {
    ans -= sum[occ[a] + 1][0];
  }

  // + All strings, restrict 2 characters
  for (int a = 0; a < K; a++) {
    for (int b = a + 1; b < K; b++) {
      ans += sum[occ[a] + 1][occ[b] + 1];
    }
  }

  cout << ans << '\n';
  return 0;
}