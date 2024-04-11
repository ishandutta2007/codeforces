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

const int maxn = 3123;

int n, sz[maxn][maxn];
bool vis[maxn][maxn];
ll f[maxn][maxn], ans;
vector<int> G[maxn];

void dfs3(int u, int par) {
  sz[u][par] = 1;
  for (auto v : G[u]) if (v != par) {
      dfs3(v, u);
      sz[u][par] += sz[v][u];
    }
}

ll solve(int u, int pu, int v, int pv) {
  if (u > v) swap(u, v), swap(pu, pv);
  if (vis[u][v]) return f[u][v];
  ll &ret = f[u][v];
  vis[u][v] = true;
  ret = 0;
  for (auto nu : G[u]) if (nu != pu) chkmax(ret, solve(nu, u, v, pv));
  for (auto nv : G[v]) if (nv != pv) chkmax(ret, solve(u, pu, nv, v));
  return ret += sz[u][pu] * sz[v][pv];
}

void dfs2(int u, int par) {
  for (auto v : G[u]) if (v != par) {
      chkmax(ans, solve(u, v, v, u));
      dfs2(v, u);
    }
}

int main() {
  scanf("%d", &n);
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v);
    G[v].eb(u);
  }
  FOR(i, 1, n) dfs3(i, 0);
  dfs2(1, 0);
  printf("%lld", ans);
}