#include <bits/stdc++.h>
using namespace std;

template <int MOD>
class ModInt {
 public:
  int v;

  ModInt() : v(0) {}
  ModInt(long long _v) {
    v = int((-MOD < _v && _v < MOD) ? (_v) : (_v % MOD));
    if (v < 0) v += MOD;
  }

  friend bool operator==(const ModInt &a, const ModInt &b) { return a.v == b.v; }
  friend bool operator!=(const ModInt &a, const ModInt &b) { return a.v != b.v; }
  friend bool operator<(const ModInt &a, const ModInt &b) { return a.v < b.v; }
  friend bool operator<=(const ModInt &a, const ModInt &b) { return a.v <= b.v; }
  friend bool operator>(const ModInt &a, const ModInt &b) { return a.v > b.v; }
  friend bool operator>=(const ModInt &a, const ModInt &b) { return a.v >= b.v; }

  ModInt &operator+=(const ModInt &a) {
    if ((v += a.v) >= MOD) v -= MOD;
    return *this;
  }
  ModInt &operator-=(const ModInt &a) {
    if ((v -= a.v) < 0) v += MOD;
    return *this;
  }
  ModInt &operator*=(const ModInt &a) {
    v = 1ll * v * a.v % MOD;
    return *this;
  }
  ModInt &operator/=(const ModInt &a) {
    return (*this) *= inverse(a);
  }

  friend ModInt pow(ModInt a, long long x) {
    ModInt res = 1;
    assert(x >= 0);
    for (; x; x /= 2, a *= a)
      if (x & 1) res *= a;
    return res;
  }
  friend ModInt inverse(ModInt a) {
    assert(a.v != 0);
    return pow(a, MOD - 2);
  }

  ModInt operator+() const { return ModInt(v); }
  ModInt operator-() const { return ModInt(-v); }
  ModInt operator++() const { return *this += 1; }
  ModInt operator--() const { return *this -= 1; }

  friend ModInt operator+(ModInt a, const ModInt &b) { return a += b; }
  friend ModInt operator-(ModInt a, const ModInt &b) { return a -= b; }
  friend ModInt operator*(ModInt a, const ModInt &b) { return a *= b; }
  friend ModInt operator/(ModInt a, const ModInt &b) { return a /= b; }

  friend istream &operator>>(istream &is, ModInt &v) {
    is >> v.v;
    return is;
  }
  friend ostream &operator<<(ostream &os, const ModInt &v) {
    os << v.v;
    return os;
  }
};

const int MOD = 998244353;
using Mint = ModInt<MOD>;

using lint = long long;

vector<Mint> fact, inv;

class SegTree {
 public:
  int sz;
  vector<Mint> tree;
  SegTree(int sz) : sz(sz), tree(2 * sz) {}
  void Update(int p, int x) {
    p += sz;
    tree[p] = x;
    for (p /= 2; p > 0; p /= 2) tree[p] = tree[p * 2] + tree[p * 2 + 1];
  }
  Mint Query(int l, int r) {
    Mint z = 0;
    for (l += sz, r += sz + 1; l < r; l /= 2, r /= 2) {
      if (l & 1) z += tree[l++];
      if (r & 1) z += tree[--r];
    }
    return z;
  }
};

void Main() {
  int n, m;
  cin >> n >> m;
  vector<int> s(n), t(m);
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < m; i++) cin >> t[i];

  // while (n < m) s.emplace_back(0), n++;
  // while (n > m) t.emplace_back(0), m++;

  const int MAX = 2e5 +5;

  fact.resize(n + 1);
  fact[0] = 1;
  for (int i = 1; i <= n; i++) fact[i] = i * fact[i - 1];
  inv.resize(n + 1);
  for (int i = 0; i <= n; i++) inv[i] = Mint(1) / fact[i];

  Mint ans = 0;
  SegTree seg(MAX);
  vector<int> cnt(MAX);
  for (int i = 0; i < n; i++) {
    cnt[s[i]] += 1;
  }
  for (int i = 0; i < MAX; i++) {
    seg.Update(i, cnt[i]);
  }
  Mint all = fact[n];
  for (int i = 0; i < MAX; i++) all *= inv[cnt[i]];

  ans = 0;
  for (int i = 0; i < m && i < n; i++) {
    // Count number of strings which start with one of "cntlower" chars
    // Number of ways = all!/each!
    // At each stage, only sqrt different values of each
    // Keep a segtree, each node keeps each!/(each-1)!, find sum of this

    all /= Mint(n - i);
    ans += seg.Query(0, t[i] - 1) * all;
    // cout << seg.Query(t[i] + 1, MAX-1) * all << '\n';
    if (cnt[t[i]] == 0) break;

    all *= fact[cnt[t[i]]];
    cnt[t[i]] -= 1;
    seg.Update(t[i], cnt[t[i]]);
    all *= inv[cnt[t[i]]];
    if (i == n - 1 && n < m) ans += 1;
  }

  cout << ans << '\n';
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