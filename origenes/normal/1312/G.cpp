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

int n, k, clk;
int a[maxn], p[maxn], f[maxn], g[maxn], dfn[maxn];
char c[maxn];
bool good[maxn];
vector<int> G[maxn];

void dfs1(int u) {
  clk += good[u];
  dfn[u] = clk;
  for (auto v : G[u]) dfs1(v);
}

void dfs2(int u) {
  chkmin(f[u], f[p[u]] + 1);
  if (good[u]) chkmin(f[u], g[p[u]] + dfn[u]);
  g[u] = min(g[p[u]], f[u] - dfn[u] + good[u]);
  for (auto v : G[u]) dfs2(v);
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    scanf("%d %c", p + i, c + i);
    G[p[i]].eb(i);
  }
  REP(i, n + 1) sort(all(G[i]), [&](int x, int y) { return c[x] < c[y]; });
  scanf("%d", &k);
  FOR(i, 1, k) {
    scanf("%d", a + i);
    good[a[i]] = true;
  }
  reset(f, 0x3f);
  reset(g, 0x3f);
  f[0] = 0;
  dfs1(0);
  dfs2(0);
  FOR(i, 1, k) printf("%d ", f[a[i]]);
}