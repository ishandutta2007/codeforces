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

const int maxn = 112345;

int n, m, cnt;
vector<int> G[maxn];
int par[maxn], anc[maxn][17], dep[maxn], f[maxn];
bool good[maxn];

void dfs(int u, int p) {
  for (auto v : G[u]) if (v != p) {
    anc[v][0] = u;
    dep[v] = dep[u] + 1;
    FOR(i, 1, 16) anc[v][i] = anc[anc[v][i - 1]][i - 1];
    dfs(v, u);
  }
}

int Find(int x) {
  return par[x] == x ? x : par[x] = Find(par[x]);
}

void Union(int x, int y) {
  x = Find(x), y = Find(y);
  par[x] = y;
}

void dfs2(int u, int p) {
  cnt += f[u];
  if (cnt == m - n + 1) good[u] = true;
  for (auto v : G[u]) if (v != p) dfs2(v, u);
  cnt -= f[u];
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m;
  vector<pii> qs;
  iota(par, par + n, 0);
  REP(i, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (Find(u) == Find(v)) qs.eb(u, v);
    else {
      G[u].eb(v);
      G[v].eb(u);
      Union(u, v);
    }
  }
  dfs(0, -1);
  for (auto [u, v] : qs) {
    if (dep[u] > dep[v]) swap(u, v);
    int pv = v;
    ROF(i, 16, 0) if (dep[anc[v][i]] >= dep[u] + 1) v = anc[v][i];
    if (anc[v][0] == u) f[0]++, f[v]--, f[pv]++;
    else f[u]++, f[pv]++;
  }
  dfs2(0, -1);
  REP(i, n) cout << good[i];
}