#include <bits/stdc++.h>
#include <random>
#define int long long
using namespace std;

template <const int32_t MOD> struct ModInt {
  int32_t x;
  ModInt() : x(0) {}
  ModInt(long long u) : x(u % MOD) {
    x %= MOD;
    if (x < 0)
      x += MOD;
  }
  friend bool operator==(const ModInt &a, const ModInt &b) {
    return a.x == b.x;
  }
  friend bool operator!=(const ModInt &a, const ModInt &b) {
    return a.x != b.x;
  }
  friend bool operator<(const ModInt &a, const ModInt &b) { return a.x < b.x; }
  friend bool operator>(const ModInt &a, const ModInt &b) { return a.x > b.x; }
  friend bool operator<=(const ModInt &a, const ModInt &b) {
    return a.x <= b.x;
  }
  friend bool operator>=(const ModInt &a, const ModInt &b) {
    return a.x >= b.x;
  }
  static ModInt sign(long long k) {
    return ((k & 1) ? ModInt(MOD - 1) : ModInt(1));
  }

  ModInt &operator+=(const ModInt &m) {
    x += m.x;
    if (x >= MOD)
      x -= MOD;
    return *this;
  }
  ModInt &operator-=(const ModInt &m) {
    x -= m.x;
    if (x < 0LL)
      x += MOD;
    return *this;
  }
  ModInt &operator*=(const ModInt &m) {
    x = (1LL * x * m.x) % MOD;
    return *this;
  }

  friend ModInt operator-(const ModInt &a) {
    ModInt res(a);
    if (res.x)
      res.x = MOD - res.x;
    return res;
  }
  friend ModInt operator+(const ModInt &a, const ModInt &b) {
    return ModInt(a) += ModInt(b);
  }
  friend ModInt operator-(const ModInt &a, const ModInt &b) {
    return ModInt(a) -= ModInt(b);
  }
  friend ModInt operator*(const ModInt &a, const ModInt &b) {
    return ModInt(a) *= ModInt(b);
  }

  static long long fp(long long u, long long k) {
    long long res = 1LL;
    while (k > 0LL) {
      if (k & 1LL)
        res = (res * u) % MOD;
      u = (u * u) % MOD;
      k /= 2LL;
    }
    return res;
  }

  static constexpr int mod() { return MOD; }

  ModInt fastpow(long long k) { return ModInt(fp(x, k)); }
  ModInt inv() {
    assert(x);
    return ModInt(fp(x, MOD - 2));
  }
  ModInt &operator/=(const ModInt &m) { return *this *= ModInt(m).inv(); }
  friend ModInt operator/(const ModInt &a, const ModInt &b) {
    return ModInt(a) *= ModInt(b).inv();
  }

  friend ostream &operator<<(ostream &out, const ModInt &a) {
    return out << a.x;
  }
  friend istream &operator>>(istream &in, ModInt &a) { return in >> a.x; }
};

const int MOD = 998244353;
using Mint = ModInt<MOD>;

const int MAXN = 2e5;
Mint fact[MAXN], invFact[MAXN];

void init() {
  fact[0] = 1;
  for (int i = 1; i < MAXN; ++i)
    fact[i] = i * fact[i - 1];
  for (int i = 0; i < MAXN; ++i)
    invFact[i] = fact[i].inv();
}

Mint binom(int n, int k) {
  if (k > n or k < 0)
    return 0;
  return fact[n] * invFact[k] * invFact[n - k];
}

Mint cntSum(int nbTermes, int sommeVoulue) {
  if (sommeVoulue < 0 or nbTermes < 1)
    return 0;
  return binom(nbTermes - 1 + sommeVoulue, sommeVoulue);
}

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int nb1 = 0;
  for (auto v : s)
    nb1 += v == '1';
  bool ok = false;
  for (int i = 0; i < n - 1; ++i)
    ok |= (s[i] == '1') and (s[i + 1] == '1');

  int blocsImpairs = 0;

  int cur = 0;
  while (cur < n) {
    if (s[cur] == '0') {
      ++cur;
      continue;
    }
    int nb = 1;
    while (cur + nb < n and s[cur + nb] == '1')
      ++nb;
    if (nb % 2)
      blocsImpairs++;
    cur += nb;
  }
  if (!ok) {
    cout << 1 << '\n';
    return;
  }

  Mint ret = 0;
  for (int blocsPairs = 1; blocsPairs * 2 + blocsImpairs <= nb1; ++blocsPairs) {
    int espace = n - blocsImpairs;
    int aPlacer = nb1 - blocsImpairs;
    ret += cntSum(blocsPairs + 1, espace - aPlacer - blocsPairs + 1) *
           cntSum(blocsPairs, aPlacer / 2 - blocsPairs);
  }

  cout << ret << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  init();

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}