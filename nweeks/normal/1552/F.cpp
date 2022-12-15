#include <bits/stdc++.h>
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

template <class T> class Fenwick {
public:
  int lim;
  vector<T> bit;

  Fenwick(int n) : lim(n + 1), bit(lim) {}

  void upd(int pos, T val) {
    for (pos++; pos < lim; pos += pos & -pos)
      bit[pos] += val;
  }

  T sum(int r) { // < r
    T ret = 0;
    for (; r; r -= r & -r)
      ret += bit[r];
    return ret;
  }

  T sum(int l, int r) { // [l, r)
    return sum(r) - sum(l);
  }
};

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbPortails;
  cin >> nbPortails;

  vector<int> depart(nbPortails), arrive(nbPortails), state(nbPortails);
  vector<Mint> cost(nbPortails);

  for (int i = 0; i < nbPortails; ++i)
    cin >> depart[i] >> arrive[i] >> state[i];
  Fenwick<Mint> fen(nbPortails);
  for (int iPortail = 0; iPortail < nbPortails; ++iPortail) {
    int fst = lower_bound(depart.begin(), depart.end(), arrive[iPortail]) -
              depart.begin();

    cost[iPortail] =
        depart[iPortail] - arrive[iPortail] + fen.sum(fst, iPortail);
    fen.upd(iPortail, cost[iPortail]);
  }

  Mint ret = depart.back() + 1;
  for (int i = 0; i < nbPortails; ++i)
    if (state[i])
      ret += cost[i];
  cout << ret << endl;
}