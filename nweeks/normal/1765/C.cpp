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

const int MOD = 998244353;
using Mint = ModInt<MOD>;

const int root = 62;
void ntt(vector<Mint> &a, bool inverse = false) {
  int n = a.size(), L = 31 - __builtin_clz((int)n);
  static vector<Mint> rt(2, 1);
  for (static int k = 2, s = 2; k < n; k *= 2, s++) {
    rt.resize(n);
    Mint z[] = {1, Mint(root).fastpow(MOD >> s)};
    for (int i(k); i < 2 * k; ++i)
      rt[i] = rt[i / 2] * z[i & 1];
  }
  if (inverse)
    reverse(a.begin() + 1, a.end());
  vector<int> rev(n);
  for (int i = 0; i < n; ++i) {
    rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
  }
  for (int i = 0; i < n; ++i) {
    if (i < rev[i])
      swap(a[i], a[rev[i]]);
  }
  for (int k(1); k < n; k *= 2)
    for (int i(0); i < n; i += 2 * k)
      for (int j = 0; j < k; ++j) {
        Mint z = rt[j + k] * a[i + j + k], &ai = a[i + j];
        a[i + j + k] = ai - z + (z > ai ? MOD : 0);
        ai += (ai + z >= MOD ? z - MOD : z);
      }
  if (inverse) {
    Mint invN = Mint(n).inv();
    for (int i = 0; i < n; ++i)
      a[i] = a[i] * invN;
  }
}

vector<Mint> conv(const vector<Mint> &a, const vector<Mint> &b) {
  if (a.empty() or b.empty())
    return {};
  int s = a.size() + b.size() - 1, B = 32 - __builtin_clz((int)s), n = 1 << B;
  Mint inverse = Mint(n).inv();
  vector<Mint> L(a), R(b), out(n);
  L.resize(n), R.resize(n);
  ntt(L), ntt(R);
  for (int i = 0; i < n; ++i) {
    out[-i & (n - i)] = L[i] * R[i] * inverse;
  }
  ntt(out);
  return {out.begin(), out.begin() + s};
}

const int MAXN = 1e5;
Mint fact[MAXN], invFact[MAXN];

vector<vector<Mint>> polynomials[4];

void initFact() {
  fact[0] = 1;
  for (int i = 1; i < MAXN; ++i)
    fact[i] = i * fact[i - 1];
  invFact[MAXN - 1] = fact[MAXN - 1].inv();
  for (int i = MAXN - 1; i; --i)
    invFact[i - 1] = invFact[i] * i;
}

Mint binom(int n, int k) {
  if (k < 0 or k > n)
    return 0;
  return fact[n] * invFact[k] * invFact[n - k];
}

int bySuit;

Mint waysSum(int cnt, int lowerBound, int sum) {
  if (sum >= (int)polynomials[cnt][lowerBound].size())
    return 0;
  return polynomials[cnt][lowerBound][sum];
  if (cnt == 0)
    return sum == 0;
  if (cnt == 1) {
    assert(sum >= lowerBound);
    assert(binom(bySuit, sum) == polynomials[1][lowerBound][sum]);
    return binom(bySuit, sum);
  }
  if (cnt == 2) {
    Mint ret = 0;
    for (int v1 = lowerBound; v1 <= sum - lowerBound; ++v1) {
      int v2 = sum - v1;
      if (v2 < lowerBound)
        continue;
      ret += binom(bySuit, v1) * binom(bySuit, v2);
    }
    return ret;
  }
  if (cnt == 3) {
    Mint ret = 0;
    for (int v1 = lowerBound; v1 <= sum - 2 * lowerBound; ++v1)
      for (int v2 = lowerBound; v1 + v2 <= sum - lowerBound; ++v2) {
        int v3 = sum - v1 - v2;
        if (v3 < lowerBound)
          continue;
        ret += binom(bySuit, v1) * binom(bySuit, v2) * binom(bySuit, v3);
      }
    return ret;
  }
  assert(false);
}

Mint cntWays(int cardsKnown) {
  Mint ret = 0;
  for (int minVal = 0; minVal * 4 <= cardsKnown; ++minVal)
    for (int occ = 1; occ <= 4; ++occ) {
      if (minVal * occ + (4 - occ) * (minVal + 1) > cardsKnown)
        continue;
      Mint ways = waysSum(4 - occ, minVal + 1, cardsKnown - occ * minVal);
      ways *= binom(4, occ);
      for (int i = 1; i < occ; ++i)
        ways *= binom(bySuit, minVal);
      ways *= binom(bySuit, minVal + 1) * (minVal + 1);
      ways *= fact[4 * bySuit - cardsKnown - 1] * fact[cardsKnown];
      ret += ways;
    }
  return ret;
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  initFact();
  int k;
  cin >> bySuit >> k;

  for (int cnt = 0; cnt < 4; ++cnt)
    polynomials[cnt].resize(bySuit + 1);

  for (int lo = 1; lo <= bySuit; ++lo) {
    vector<Mint> pol(bySuit + 1);
    for (int i = lo; i <= bySuit; ++i)
      pol[i] = binom(bySuit, i);
    polynomials[0][lo] = {1};
    auto p = conv(pol, polynomials[0][lo]);
    for (int cnt = 1; cnt <= 3; ++cnt)
      polynomials[cnt][lo] = conv(polynomials[cnt - 1][lo], pol);
  }

  Mint ret = 0;
  for (int i = 0; i < 4 * bySuit; ++i) {
    Mint x = cntWays(min(k, i));
    ret += x;
  }
  cout << ret * invFact[4 * bySuit] << endl;
}