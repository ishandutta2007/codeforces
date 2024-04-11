#include <bits/stdc++.h>
using namespace std;

using lint = long long;
#define int lint

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

const int MAX = 6e7;
int FREQ[MAX + int(1e6)];

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int ans = n - 1;
  { // d = 0
    map<int, int> freq;
    for (int i = 0; i < n; i++) freq[a[i]]++;
    for (auto [i, j] : freq) ans  = min(ans, n - j);
  }

  for (int r = 0; r < 2; r++) {
    for (int d = 1; d <= 300; d++) {
      // x, x + 
      for (int i = 0; i < n; i++) {
        // a[i] - i * d
        // 
        FREQ[a[i] - i * d + MAX]++;
      }
      for (int i = 0; i < n; i++) {
        auto &f = FREQ[a[i] - i * d + MAX];
        ans = min(ans, n - f);
        f = 0;
      }
    }
    reverse(begin(a), end(a));
  }

  const int BL = 700;
  for (int b = 0; b < n; b += BL / 2) {
    for (int i = b; i < n && i < b + BL; i++) {
      for (int j = b; j < n && j < b + BL; j++) {
        if (i == j) {
          continue;
        }
        int up = a[i] - a[j];
        int dn = i - j;
        if (up / dn * dn != up) {
          continue;
        }
        FREQ[up / dn + MAX / 2] += 1;          
      }
      for (int j = b; j < n && j < b + BL; j++) {
        if (i == j) {
          continue;
        }
        int up = a[i] - a[j];
        int dn = i - j;
        if (up / dn * dn != up) {
          continue;
        }
        auto &f = FREQ[up / dn + MAX / 2];
        ans = min(ans, n - 1 - f);
        f = 0;
      }
      

      // iterate through [b, b + 500]
      // solve tthis in n^2
      // fix a node i
      // 
    }
  }
  cout << ans << '\n';

}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}