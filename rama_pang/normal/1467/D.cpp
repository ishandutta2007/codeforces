#include <bits/stdc++.h>
using namespace std;
using lint = long long;

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

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, K, Q;
  cin >> N >> K >> Q;

  vector<vector<Mint>> dp(N, vector<Mint>(K + 1));
  for (int i = 0; i < N; i++) {
    dp[i][0] = 1;
  }
  for (int j = 1; j <= K; j++) {
    for (int i = 0; i < N; i++) {
      dp[i][j] = (i > 0 ? dp[i - 1][j - 1] : 0) + (i + 1 < N ? dp[i + 1][j - 1] : 0);
    }
  }

  vector<Mint> cnt(N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= K; j++) {
      cnt[i] += dp[i][j] * dp[i][K - j];
    }
  }

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  Mint ans = 0;
  for (int i = 0; i < N; i++) {
    ans += 1ll * cnt[i] * A[i];
  }
  while (Q--) {
    int i, x;
    cin >> i >> x;
    i--;
    ans -= 1ll * cnt[i] * A[i];
    A[i] = x;
    ans += 1ll * cnt[i] * A[i];
    cout << ans << '\n';
  }
  return 0;
}