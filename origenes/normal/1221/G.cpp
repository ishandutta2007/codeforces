#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 45;

int n, m;
int par[maxn], sz[maxn];
ll G[maxn];

int Find(int x) {
  return par[x] == x ? x : par[x] = Find(par[x]);
}

void Union(int u, int v) {
  u = Find(u), v = Find(v);
  if (u == v) return;
  par[u] = v;
  sz[v] += sz[u];
}

bool good[1 << 20];
int maximal[1 << 20], f[1 << 20];

ll ind_set() {
  int lef = n / 2, rig = n - n / 2;
  REP(mask, 1 << lef) {
    bool ok = true;
    ll allowed = ((1LL << rig) - 1) << lef;
    REP(i, lef) if (mask & (1 << i)) {
      if (G[i] & ll(mask)) {
        ok = false;
        break;
      }
      allowed &= ~G[i];
    }
    if (!ok) continue;
    good[mask] = true;
    maximal[mask] = allowed >> lef;
  }
  REP(mask, 1 << rig) {
    bool ok = true;
    ll actual = ll(mask) << lef;
    FOR(i, lef, n - 1) if (actual & (1LL << i)) {
      if (G[i] & actual) {
        ok = false;
        break;
      }
    }
    f[mask] = ok;
  }
  REP(i, rig) REP(mask, 1 << rig) if (mask & (1 << i)) f[mask] += f[mask ^ (1 << i)];
  ll ret = 0;
  REP(mask, 1 << lef) if (good[mask]) ret += f[maximal[mask]];
  return ret;
}

int colour[maxn];

bool dfs(int u, int c) {
  colour[u] = c;
  REP(v, n) if (G[u] & (1LL << v)) {
    if (colour[v] == colour[u]) return false;
    if (colour[v] == -1 && !dfs(v, 1 - c)) return false;
  }
  return true;
}

int main() {
  scanf("%d%d", &n, &m);
  if (n == 1) {
    puts("0");
    return 0;
  }
  iota(par, par + n, 0);
  fill(sz, sz + n, 1);
  REP(i, m) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    G[u] |= 1LL << v;
    G[v] |= 1LL << u;
    Union(u, v);
  }
  ll ans = 1LL << n;
  ans -= 2 * ind_set();
  int cc = 0, iso = 0;
  bool bipartite = true;
  reset(colour, -1);
  REP(i, n) if (Find(i) == i) {
    cc++;
    if (sz[i] == 1) iso++;
    else bipartite &= dfs(i, 0);
  }
  ans -= 1LL << cc;
  ans += 1LL << iso + 1;
  if (bipartite) ans += 1LL << cc;
  if (!m) ans -= 1LL << n;
  printf("%lld", ans);
}