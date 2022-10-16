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
const ll inf = 1e18;

ll f[maxn][3][3];
int n, c[3][maxn], dep[maxn];
vector<int> G[maxn];

void dfs(int u, int par) {
  dep[u] = dep[par] + 1;
  bool leaf = true;
  for (auto v : G[u]) if (v != par) {
    leaf = false;
    dfs(v, u);
  }
  if (leaf) {
    REP(i, 3) REP(j, 3) if (i != j) f[u][i][j] = c[i][u];
    return;
  }
  REP(i, 3) REP(j, 3) if (j != i) {
    int k = 0; while (k == i || k == j) k++;
    ll now = 0;
    for (auto v : G[u]) if (v != par) {
      now += f[v][j][k];
      if (now > inf) break;
    }
    now += c[i][u];
    chkmin(f[u][i][j], now);
  }
}

int main() {
  scanf("%d", &n);
  REP(i, 3) FOR(j, 1, n) scanf("%d", &c[i][j]);
  reset(f, 0x3f);
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v); G[v].eb(u);
  }
  FOR(i, 1, n) if (G[i].size() >= 3) {
    puts("-1");
    return 0;
  }
  int r = 0;
  FOR(i, 1, n) if (G[i].size() == 1) {
    r = i;
    break;
  }
  dfs(r, 0);
  int bi = 0, bj = 0;
  REP(i, 3) REP(j, 3) if (f[r][i][j] < f[r][bi][bj]) {
    bi = i; bj = j;
  }
  if (f[r][bi][bj] > 1e18) {
    puts("-1");
    return 0;
  }
  printf("%lld\n", f[r][bi][bj]);
  int bk = 0; while (bk == bi || bk == bj) bk++;
  FOR(i, 1, n) {
    int ans = -1;
    if (dep[i] % 3 == 0) ans = bk;
    else if (dep[i] % 3 == 2) ans = bj;
    else ans = bi;
    printf("%d ", ans + 1);
  }
}