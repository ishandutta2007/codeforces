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

class SegTree {
 public:
  int sz;
  vector<pair<int, int>> tree;

  SegTree(int sz) : sz(sz), tree(2 * sz, pair(-1, -1)) {}

  void Modify(int p, int x) {
    tree[p + sz] = {x, p};
    p += sz;
    for (p /= 2; p > 0; p /= 2) {
      tree[p] = max(tree[p * 2], tree[p * 2 + 1]);
    }
  }

  pair<int, int> Query(int l, int r) {
    pair<int, int> res = {-1, -1};
    for (l += sz, r += sz + 1; l < r; l /= 2, r /= 2) {
      if (l & 1) res = max(res, tree[l++]);
      if (r & 1) res = max(res, tree[--r]);
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, K;
  cin >> N >> K;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  const auto MinimumDistinct = [&]() -> int {
    vector<int> arr1(N + 1);
    for (int i = 0; i < N; i++) {
      arr1[i + 1] = A[i];
    }
    vector<int> pos(N + 1);
    for (int i = 0; i <= N; i++) {
      pos[arr1[i]] = i;
    }
    int k = 1;
    for (int i = N; i > 1; i--) {
      if (pos[arr1[i] + 1] <= pos[arr1[i - 1] + 1]) {
        k += 1;
      }
    }
    return k;
  };

  int X = MinimumDistinct();
  const int MAX = 2e5 + 5;

  vector<Mint> fact(MAX);
  fact[0] = 1;
  for (int i = 1; i < MAX; i++) {
    fact[i] = i * fact[i - 1];
  }

  const auto C = [&](int n, int k) {
    if (k < 0 || k > n) return Mint(0);
    return fact[n] / fact[k] / fact[n - k];
  };

  Mint ans = 0;
  int len = N - X;
  for (int i = 0; i <= len; i++) {
    ans += C(len, i) * C(K, X + i);
  }

  // cout << X << '\n';
  cout << ans << '\n';
  return 0;

  vector<int> P(N);
  vector<Mint> cnt(K + 1);
  const auto Dfs = [&](const auto &self, int u) {
    if (u == N) {
      vector<pair<vector<int>, int>> strings;
      for (int i = 0; i < N; i++) {
        vector<int> s;
        for (int j = i; j < N; j++) {
          s.push_back(P[j]);
        }
        s.push_back(-1);
        strings.push_back({s, i});
      }
      sort(begin(strings), end(strings));
      int ok = 1;
      for (int i = 0; i < N; i++) {
        if (strings[i].second != A[i]) {
          ok = 0;
          break;
        }
      }
      if (!ok) return;
      vector<int> diff = P;
      sort(begin(diff), end(diff));
      diff.resize(unique(begin(diff), end(diff)) - begin(diff));
      cnt[diff.size()] += 1;
      return;
    }
    for (int i = 1; i <= K; i++) {
      P[u] = i;
      self(self, u + 1);
    }
  };

  Dfs(Dfs, 0);
  for (int i = 1; i <= K; i++) {
    cout << i << ' ' << cnt[i] << '\n';
  }
  cout << accumulate(begin(cnt), end(cnt), Mint(0)) << '\n';
  return 0;
}

/*
7 7
3 2 4 1 0 5 6
1 0
2 0
3 0
4 1
5 3
6 3
7 1

5 5
2 3 1 0 4
1 0
2 0
3 1
4 2
5 1

7 7
0 1 2 3 4 5 6
1 0
2 1
3 5
4 10
5 10
6 5
7 1

7
0 1 2 3 4 5 6


5 5
2 3 1 0 4

5 5
0 2 1 3 4

5 5
0 1 2 3 4

sorted decreasing: X = 1
sorted increasing: X = 2

7 7
0 1 2 3 4 6 5

7 7
0 3 4 5 6 1 2



3 3
0 1 2
*/