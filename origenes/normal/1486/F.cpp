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

const int maxn = 312345;

int n, m;
int dep[maxn], anc[maxn][19], nex[maxn], f[maxn];
vector<int> G[maxn], query[maxn];
vector<pii> claws[maxn];
ll ans;

void dfs(int u, int par) {
  dep[u] = dep[par] + 1;
  anc[u][0] = par;
  FOR(i, 1, 18) anc[u][i] = anc[anc[u][i - 1]][i - 1];
  for (auto v : G[u]) if (v != par) dfs(v, u);
}

int lift(int u, int d) {
  ROF(i, 18, 0) if (d >= (1 << i)) {
    u = anc[u][i];
    d -= 1 << i;
  }
  return u;
}

int lca(int u, int v) {
  if (dep[u] > dep[v]) swap(u, v);
  ROF(i, 18, 0) if (dep[u] <= dep[anc[v][i]]) v = anc[v][i];
  if (u == v) return u;
  ROF(i, 18, 0) if (anc[u][i] != anc[v][i]) u = anc[u][i], v = anc[v][i];
  return anc[u][0];
}

void dfs2(int u, int par) {
  map<int, int> cnt1;
  map<pii, int> cnt2;
  for (auto &[x, y] : claws[u]) {
    if (x > y) swap(x, y);
    cnt1[x]++, cnt1[y]++;
    cnt2[mp(x, y)]++;
  }
  for (auto [x, y] : claws[u]) {
    ans += claws[u].size() - 1;
    ans -= cnt1[x] - 1 + cnt1[y] - 1;
    ans += cnt2[mp(x, y)] - 1;
  }
  for (auto v : G[u]) if (v != par) dfs2(v, u);
}

void dfs3(int u, int par) {
  for (auto v : G[u]) if (v != par) {
    dfs3(v, u);
    f[u] += f[v];
  }
  for (auto v : query[u]) if (v != u) f[lift(v, dep[v] - dep[u] - 1)]--;
  ans += ll(claws[u].size()) * f[u];
  for (auto [x, y] : claws[u]) {
    if (x <= n) ans -= f[x];
    if (y <= n) ans -= f[y];
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  REP(i, n - 1) {
    int u, v;
    cin >> u >> v;
    G[u].eb(v);
    G[v].eb(u);
  }
  dfs(1, 0);
  FOR(i, 1, n) nex[i] = n;
  cin >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    int a = lca(u, v);
    int au = a == u ? ++nex[u] : lift(u, dep[u] - dep[a] - 1);
    int av = a == v ? ++nex[v] : lift(v, dep[v] - dep[a] - 1);
    f[u]++, f[v]++;
    f[a] -= 2;
    claws[a].eb(au, av);
    query[a].eb(u); query[a].eb(v);
  }
  dfs2(1, 0);
  ans /= 2;
  dfs3(1, 0);
  cout << ans;
}