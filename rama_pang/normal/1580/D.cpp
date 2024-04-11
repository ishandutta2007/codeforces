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
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  const auto Solve = [&](const auto &self, int LFT, int RGT) -> vector<lint> {
    if (LFT > RGT) {
      return {0};
    }
    int MN = LFT;
    for (int i = LFT; i <= RGT; i++) {
      if (A[MN] > A[i]) {
        MN = i;
      }
    }
    auto lft = self(self, LFT, MN - 1);
    auto rgt = self(self, MN + 1, RGT);
    // T(N) = T(K) + T(N - K) + O(NK)
    // O(N^2)
    vector<lint> dp(RGT - LFT + 2, -1e18);
    for (int i = 0; i < int(lft.size()); i++) {
      for (int j = 0; j < int(rgt.size()); j++) {
        dp[i + j] = max(dp[i + j], lft[i] + rgt[j] - 2ll * i * j * A[MN]);
        dp[i + j + 1] = max(dp[i + j + 1], lft[i] + rgt[j] + 1ll * M * A[MN] - (2ll * (i + 1) * (j + 1) - 1) * A[MN]);
        // cout << i + j + 1 << ' ' << lft[i] + rgt[j] + 1ll * M * A[MN] - (2ll * (i + 1) * (j + 1) - 1) * A[MN] << '\n';
        // cout << dp[i + j + 1] << '\n';
      }
    }
    // cout << LFT << ' ' << RGT << ' ' << ":";
    // for (int i = 0; i <= RGT - LFT + 1; i++) cout << dp[i] << ' '; cout << '\n';
    return dp;
  };
  cout << Solve(Solve, 0, N - 1)[M] << '\n';
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