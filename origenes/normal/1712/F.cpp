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

const int maxn = 1123456;

vector<int> G[maxn], bloc[maxn];
int deg[maxn], x[11], ans[11], f[maxn], dep[maxn];
int n, q;

void unite(int u, int v) {
  if (size(bloc[u]) < size(bloc[v])) swap(bloc[u], bloc[v]);
  REP(i, int(size(bloc[v]))) FOR(k, 1, q) {
    int j = max(ans[k] - i - x[k], 0);
    while (j < size(bloc[u]) && bloc[u][j] + bloc[v][i] - 2 * dep[u] >= ans[k]) {
      ans[k]++;
      j = max(ans[k] - i - x[k], 0);
    }
  }
  REP(i, int(size(bloc[v]))) chkmax(bloc[u][i], bloc[v][i]);
}

void dfs(int u, int par) {
  dep[u] = dep[par] + 1;
  for (auto v : G[u]) if (v != par) {
    dfs(v, u);
    unite(u, v);
  }
  FOR(i, 1, q) {
    int j = max(ans[i] - f[u] - x[i], 0);
    while (j < size(bloc[u]) && bloc[u][j] - dep[u] >= ans[i]) {
      ans[i]++;
      j = max(ans[i] - f[u] - x[i], 0);
    }
  }
  if (f[u] >= size(bloc[u])) bloc[u].eb(dep[u]);
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 2, n) {
    int p; cin >> p;
    G[i].eb(p); G[p].eb(i);
    deg[i]++, deg[p]++;
  }
  cin >> q;
  FOR(i, 1, q) cin >> x[i];
  int root = 1;
  FOR(i, 1, n) if (deg[i] > 1) {
    root = i;
    break;
  }
  queue<int> Q;
  reset(f, 0x3f);
  FOR(i, 1, n) if (deg[i] == 1) {
    Q.emplace(i);
    f[i] = 0;
  }
  while (!Q.empty()) {
    auto u = Q.front(); Q.pop();
    for (auto v : G[u]) if (f[v] > f[u] + 1) {
      f[v] = f[u] + 1;
      Q.emplace(v);
    }
  }
  dfs(root, 0);
  FOR(i, 1, q) cout << ans[i] - 1 << ' ';
}