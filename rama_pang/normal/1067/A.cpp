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

Mint dp[2][201][2];

void Main() {
  int N, M = 200;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  dp[0][0][1] = 1;
  vector<Mint> pref0(M + 1);
  vector<Mint> pref1(M + 1);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= M; j++) {
      dp[(i + 1) & 1][j][0] = dp[(i + 1) & 1][j][1] = 0;
    }
    if (A[i] == -1) {
      fill(begin(pref0), end(pref0), 0);
      fill(begin(pref1), end(pref1), 0);
      for (int last = 0; last <= M; last++) {
        pref0[last] = dp[i & 1][last][0];
        pref1[last] = dp[i & 1][last][1];
        if (last) {
          pref0[last] += pref0[last - 1];
          pref1[last] += pref1[last - 1];
        }
      }
      for (int elem = 1; elem <= M; elem++) {
        dp[(i + 1) & 1][elem][1] += pref1[M] - pref1[elem - 1];
        dp[(i + 1) & 1][elem][1] += dp[i & 1][elem][0];
        dp[(i + 1) & 1][elem][0] += pref1[elem - 1];
        dp[(i + 1) & 1][elem][0] += pref0[elem - 1];
      }
    } else {
      for (int last = 0; last <= M; last++) {
        for (int lastok = 0; lastok < 2; lastok++) {
          dp[(i + 1) & 1][A[i]][last >= A[i]] += (lastok || last <= A[i]) * dp[i & 1][last][lastok];
        }
      }
    }
  }
  Mint ans = 0;
  for (int j = 1; j <= M; j++) {
    ans += dp[N & 1][j][1];
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