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

using lint = long long;
const lint INF = 1e18;

const int MAX = 2e5 + 5;

Mint fact[MAX];
Mint ifact[MAX];

void Main() {
  int N, K;
  cin >> N >> K;

  const auto C = [&](lint n, lint k) -> Mint {
    if (n < 0 || k < 0 || k > n) return 0;
    return fact[n] * ifact[k] * ifact[n - k];
  };

  vector<Mint> ways(N + 1);
  for (lint X = 1; X < N; X++) {
    ways[X] += fact[X] * (N - X) * C(N - (X - 1) * (K - 1), X); // to have dist >= K everyone
    ways[X] -= fact[X + 1] * C(N - X * (K - 1), X + 1);
  }

  Mint ans = 0;
  for (int i = 1; i < N; i++) {
    // prob = 1/N * 1/(N - 1) * ... * 1/(N - i)
    ans += (i + 1) * ways[i] * ifact[N] * fact[N - i - 1];
  }

  cout << ans << '\n';
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fact[0] = ifact[0] = 1;
  for (int i = 1; i < MAX; i++) {
    fact[i] = i * fact[i - 1];
    ifact[i] = Mint(1) / fact[i];
  }

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}