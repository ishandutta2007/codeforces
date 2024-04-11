#include <bits/stdc++.h>
#define int long long
using namespace std;

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

const int MAXN = 201;
int subSize[MAXN][MAXN];
int depth[MAXN][MAXN];
int par[MAXN][MAXN];
vector<int> adj[MAXN];
Mint dp[MAXN][MAXN]; // dp[lft][rgt] : probability that 0 is picked before len
                     // if we start at pos

void dfs(int u, int p, int root) {
  par[root][u] = p;
  subSize[root][u] = 1;
  for (auto v : adj[u])
    if (v != p) {
      depth[root][v] = 1 + depth[root][u];
      dfs(v, u, root);
      subSize[root][u] += subSize[root][v];
    }
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbSommets;
  cin >> nbSommets;
  for (int iArete = 1; iArete < nbSommets; ++iArete) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 0; i < nbSommets; ++i)
    dfs(i, i, i);

  for (int lft = 0; lft <= nbSommets; ++lft)
    for (int rgt = 0; rgt <= nbSommets; ++rgt) {
      if (!lft and !rgt)
        dp[lft][rgt] = 1 / Mint(2);
      else if (!lft)
        dp[lft][rgt] = 1 / Mint(2) * (1 + dp[lft][rgt - 1]);
      else if (!rgt)
        dp[lft][rgt] = 1 / Mint(2) * dp[lft - 1][rgt];
      else
        dp[lft][rgt] = 1 / Mint(2) * (dp[lft - 1][rgt] + dp[lft][rgt - 1]);
    }

  Mint ret = 0;
  for (int i = 0; i < nbSommets; ++i)
    for (int j = i + 1; j < nbSommets; ++j) {
      // Proba que j soit tir avant i ?
      // Soit on tire dans sous-arbre de j
      ret += subSize[i][j] / Mint(nbSommets);

      int prv = j;
      int cur = par[i][j];
      while (cur != i) {
        int nbPossibles = subSize[i][cur] - subSize[i][prv];

        int rgt = depth[i][cur] - 1;
        int lft = depth[cur][j] - 1;
        ret += nbPossibles / Mint(nbSommets) * dp[lft][rgt];
        prv = cur;
        cur = par[i][cur];
      }
    }
  cout << ret << endl;
}