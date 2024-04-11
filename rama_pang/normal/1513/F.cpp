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

class SegTree {
 public:
  int sz;
  vector<int> tree;

  SegTree(int n) {
    sz = 1;
    while (sz < n) sz *= 2;
    tree.assign(2 * sz, -1);
  }

  void Update(int p, int x) {
    p += sz;
    tree[p] = max(tree[p], x);
    for (p /= 2; p > 0; p /= 2) {
      tree[p] = max(tree[p * 2], tree[p * 2 + 1]);
    }
  }

  int Query(int l, int r) {
    int res = -1;
    for (l += sz, r += sz + 1; l < r; l /= 2, r /= 2) {
      if (l & 1) res = max(res, tree[l++]);
      if (r & 1) res = max(res, tree[--r]);
    }
    return res;
  }

  int Get(int val) {
    int n = 1;
    while (n < sz) {
      if (tree[n * 2] >= val) {
        n = 2 * n;
      } else {
        n = 2 * n + 1;
        assert(tree[n] >= val);
      }
    }
    return n - sz;
  }
};

void Main() {
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  lint init_score = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> B[i];
    init_score += abs(A[i] - B[i]);
  }

  // Let swaps be (1, 2)
  //
  // Case 0: A A B B or B B A A
  // Doesn't change cost
  //
  // Case 1: A B A B
  //
  // Case 1.1: A[1] <= B[1] <= A[2] <= B[2]
  // Optimal way: don't change
  //
  // Case 1.2: A[1] <= B[2] < A[2] <= B[1]
  // Cost decrease by 2 * abs(A[2] - B[2])
  // For every index i, where B[i] < A[i]; 
  // We want to check whether an overlapping interval exist
  // Can be done via segment tree.
  //
  // Case 2: A B B A
  //
  // Case 2.1: A[1] <= B[1] <= B[2] <= A[2]
  // Optimal way: don't change
  //
  // Case 2.2: A[1] <= B[2] < B[1] <= A[2]
  // Cost decrease by 2 * abs(B[1] - B[2])
  //

  vector<lint> coords;
  for (int i = 0; i < N; i++) {
    coords.emplace_back(A[i]);
    coords.emplace_back(B[i]);
  }
  sort(begin(coords), end(coords));
  coords.resize(unique(begin(coords), end(coords)) - begin(coords));
  const auto Get = [&](int x) {
    return lower_bound(begin(coords), end(coords), x) - begin(coords);
  };

  const auto Solve1 = [&]() -> lint {
    SegTree seg(coords.size());
    vector<pair<lint, lint>> cand;
    for (int i = 0; i < N; i++) {
      if (B[i] < A[i]) {
        cand.emplace_back(B[i], A[i]);
      } else {
        seg.Update(Get(A[i]), Get(B[i]));
      }
    }
    lint ans = 0;
    for (auto [l, r] : cand) {
      if (Get(r) <= seg.Query(0, Get(l))) {
        ans = max(ans, r - l);
      }
    }
    return ans;
  };

  const auto Solve2 = [&]() -> lint {
    SegTree seg(coords.size());
    vector<pair<lint, lint>> cand;
    vector<pair<lint, lint>> upd;
    for (int i = 0; i < N; i++) {
      if (A[i] < B[i]) {
        cand.emplace_back(A[i], B[i]);
      } else if (B[i] < A[i]) {
        upd.emplace_back(B[i], A[i]);
      }
    }
    // Case 2.2: A[1] <= B[2] <= B[1] <= A[2]
    // Cost decrease by 2 * abs(B[1] - B[2])
    sort(begin(cand), end(cand));
    sort(begin(upd), end(upd));
    reverse(begin(cand), end(cand));
    lint ans = 0;
    for (auto [l, r] : cand) {
      while (!upd.empty() && l <= upd.back().first) {
        seg.Update(Get(upd.back().first), Get(upd.back().second));
        upd.pop_back();
      }
      if (seg.Query(Get(l), Get(r)) < Get(r)) continue;
      int vv = seg.Get(Get(r));
      ans = max(ans, r - coords[vv]);
    }
    return ans;
  };

  lint ans = 0;
  ans = max(ans, Solve1());
  ans = max(ans, Solve2());
  swap(A, B);
  ans = max(ans, Solve1());
  ans = max(ans, Solve2());

  cout << init_score - 2ll * ans << '\n';
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