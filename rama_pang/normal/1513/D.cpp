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
  int n, p;
  cin >> n >> p;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> ord(n);
  iota(begin(ord), end(ord), 0);
  sort(begin(ord), end(ord), [&](int i, int j) { return a[i] < a[j]; });

  vector<int> seg(2 * n);
  for (int i = 0; i < n; i++) {
    seg[i + n] = a[i];
  }
  for (int i = n - 1; i > 0; i--) {
    seg[i] = __gcd(seg[i * 2], seg[i * 2 + 1]);
  }
  const auto Query = [&](int l, int r) {
    int g = a[l];
    for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
      if (l & 1) g = __gcd(g, seg[l++]);
      if (r & 1) g = __gcd(g, seg[--r]);
    }
    return g;
  };

  lint ans = 0;
  set<pair<int, int>> s;
  for (int i = 0; i < n; i++) s.emplace(i, i);

  const auto Add = [&](int l, int r, int cost) {
    auto it = prev(s.lower_bound({l + 1, -1}));
    int lo = it->first;
    int hi = it->second;
    int cnt = 0;
    while (it != end(s) && it->first <= r) {
      cnt += 1;
      hi = max(hi, it->second);
      it = s.erase(it);
    }
    s.emplace(lo, hi);
    ans += 1ll * (cnt - 1) * cost;
  };
  
  for (auto i : ord) {
    if (a[i] >= p) continue;
    int l, r;
    {
      int lo = 0, hi = i;
      while (lo < hi) {
        int md = (lo + hi) / 2;
        if (Query(md, i) == a[i]) {
          hi = md;
        } else {
          lo = md + 1;
        }
      }
      l = lo;
    }
    {
      int lo = i, hi = n - 1;
      while (lo < hi) {
        int md = (lo + hi + 1) / 2;
        if (Query(i, md) == a[i]) {
          lo = md;
        } else {
          hi = md - 1;
        }
      }
      r = lo;
    }
    Add(l, r, a[i]);
  }

  ans += 1ll * int(s.size() - 1) * p;

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