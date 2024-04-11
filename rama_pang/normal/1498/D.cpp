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

const int MOD = 1e9 + 7;
using Mint = ModInt<MOD>;

const int MAX = 1e5 + 5;
using Bit = bitset<MAX>;

using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  cin >> N >> M;
  vector<array<lint, 3>> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i][0] >> A[i][1] >> A[i][2];
  }
  const int MX = 1e5;
  vector<int> ans(M + 1, -1);
  Bit dp = 0;
  dp[0] = 1;
  for (int i = 0; i < N; i++) {
    Bit ndp = 0;
    if (A[i][0] == 1) {
      int lim = A[i][2];
      lint add = (A[i][1] + MX - 1) / MX;
      vector<lint> cnt(add);
      for (int k = 0; k <= M; k++) {
        if (dp[k]) {
          cnt[k % add] += 1;
        }
        lint z = k - 1ll * (lim + 1) * add;
        if (0 <= z && dp[z]) {
          cnt[k % add] -= 1;
        }
        if (cnt[k % add] > 0) {
          ndp[k] = 1;
        }
      }
    } else if (A[i][0] == 2) {
      int lim = A[i][2];
      lint mul = A[i][1];
      vector<lint> nxt(MAX);
      for (int k = 0; k <= M; k++) {
        nxt[k] = (k * mul + MX - 1) / MX;
      }
      vector<int> cnt(MAX, -1);
      if (dp[0]) ndp[0] = dp[0];
      for (int k = 1; k <= M; k++) {
        if (dp[k]) cnt[k] = max(cnt[k], lim);
        if (nxt[k] <= M) cnt[nxt[k]] = max(cnt[nxt[k]], cnt[k] - 1);
        if (cnt[k] >= 0) {
          ndp[k] = 1;
        }
      }
    }
    dp = ndp;
    for (int j = 1; j <= M; j++) {
      if (dp[j] && ans[j] == -1) {
        ans[j] = i + 1;
      }
    }
  }
  for (int i = 1; i <= M; i++) {
    cout << ans[i] << " \n"[i == M];
  }
  return 0;
}