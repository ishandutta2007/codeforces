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

const int maxn = 5123;

int n, m, col[maxn];
bool vis[maxn], f[maxn][maxn];
int n1, n2, n3, ans[maxn];
vector<int> G[maxn];

bool dfs(int u, int c) {
  col[u] = c;
  for (auto v : G[u]) {
    if (col[v] != -1 && col[v] == c) return false;
    if (col[v] == -1 && !dfs(v, c ^ 1)) return false;
  }
  return true;
}

pii dfs(int u) {
  vis[u] = true;
  int s = 1, o = col[u];
  for (auto v : G[u]) if (!vis[v]) {
    auto [ns, no] = dfs(v);
    s += ns, o += no;
  }
  return {s, o};
}

void dfs2(int u, bool so) {
  vis[u] = true;
  ans[u] = 1;
  if (so == col[u]) ans[u] = 2;
  for (auto v : G[u]) if (!vis[v]) dfs2(v, so);
}

int main() {
  scanf("%d%d", &n, &m);
  scanf("%d%d%d", &n1, &n2, &n3);
  while (m--) {
    int u, v; scanf("%d%d", &u, &v);
    G[u].eb(v);
    G[v].eb(u);
  }
  reset(col, -1);
  FOR(i, 1, n) if (col[i] == -1 && !dfs(i, 0)) {
    puts("NO");
    return 0;
  }
  vector<int> sz, ones;
  FOR(i, 1, n) if (!vis[i]) {
    auto [s, o] = dfs(i);
    sz.eb(s); ones.eb(o);
  }
  int N = sz.size();
  f[0][0] = true;
  REP(i, N) REP(j, n2 + 1) {
    if (j + ones[i] <= n2) f[i + 1][j + ones[i]] |= f[i][j];
    if (j + sz[i] - ones[i] <= n2) f[i + 1][j + sz[i] - ones[i]] |= f[i][j];
  }
  if (!f[N][n2]) {
    puts("NO");
    return 0;
  }
  puts("YES");
  int j = n2;
  vector<bool> cc(N);
  ROF(i, N, 1) {
    if (j >= ones[i - 1] && f[i - 1][j - ones[i - 1]]) {
      cc[i - 1] = true;
      j -= ones[i - 1];
    } else j -= sz[i - 1] - ones[i - 1];
  }
  reset(vis, 0);
  int cnt = 0;
  FOR(i, 1, n) if (!vis[i]) {
    dfs2(i, cc[cnt]);
    cnt++;
  }
  FOR(i, 1, n) {
    if (ans[i] == 2) printf("%d", ans[i]);
    else {
      if (n1) {
        putchar('1');
        n1--;
      } else putchar('3');
    }
  }
}