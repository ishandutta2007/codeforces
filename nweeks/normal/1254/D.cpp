#include <bits/stdc++.h>
#define int long long
using namespace std;

template <const int32_t MOD> struct ModInt {
  int x;
  ModInt() : x(0) {}
  ModInt(long long u) : x(u%MOD) {
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

const int MAXN = 1.5e5;

Fenwick<Mint> fen(MAXN);

vector<int> adj[MAXN];
int subSize[MAXN], depth[MAXN], heavy[MAXN], root[MAXN], in[MAXN], out[MAXN],
    par[MAXN], totUpdates[MAXN], lstUpdates[MAXN];
int curTime = 0;
int nbSommets, nbRequetes;

void dfs(int u, int p) {
  subSize[u] = 1;
  par[u] = p;
  for (int v : adj[u])
    if (v != p) {
      depth[v] = depth[u] + 1;
      dfs(v, u);
      subSize[u] += subSize[v];
    }

  heavy[u] = -1;
  for (int v : adj[u])
    if (v != p and 2 * subSize[v] >= subSize[u])
      heavy[u] = v;
  if (heavy[u] != -1)
    for (int i = 0; i < (int)adj[u].size(); ++i)
      if (heavy[u] == adj[u][i]) {
        swap(adj[u][i], adj[u][0]);
        break;
      }
}

void dfs2(int u) {
  in[u] = curTime++;
  for (int v : adj[u])
    if (par[u] != v) {
      if (heavy[u] == v)
        root[v] = root[u];
      else
        root[v] = v;
      dfs2(v);
    }
  out[u] = curTime;
}

Mint query(int u) {
  // cout << "QUERY " << u + 1 << endl;
  Mint ret = fen.sum(in[u] + 1);
  // cout << ret << endl;
  while (root[u]) {
    // cout << u + 1 << ' ' << ret << endl;
    u = root[u];
    ret -= totUpdates[par[u]] * subSize[u] / Mint(nbSommets);
    u = par[u];
  }
  return ret;
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> nbSommets >> nbRequetes;

  for (int i = 1; i < nbSommets; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0, 0);
  dfs2(0);
  for (int i = 0; i < nbRequetes; ++i) {
    int t, v;
    cin >> t >> v;
    --v;
    if (t == 1) {
      int d;
      cin >> d;
      fen.upd(0, d);
      totUpdates[v] += d;
      if (heavy[v] != -1) {
        Mint toChange = -d * subSize[heavy[v]] / Mint(nbSommets);
        fen.upd(in[heavy[v]], toChange);
        fen.upd(out[heavy[v]], -toChange);
      }
      if (v) {
        Mint toChange = -d * (nbSommets - subSize[v]) / Mint(nbSommets);
        fen.upd(0, toChange);
        fen.upd(in[v], -toChange);
        fen.upd(out[v], toChange);
      }
    } else {
      cout << query(v) << '\n';
    }
  }
}