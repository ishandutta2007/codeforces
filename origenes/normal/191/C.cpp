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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 112345;

vector<pii> G[maxn];

int clk, n, k;
int tab[maxn], st[maxn * 2][19], in[maxn], dep[maxn], ans[maxn];

void dfs(int u, int par) {
  in[u] = ++clk;
  st[clk][0] = u;
  dep[u] = dep[par] + 1;
  for (auto _ : G[u]) {
    int v = _._1;
    if (v == par) continue;
    dfs(v, u);
    st[++clk][0] = u;
  }
}

inline int rmq(int l, int r) {
  int val = floor(log(r - l + 1) / log(2));
  int u = st[l + (1 << val) - 1][val], v = st[r][val];
  return dep[u] < dep[v] ? u : v;
}

inline int lca(int u, int v) {
  if (in[u] > in[v]) swap(u, v);
  return rmq(in[u], in[v]);
}

int dfs(int u, int par, int pre) {
  for (auto _ : G[u]) {
    int v = _._1, nxt = _._2;
    if (v == par) continue;
    tab[u] += dfs(v, u, nxt);
  }
  return ans[pre] = tab[u];
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v, i);
    G[v].eb(u, i);
  }
  dfs(1, 0);
  FOR(i, 1, clk) FOR(j, 1, 18) {
    st[i][j] = st[i][j - 1];
    int val = i - (1 << j - 1);
    if (val > 0 && dep[st[val][j - 1]] < dep[st[i][j]]) st[i][j] = st[val][j - 1];
  }
  scanf("%d", &k);
  while (k--) {
    int u, v, anc;
    scanf("%d%d", &u, &v);
    anc = lca(u, v);
    tab[u]++, tab[v]++;
    tab[anc] -= 2;
  }
  dfs(1, 0, 0);
  FOR(i, 1, n - 1) printf("%d ", ans[i]);
}