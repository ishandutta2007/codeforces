#include <bits/stdc++.h>
using namespace std;

using lint = long long;
#define int lint

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

void Main() {
  int n;
  cin >> n;
  // ai / aj = x/y
  // ai y = aj x
  // #define Mint double

  vector<int> isPrime(n + 1, 1);
  vector<int> smallPrime(n + 1);
  for (int i = 1; i <= n; i++) smallPrime[i] = i;
  isPrime[1] = 0;
  for (int i = 2; i <= n; i++) {
    if (isPrime[i]) {
      for (int j = i + i; j <= n; j += i) {
        isPrime[j] = 0;
        smallPrime[j] = min(smallPrime[j], i);
      }
    }
  }

  map<int, int> all;
  map<int, int> worst;
  const auto Modify = [&](int x, int sgn) {
    int p = x;
    while (p > 1) {
      int d = smallPrime[p];
      all[d] += sgn;
      worst[d] = min(worst[d], all[d]);
      p /= d;
    }
  };
  vector<vector<int>> crit(n);
  vector<vector<array<int, 3>>> adj(n);
  for (int q = 1; q < n; q++) {
    int i, j, x, y;
    cin >> i >> j >> x >> y;
    i--, j--;
    int g = gcd(x, y);
    x /= g;
    y /= g;
    Modify(x, 1);
    Modify(y, 1);

    adj[i].push_back({j, y, x});
    adj[j].push_back({i, x, y});
  }
  worst = all;
  // minimum r such that:
  // ai = x/y aj
  // ai = aj / (y/x)
  // aj * x is divisible by y
  // ai * y is divisible by x
  // if x,y has no common factors
  // then

  // ai y = aj x
  // want to:
  // find
  // find smallest lcm

  // ry/x
  // r * y / x

  Mint rat = 0;
  vector<Mint> st;
  const auto Dfs = [&](const auto &self, int u, int p, Mint d) -> void {
    rat += d;
    // d * x is divisible by lcm(crit[u])
    // d = a/b for some a, b
    // ax/b is divisible by lcm
    // ax is divisible by lcm * b
    // let g = gcd(a, lcm * b)
    // x = a * lcm * b / g
    //
    // st.emplace_back(d);
    // cout << u << ' ' << all * d << '\n';
    for (auto [v, x, y] : adj[u]) {
      if (v != p) {
        Modify(x, 1);
        Modify(y, -1);
        self(self, v, u, d * Mint(x) / Mint(y));
        Modify(y, 1);
        Modify(x, -1);
      }
    }
  };

  Mint mul = 1;
  Dfs(Dfs, 0, -1, 1);
  for (auto [u, v] : worst) {
    int p = all[u] - v;
    while (p > 0) {
      p--;
      mul *= u;
    }
    // cout << u << ' ' << all[u] - v << '\n';
  }
  cout << mul * rat << '\n';
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}