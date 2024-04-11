#include <bits/stdc++.h>
using namespace std;

int MOD;

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

  friend ModInt operator+(ModInt a, const ModInt &b) { return a += b; }
  friend ModInt operator-(ModInt a, const ModInt &b) { return a -= b; }
  friend ModInt operator*(ModInt a, const ModInt &b) { return a *= b; }
  friend ModInt operator/(ModInt a, const ModInt &b) { return a /= b; }

  friend istream& operator>>(istream &is, ModInt &v) { is >> v.v; return is; }
  friend ostream& operator<<(ostream &os, const ModInt &v) { os << v.v; return os; }
};

using Mint = ModInt;

void Main() {
  int N;
  cin >> N >> MOD;

  const auto Brute = [&]() {
    Mint res = 0;
    vector<int> p(N);
    iota(begin(p), end(p), 0);
    do {
      vector<int> q(N);
      iota(begin(q), end(q), 0);
      do {
        if (p < q) {
          int inv = 0;
          for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
              if (p[i] > p[j]) inv++;
              if (q[i] > q[j]) inv--;
            }
          }
          if (inv > 0) {
            res += 1;
          }
        }
      } while (next_permutation(begin(q), end(q)));
    } while (next_permutation(begin(p), end(p)));
    return res;
  };

  // cout << Brute() << '\n';

  vector<Mint> fact(N + 1);
  fact[0] = 1;
  for (int i = 1; i <= N; i++) {
    fact[i] = i * fact[i - 1];
  }

  vector<vector<Mint>> choose(N + 1, vector<Mint>(N + 1));
  for (int i = 0; i <= N; i++) {
    choose[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      choose[i][j] = choose[i - 1][j] + choose[i - 1][j - 1];
    }
  }

  int K = N * (N + 1) / 2 + 5;

  Mint ans = 0;
  vector<Mint> dp(2 * K + 1);
  dp[K] = 1;

  for (int same = N - 2; same >= 0; same--) {
    int inDp = N - same - 1;
    Mint ways = 0;

    int ptr = K;
    Mint sumDp = 0;

    for (int d = inDp; d >= 1; d--) {
      while (ptr - d > 0) {
        sumDp += dp[K + ptr--];
      }
      ways += sumDp * (inDp - d + 1);
    }

    ans += fact[same] * choose[N][same] * ways;

    auto ndp = dp;
    fill(begin(dp), end(dp), Mint(0));
    for (int inv = -K; inv <= K; inv++) if (ndp[K + inv] != 0) {
      dp[K + inv] += ndp[K + inv];
      dp[K + inv + inDp + 1] -= ndp[K + inv];
    }
    for (int i = 1; i < int(dp.size()); i++) {
      dp[i] += dp[i - 1];
    }

    ndp = dp;
    fill(begin(dp), end(dp), Mint(0));
    for (int inv = -K; inv <= K; inv++) if (ndp[K + inv] != 0) {
      dp[K + inv - inDp] += ndp[K + inv];
      dp[K + inv + 1] -= ndp[K + inv];
    }
    for (int i = 1; i < int(dp.size()); i++) {
      dp[i] += dp[i - 1];
    }
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