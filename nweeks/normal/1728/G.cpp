#include <bits/stdc++.h>
#define int long long
using namespace std;

template <const int32_t MOD> struct ModInt {
  int32_t x;
  ModInt() : x(0) {}
  ModInt(long long u) : x(u % MOD) {
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

// const int MOD = 1e9 + 7;
const int MOD = 998244353;
using Mint = ModInt<MOD>;

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int d, nbLanternes, nbInterets;
  cin >> d >> nbLanternes >> nbInterets;
  vector<int> posLanternes(nbLanternes);
  for (int &pos : posLanternes)
    cin >> pos;
  vector<int> posInterets(nbInterets);
  for (int &pos : posInterets)
    cin >> pos;

  vector<Mint> ways((1 << nbInterets), 1);
  for (int iLanterne = 0; iLanterne < nbLanternes; ++iLanterne) {
    vector<int> order(nbInterets);
    iota(order.begin(), order.end(), 0LL);
    int pos = posLanternes[iLanterne];
    sort(order.begin(), order.end(), [&](int i, int j) {
      return pair(abs(pos - posInterets[i]), i) <
             pair(abs(pos - posInterets[j]), j);
    });
    int curMsk = 0;
    for (int i = nbInterets - 1; i >= 0; --i) {
      curMsk |= 1 << order[i];
      ways[curMsk] *= abs(posInterets[order[i]] - pos);
      ways[curMsk ^ (1 << order[i])] /= abs(posInterets[order[i]] - pos);
    }
  }
  for (int bit = 0; bit < nbInterets; ++bit)
    for (int msk = 0; msk < (1 << nbInterets); ++msk)
      if (msk & (1 << bit))
        ways[msk ^ (1 << bit)] *= ways[msk];

  ways[0] = 0;
  for (int msk = 1; msk < (1 << nbInterets); ++msk)
    if (__builtin_popcount(msk) % 2)
      ways[msk] *= -1;
  for (int bit = 0; bit < nbInterets; ++bit)
    for (int msk = 0; msk < (1 << nbInterets); ++msk)
      if (msk & (1 << bit))
        ways[msk] += ways[msk ^ (1 << bit)];
  int nbRequetes;
  cin >> nbRequetes;
  for (int iRequete = 0; iRequete < nbRequetes; ++iRequete) {
    int pos;
    cin >> pos;
    vector<int> order(nbInterets);
    iota(order.begin(), order.end(), 0LL);
    sort(order.begin(), order.end(), [&](int i, int j) {
      return pair(abs(pos - posInterets[i]), i) <
             pair(abs(pos - posInterets[j]), j);
    });
    Mint sol = Mint(d + 1).fastpow(nbLanternes + 1);
    int curMsk = 0;
    for (int i = nbInterets - 1; i >= 0; --i) {
      curMsk |= 1 << order[i];
      int diff = abs(pos - posInterets[order[i]]);
      sol += (ways[curMsk] - ways[curMsk ^ (1 << order[i])]) * diff;
    }
    cout << sol << '\n';
  }
}