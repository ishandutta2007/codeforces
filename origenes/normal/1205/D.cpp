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

const int maxn = 1123;

int n, f[maxn], g[maxn];
vector<int> G[maxn];

void dfs(int u, int par) {
  for (auto v : G[u]) if (v != par) {
    dfs(v, u);
    f[u] += f[v];
  }
}

void dfs2(int u, int par) {
  g[u] = n - f[u];
  for (auto v : G[u]) if (v != par) {
    dfs2(v, u);
    chkmax(g[u], f[v]);
  }
}

int centroid() {
  fill(f + 1, f + n + 1, 1);
  dfs(1, 0);
  dfs2(1, 0);
  int j = 1;
  FOR(i, 2, n) if (g[i] < g[j]) j = i;
  return j;
}

map<pii, int> ans;

void dfs(int u, int par, int off, vector<int>::iterator &it) {
  for (auto v : G[u]) if (v != par) {
    ans[mp(u, v)] = *it - off;
    int noff = *it;
    ++it;
    dfs(v, u, noff, it);
  }
}

int main() {
  scanf("%d", &n);
  if (n == 1) return 0;
  if (n == 2) {
    puts("1 2 1");
    return 0;
  }
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v);
    G[v].eb(u);
  }
  int r = centroid();
  fill(f + 1, f + n + 1, 1);
  dfs(r, 0);
  sort(all(G[r]), [](int a, int b) { return f[a] > f[b]; });
  int br = 1;
  if (G[r].size() > 3) {
    int s = f[G[r][0]];
    while (s < (n - 1) / 3) s += f[G[r][br++]];
  }
  int a = 0, b = 0;
  REP(i, br) a += f[G[r][i]];
  FOR(i, br, int(G[r].size()) - 1) b += f[G[r][i]];
  vector<int> need(n - 1);
  REP(i, a) need[i] = i + 1;
  FOR(i, a, n - 2) need[i] = (i - a + 1) * (a + 1);
  auto it = need.begin();
  dfs(r, 0, 0, it);
  for (auto now : ans) printf("%d %d %d\n", now._1._1, now._1._2, now._2);
}