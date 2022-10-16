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

int n, m;
ll x[maxn], y[maxn];
int dep[maxn], anc[maxn][18];
vector<int> G[maxn];

ll check(int i, int j, int k) {
  return (x[i] - x[k]) * (y[j] - y[k]) - (x[j] - x[k]) * (y[i] - y[k]);
}

void dfs(int u, int par) {
  dep[u] = dep[par] + 1;
  anc[u][0] = par;
  FOR(i, 1, 17) anc[u][i] = anc[anc[u][i - 1]][i - 1];
  for (auto v : G[u]) dfs(v, u);
}

int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  ROF(i, 17, 0) if (dep[anc[u][i]] >= dep[v]) u = anc[u][i];
  if (u == v) return u;
  ROF(i, 17, 0) if (anc[u][i] != anc[v][i]) u = anc[u][i], v = anc[v][i];
  return anc[u][0];
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) cin >> x[i] >> y[i];
  vector<int> hull = {0};
  ROF(i, n, 1) {
    while (hull.size() > 2 && check(hull.back(), i, hull[hull.size() - 2]) < 0) hull.pop_back();
    G[hull.back()].eb(i);
    hull.eb(i);
  }
  dfs(n, 0);
  cin >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    cout << lca(u, v) << ' ';
  }
}