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

vector<int> G[maxn];
int n, m, dep[maxn], st[maxn][18], bit[18], sz[maxn];

void dfs(int u, int par) {
  dep[u] = dep[par] + 1;
  st[u][0] = par;
  FOR(i, 1, 17) st[u][i] = st[st[u][i - 1]][i - 1];
  sz[u] = 1;
  for (int v : G[u]) if (v != par) {
    dfs(v, u);
    sz[u] += sz[v];
  }
}

int main() {
  REP(i, 18) bit[i] = 1 << i;
  scanf("%d", &n);
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v);
    G[v].eb(u);
  }
  dfs(1, 0);
  scanf("%d", &m);
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    if ((dep[u] ^ dep[v]) & 1) {
      puts("0");
      continue;
    }
    if (u == v) {
      printf("%d\n", n);
      continue;
    }
    if (dep[u] > dep[v]) swap(u, v);
    int x = u, y = v;
    ROF(i, 17, 0) if (dep[y] - dep[x] >= bit[i]) y = st[y][i];
    ROF(i, 17, 0) if (st[x][i] != st[y][i]) x = st[x][i], y = st[y][i];
    int a = x == y ? x : st[x][0], need = dep[u] + dep[v] - 2 * dep[a] >> 1;
    need--;
    if (dep[u] == dep[v]) {
      x = u, y = v;
      ROF(i, 17, 0) if (bit[i] <= need) y = st[y][i], x = st[x][i], need -= bit[i];
      printf("%d\n", n - sz[x] - sz[y]);
    } else {
      y = v;
      ROF(i, 17, 0) if (bit[i] <= need) y = st[y][i], need -= bit[i];
      printf("%d\n", sz[st[y][0]] - sz[y]);
    }
  }
}