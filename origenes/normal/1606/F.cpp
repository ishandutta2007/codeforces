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

const int maxn = 212345;
const int SZ = 450;

vector<int> G[maxn];
int n, q;
int f[maxn][SZ], sz[maxn];

void dfs(int u, int par) {
  for (auto v : G[u]) if (v != par) {
    dfs(v, u);
    REP(i, SZ) f[u][i] += max(1, f[v][i] - i);
  }
}

void dfs2(int u, int par) {
  sz[u] = 1;
  for (auto v : G[u]) if (v != par) {
    dfs2(v, u);
    vector<int> tmp(SZ);
    REP(i, min(sz[u] + 1, SZ)) REP(j, min(sz[v] + 1, SZ - i)) {
      chkmax(tmp[i + j], f[u][i] + 1);
      if (i + j + 1 < SZ) chkmax(tmp[i + j + 1], f[u][i] + f[v][j]);
    }
    sz[u] += sz[v];
    REP(i, min(sz[u] + 1, SZ)) f[u][i] = tmp[i];
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
  cin >> q;
  vector<pii> qs(q);
  vector<int> ans(q);
  REP(i, q) {
    int v, k;
    cin >> v >> k;
    qs[i] = {v, k};
  }
  dfs(1, 0);
  REP(i, q) {
    auto [v, k] = qs[i];
    if (k < SZ) ans[i] = f[v][k];
  }
  reset(f, 0);
  dfs2(1, 0);
  REP(i, q) {
    auto [v, k] = qs[i];
    if (k >= SZ) REP(j, SZ) chkmax(ans[i], f[v][j] - j * k);
  }
  for (auto x : ans) cout << x << '\n';
}