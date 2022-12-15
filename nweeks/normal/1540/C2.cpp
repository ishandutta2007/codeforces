#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://github.com/nweeks1/UltiSnips
template <const int32_t MOD> struct ModInt {
  int32_t x;
  ModInt() : x(0) {}
  ModInt(long long u) : x(u) {
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

const int MOD = 1e9 + 7;
using Mint = ModInt<MOD>;

const int MAXSUM = 1e4 + 1;
const int MAXN = 101;

Mint ways[MAXN][MAXSUM];
Mint partialWays[MAXN][MAXSUM];

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> c(n);
  vector<int> b(n - 1);
  for (int i = 0; i < n; ++i)
    cin >> c[i];
  for (int i = 0; i < n - 1; ++i)
    cin >> b[i];
  vector<int> partialB(n);
  for (int k0 = 0; k0 < n; ++k0)
    for (int i = 0; i < k0; ++i)
      partialB[k0] += (k0 - i) * b[i];

  auto calcWay = [&](int x) {
    ways[0][0] = 1;
    for (int i = 0; i < MAXSUM; ++i)
      partialWays[0][i] = 1;
    for (int nbPris = 1; nbPris <= n; ++nbPris)
      for (int curSum = 0; curSum < MAXSUM; ++curSum) {
        if (curSum)
          partialWays[nbPris][curSum] = partialWays[nbPris][curSum - 1];
        else
          partialWays[nbPris][0] = 0;
        if (curSum < nbPris * x + partialB[nbPris - 1])
          continue;
        int lo = curSum - min(c[nbPris - 1], curSum), up = curSum;
        ways[nbPris][curSum] = partialWays[nbPris - 1][up] -
                               (lo ? partialWays[nbPris - 1][lo - 1] : 0);
        partialWays[nbPris][curSum] += ways[nbPris][curSum];
      }
    return partialWays[n][MAXSUM - 1];
  };

  int lo = 1e18, up = 1e18;
  for (int k = 0; k < n; ++k) {
    lo = min(lo, (int)ceil(-partialB[k] / double(k + 1)));
    up = min(up, ((1 + k) * 100 - partialB[k]) / (k + 1));
  }

  // cout << lo << ' ' << up << endl;
  map<int, Mint> sol;
  for (int x = lo; x <= up; ++x)
    sol[x] = calcWay(x);

  int q;
  Mint totWays = 1;
  for (int i = 0; i < n; ++i)
    totWays *= c[i] + 1;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int x;
    cin >> x;
    if (x < lo)
      cout << totWays << '\n';
    else if (x > up)
      cout << 0 << '\n';
    else
      cout << sol[x] << '\n';
  }
}