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

const int maxn = 1512;
const int MOD = 998244353;

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int f[maxn][maxn], par[maxn], a[maxn][maxn], sz[maxn], cnt[maxn];
int n;

int Find(int x) {
  return par[x] == x ? x : par[x] = Find(par[x]);
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) FOR(j, 1, n) scanf("%d", &a[i][j]);
  vector<tuple<int, int, int>> edges;
  FOR(i, 1, n) FOR(j, i + 1, n) edges.eb(a[i][j], i, j);
  sort(all(edges));
  iota(par + 1, par + n + 1, 1);
  FOR(i, 1, n) f[i][1] = sz[i] = 1;
  for (auto [_, u, v] : edges) {
    u = Find(u), v = Find(v);
    if (u == v) {
      cnt[u]++;
      if (cnt[u] == sz[u] * (sz[u] - 1) / 2) f[u][1] = add(f[u][1], 1);
      continue;
    }
    vector<int> g(sz[u] + sz[v] + 1);
    FOR(i, 1, sz[u]) FOR(j, 1, sz[v]) g[i + j] = add(g[i + j], mul(f[u][i], f[v][j]));
    par[u] = v;
    cnt[v] += cnt[u] + 1;
    sz[v] += sz[u];
    FOR(i, 1, sz[v]) f[v][i] = g[i];
    if (cnt[v] == sz[v] * (sz[v] - 1) / 2) f[v][1] = add(f[v][1], 1);
  }
  FOR(i, 1, n) printf("%d ", f[Find(1)][i]);
}