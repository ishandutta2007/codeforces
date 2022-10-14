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

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> mp;
  vector<int> cnt(30);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;
    for (int j = 0; j < 30; j++) {
      if ((a[i] >> j) & 1) {
        cnt[j]++;
      }
    }
  }

  // AND(1...N-1) = A[N]
  // AND(1...N-2) = A[N - 1] & A[N]
  // AND(1...N-2) = A[N - 1] & AND(1...N-1)
  // AND(1...N-2) = AND(1...N-1)
  // AND(1...N-3) = AND(1...N-2)

  Mint fact = 1;
  for (int i = 1; i <= n - 2; i++) {
    fact *= i;
  }
  Mint ans = 0;
  for (int i = 0; i < n; i++) {
    mp[a[i]]--;
    for (int j = 0; j < 30; j++) {
      if ((a[i] >> j) & 1) {
        cnt[j]--;
      }
    }
    int AND = 0;
    for (int j = 0; j < 30; j++) {
      if (cnt[j] == n - 1) {
        AND |= 1 << j;
      }
    }
    if (AND == a[i]) {
      ans += mp[AND] * fact;
    }
    mp[a[i]]++;
    for (int j = 0; j < 30; j++) {
      if ((a[i] >> j) & 1) {
        cnt[j]++;
      }
    }
  }
  
  cout << ans << '\n';
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}