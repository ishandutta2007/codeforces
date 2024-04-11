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

  string X, Y;
  cin >> X >> Y;

  int N = X.size();
  int M = Y.size();

  vector<vector<vector<vector<Mint>>>> dp(N + 1, vector<vector<vector<Mint>>>(M + 1, vector<vector<Mint>>(3, vector<Mint>(4))));
  // dp[i][k][k][l]:
  // distinct sequences, such that the last character is k (can be represented with 0, 1, 2), and:
  // (l & 1) == 0: the sequences doesn't have a X member
  // (l & 2) == 0: the sequences doesn't have a Y member

  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      dp[i][j][0][0] += 1;
      for (int k = 0; k < 3; k++) {
        char last = k == 0 ? '-' : (k == 1 ? (i > 0 ? X[i - 1] : '-') : (j > 0 ? Y[j - 1] : '-'));
        for (int l = 0; l < 4; l++) {
          if (i < N && last != X[i]) dp[i + 1][j][1][l | 1] += dp[i][j][k][l];
          if (j < M && last != Y[j]) dp[i][j + 1][2][l | 2] += dp[i][j][k][l];
        }
      }
    }
  }

  Mint ans = 0;
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      for (int c = 0; c < 3; c++) {
        ans += dp[i][j][c][3];
      }
    }
  }

  cout << ans << '\n';
  return 0;
}