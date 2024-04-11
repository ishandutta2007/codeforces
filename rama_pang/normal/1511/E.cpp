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

using lint = long long;
const lint INF = 1e18;

void Main() {
  int N, M;
  cin >> N >> M;
  vector<string> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  const int MAX = N * M + 5;
  vector<Mint> dp(MAX);
  vector<Mint> pref(MAX);
  vector<Mint> pref2(MAX);

  dp[0] = dp[1] = 0;
  for (int i = 2; i < MAX; i++) {
    dp[i] += dp[i - 1]; // last character is 0
    dp[i] += int(i / 2); // all characters is 1
    dp[i] += pref[i - 2];
    dp[i] += pow(Mint(2), i - 1) * pref2[i - 1];
    pref[i] = pref[i - 1] + dp[i];
    pref2[i] = pref2[i - 1] + int(i / 2) * (pow(Mint(1) / Mint(2), i));
  }

  const auto Solve = [&]() -> Mint {
    vector<int> segments;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
      cnt += count(begin(A[i]), end(A[i]), 'o');
      for (int j = 0; j < M; j++) if (A[i][j] == 'o') {
        int k = j;
        while (k + 1 < M && A[i][k + 1] == 'o') k += 1;
        segments.emplace_back(k - j + 1);
        j = k;
      }
    }
    Mint ans = 0;
    for (auto seg : segments) {
      ans += dp[seg] * pow(Mint(2), cnt - seg);
    }
    return ans;
  };

  Mint ans = 0;
  ans += Solve();
  {
    vector<string> B(M, string(N, '?'));
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        B[j][i] = A[i][j];
      }
    }
    A = B;
    swap(N, M);
  }
  ans += Solve();
  
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