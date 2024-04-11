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

void Main() {
  int N, M;
  cin >> N >> M;
  vector<string> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  vector<vector<int>> sum(N, vector<int>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      sum[i][j] = A[i][j] == '0';
      if (i) sum[i][j] += sum[i - 1][j];
      if (j) sum[i][j] += sum[i][j - 1];
      if (i && j) sum[i][j] -= sum[i - 1][j - 1];
    }
  }
  const auto Sum = [&](int i1, int i2, int j1, int j2, bool inv = false) {
    if (j2 < 0) return 0;
    int ans = sum[i2][j2];
    if (i1) ans -= sum[i1 - 1][j2];
    if (j1) ans -= sum[i2][j1 - 1];
    if (i1 && j1) ans += sum[i1 - 1][j1 - 1];
    if (inv) {
      return (i2 - i1 + 1) * (j2 - j1 + 1) - ans;
    }
    return ans;
  };
  const auto Calc = [&](int r1, int r2, int c) {
    int fl = Sum(r1 + 1, r2 - 1, c, c);
    int uplft = Sum(r1, r1, 0, c);
    int dnlft = Sum(r2, r2, 0, c);
    int sublft = Sum(r1 + 1, r2 - 1, 0, c, 1);
    int uprgt = Sum(r1, r1, 0, c - 1);
    int dnrgt = Sum(r2, r2, 0, c - 1);
    int subrgt = Sum(r1 + 1, r2 - 1, 0, c - 1, 1);
    return array<int, 3>({fl, uplft + dnlft + sublft, uprgt + dnrgt + subrgt});
  };
  int ans = 1e9;
  for (int r1 = 0; r1 < N; r1++) {
    for (int r2 = r1 + 4; r2 < N; r2++) {
      int best = 1e9;
      for (int c = 0; c < M; c++) {
        if (c - 3 >= 0) {
          auto [fl, lft, rgt] = Calc(r1, r2, c - 3);
          best = min(best, fl - lft);
        }
        auto [fl, lft, rgt] = Calc(r1, r2, c);
        ans = min(ans, fl + rgt + best);
      }
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