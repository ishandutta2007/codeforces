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

const int MAXN = 1e5;
vector<int> adj[MAXN];
int sz[MAXN];
int want;

void dfs(int u, int p) {
  sz[u] = 1;
  for (int v : adj[u])
    if (v != p) {
      dfs(v, u);
      sz[u] += sz[v];
    }
}

bool possible(int u, int p) {
  vector<Mint> ways;

  bool needPar = (want + sz[u] - 1) % want;
  int deg = needPar and u;

  for (int v : adj[u])
    if (v != p) {
      if (!possible(v, u))
        return false;
      int r = (sz[v] - 1) % want;
      if (r and r != want - 1) {
        return false;
      }
      if (!r)
        deg++;
    }
  // cout << u + 1 << ' ' << sz[u] << ' ' << deg << ' ' << needPar << endl;
  if (deg % want) {
    return false;
  }
  return true;
}

Mint cntWays(int u, int p) {
  vector<Mint> waysSon;
  int deg = 0;
  Mint prd = 1;
  for (int v : adj[u])
    if (v != p) {
      prd *= cntWays(v, u);
      deg++;
    }
  return prd * Mint(2).fastpow(deg);
}

void solve() {
  int nbSommets;
  cin >> nbSommets;
  for (int i = 0; i < nbSommets; ++i)
    adj[i].clear();
  for (int i = 1; i < nbSommets; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0, 0);

  int maxV = nbSommets;
  vector<Mint> sol(maxV + 1);
  for (int k = 2; k <= maxV; ++k)
    if ((nbSommets - 1) % k == 0) {
      want = k;
      if (possible(0, 0))
        sol[k] = 1;
    }
  sol[1] = cntWays(0, 0);
  for (int k = maxV; k >= 1; --k)
    for (int i = 2 * k; i <= maxV; i += k)
      sol[k] -= sol[i];
  for (int k = 1; k < maxV; ++k)
    cout << sol[k] << ' ';
  cout << 0 << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--)
    solve();
}