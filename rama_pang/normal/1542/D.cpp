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

void Main() {
  int N;
  cin >> N;
  vector<char> ops(N);
  vector<pair<int, int>> val(N);
  for (int i = 0; i < N; i++) {
    cin >> ops[i];
    if (ops[i] == '+') {
      cin >> val[i].first;
      val[i].second = i;
    }
  }

  Mint ans = 0;
  for (int _ = 0; _ < N; _++) {
    if (ops[_] == '-') continue;
    auto cur = val[_];
    vector<Mint> dp(N + 5);
    vector<Mint> ndp(N + 5);
    dp[0] = 1;
    for (int idx = 0; idx < N; idx++) {
      ndp = dp;
      for (int i = 0; i <= N; i++) {
        if (idx < _) {
          if (ops[idx] == '-') {
            ndp[max(0, i - 1)] += dp[i];
          } else {
            if (val[idx] < cur) {
              ndp[i + 1] += dp[i];
            } else {
              ndp[i] += dp[i];
            }
          }
        } else if (idx == _) {
          
        } else {
          if (ops[idx] == '-') {
            if (i == 0) {
              continue;
            }
            ndp[i - 1] += dp[i];
          } else {
            if (val[idx] < cur) {
              ndp[i + 1] += dp[i];
            } else {
              ndp[i] += dp[i];
            }
          }
        }
      }
      swap(dp, ndp);
    }
    Mint ways = 0;
    for (int j = 0; j <= N; j++) {
      ways += dp[j];
    }
    ans += ways * cur.first;
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