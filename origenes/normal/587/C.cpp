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

const int maxn = 1e5 + 5;

vector<vector<int>> G;
int n, m, q, st[maxn][17], dep[maxn], bit[17];
vector<int> tab[maxn][17], lis[maxn];

vector<int> get(const vector<int> &a, const vector<int> &b, int cap) {
  int n = min(int(a.size()), cap), m = min(int(b.size()), cap);
  int i = 0, j = 0;
  vector<int> ret;
  while (i < n && j < m) {
    if (a[i] <= b[j]) ret.eb(a[i++]);
    else ret.eb(b[j++]);
  }
  while (i < n) ret.eb(a[i++]);
  while (j < m) ret.eb(b[j++]);
  uni(ret);
  if (ret.size() > cap) ret.resize(cap);
  return ret;
}

void dfs(int u, int par) {
  dep[u] = dep[par] + 1;
  st[u][0] = par;
  tab[u][0] = lis[par];
  FOR(i, 1, 16) {
    st[u][i] = st[st[u][i - 1]][i - 1];
    tab[u][i] = get(tab[u][i - 1], tab[st[u][i - 1]][i - 1], 10);
  }
  for (int v : G[u]) if (v != par) dfs(v, u);
}

int main() {
  REP(i, 17) bit[i] = 1 << i;
  scanf("%d%d%d", &n, &m, &q);
  G.resize(maxn);
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v);
    G[v].eb(u);
  }
  FOR(i, 1, m) {
    int c;
    scanf("%d", &c);
    if (lis[c].size() < 10) lis[c].eb(i);
  }
  dfs(1, 0);
  G.clear();
  while (q--) {
    int u, v, a;
    scanf("%d%d%d", &u, &v, &a);
    if (dep[u] > dep[v]) swap(u, v);
    vector<int> ans = get(lis[u], lis[v], a);
    ROF(i, 16, 0) if (dep[v] - dep[u] >= bit[i]) {
        ans = get(ans, tab[v][i], a);
        v = st[v][i];
      }
    ROF(i, 16, 0) if (st[u][i] != st[v][i]) {
        ans = get(ans, tab[u][i], a);
        ans = get(ans, tab[v][i], a);
        u = st[u][i], v = st[v][i];
      }
    if (u != v) ans = get(ans, lis[st[u][0]], a);
    printf("%d", int(ans.size()));
    for (auto it : ans) printf(" %d", it);
    putchar('\n');
  }
}