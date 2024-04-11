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

class Fenwick {
 public:
  int sz;
  vector<int> tree;
  Fenwick(int sz) : sz(sz), tree(sz) {}
  void Modify(int p, int x) {
    for (int i = p; i < sz; i |= i + 1) {
      tree[i] += x;
    }
  }
  int Query(int p) {
    int z = 0;
    for (int i = p; i > 0; i &= i - 1) {
      z += tree[i - 1];
    }
    return z;
  }
};

void Main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N * M);
  map<int, vector<int>> mp;
  for (int i = 0; i < N * M; i++) {
    cin >> A[i];    
    mp[A[i]].emplace_back(i);
  }
  Fenwick F(N * M);
  lint ans = 0;
  int cnt = 0;
  vector<vector<int>> B(N, vector<int>(M));
  for (auto [i, vec] : mp) {
    reverse(begin(vec), end(vec));
    for (auto j : vec) {
      B[cnt / M][cnt % M] = j;
      cnt++;
    }
  }
  for (int r = 0; r < N; r++) {
    for (int i = 0; i < M; i++) {
      ans += F.Query(B[r][i]);
      F.Modify(B[r][i], 1);
    }
    for (int i = 0; i < M; i++) {
      F.Modify(B[r][i], -1);
    }    
  }
  cout << ans << '\n';
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