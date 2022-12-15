#include <bits/stdc++.h>
#include <ios>
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

// const int MOD = 1e9 + 7;
const int MOD = 998244353;
using Mint = ModInt<MOD>;

const int MAXN = 503;

Mint dp[MAXN][MAXN]; // dp[nbPris][nbPlusPetits] : nb facons d'en avoir
                     // nbRestants aprs avoir regard les
                     // Ceux egaux avant : <, ceux gaux aprs : >=

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbOps;
  cin >> nbOps;
  vector<int> ops(nbOps);
  for (int i = 0; i < nbOps; ++i) {
    char c;
    cin >> c;
    if (c == '-')
      ops[i] = 0;
    else {
      cin >> ops[i];
    }
  }
  Mint ret = 0;
  for (int iVeut = 0; iVeut < nbOps; ++iVeut) {
    if (!ops[iVeut])
      continue;
    dp[0][0] = 1;

    for (int iOp = 0; iOp < nbOps; ++iOp) {
      for (int nbPlusPetits = 0; nbPlusPetits <= nbOps; ++nbPlusPetits) {
        Mint &x = dp[iOp + 1][nbPlusPetits];
        x = 0;
        if (iOp >= iVeut and !nbPlusPetits)
          continue;
        if (iOp != iVeut)
          x = dp[iOp][nbPlusPetits];
        if (ops[iOp]) {
          if (iOp <= iVeut) {
            if (ops[iVeut] >= ops[iOp] and nbPlusPetits)
              x += dp[iOp][nbPlusPetits - 1];
            else if (ops[iOp] > ops[iVeut])
              x += dp[iOp][nbPlusPetits];
          } else {
            if (ops[iVeut] > ops[iOp] and nbPlusPetits)
              x += dp[iOp][nbPlusPetits - 1];
            else if (ops[iOp] >= ops[iVeut])
              x += dp[iOp][nbPlusPetits];
          }
        } else {
          x += dp[iOp][nbPlusPetits + 1];
          if (!nbPlusPetits)
            x += dp[iOp][0];
        }
        // if (iVeut == 1) {
        // cout << 1 + iOp << ' ' << nbPlusPetits << ' ' << x << endl;
        ////}
      }
    }
    Mint nbFacons = 0;
    for (int nbPlusPetits = 1; nbPlusPetits <= nbOps; ++nbPlusPetits) {
      nbFacons += dp[nbOps][nbPlusPetits];
    }
    ret += nbFacons * ops[iVeut];
  }
  cout << ret << endl;
  ;
}