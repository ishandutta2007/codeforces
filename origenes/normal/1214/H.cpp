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

int n, k;
vector<int> G[maxn];
int f[maxn], g[maxn], h[maxn], ans[maxn];

int dfs1(int u, int par) {
  int ret = u;
  for (auto v : G[u]) if (v != par) {
    f[v] = f[u] + 1;
    int now = dfs1(v, u);
    if (f[ret] < f[now]) ret = now;
  }
  return ret;
}

int dfs2(int u, int par) {
  int ret = u;
  for (auto v : G[u]) if (v != par) {
    g[v] = g[u] + 1;
    int now = dfs2(v, u);
    if (g[ret] < g[now]) ret = now;
  }
  return h[u] = ret;
}

bool dfs3(int u, int par, int st, int d, int en) {
  if (++en >= k && k != 2) return false;
  st += d;
  ans[u] = st % k + 1;
  for (auto v : G[u]) if (v != par && !dfs3(v, u, st, d, en)) return false;
  return true;
}

int main() {
  scanf("%d%d", &n, &k);
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v);
    G[v].eb(u);
  }
  int u = dfs1(1, 0);
  int v = dfs2(u, 0);
  FOR(i, 1, n) if (h[i] == v) {
    ans[i] = g[i] % k + 1;
    if (g[i] * 2 < g[v]) {
      for (auto j : G[i]) if (h[j] != v) {
        if (!dfs3(j, i, g[i], -1, g[i] + 1)) goto label;
      }
    } else {
      for (auto j : G[i]) if (h[j] != v) {
        if (!dfs3(j, i, g[i], 1, g[v] - g[i] + 1)) goto label;
      }
    }
  }
  puts("Yes");
  FOR(i, 1, n) printf("%d ", ans[i]);
  return 0;
  label: puts("No");
}