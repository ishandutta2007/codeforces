#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int mod = 1000000007;

int n, m, newn;
int power[N];
vector <int> a[N];
vector <int> b[N];
int g[N], sl[N];

struct lcc{
  int low[N], num[N], used[N], st[N], top, cnt;

  void dfs(int u, int p) {
    low[u] = num[u] = ++cnt;
    st[top++] = u;
    for (int i = 0; i < a[u].size(); i++) {
      int v = a[u][i];
      if (v == p || used[v]) {
        continue;
      }
      if (!num[v]) {
        dfs(v, u);
      }
      low[u] = min(low[u], low[v]);
    }
    if (low[u] == num[u]) {
      int v;
      ++newn;
      while (1) {
        v = st[--top];
        g[v] = newn;
        sl[newn]++;
        used[v] = 1;
        if (u == v) {
          break;
        }
      }
    }
  }

  void submain() {
    for (int i = 1; i <= n; i++) {
      if (!used[i]) {
        dfs(i, 0);
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < a[i].size(); j++) {
        if (g[i] != g[a[i][j]]) {
          b[g[i]].push_back(g[a[i][j]]);
        }
      }
    }
  }
} partA;

struct tree {
  int lv[N], pa[20][N], num[N];

  void dfs(int u, int p, int sl2) {
    sl2 += (sl[u] > 1);
    num[u] = sl2;
    lv[u] = lv[p] + 1;
    pa[0][u] = p;
    for (int i = 0; i < b[u].size(); i++) {
      int v = b[u][i];
      if (v == p) {
        continue;
      }
      dfs(v, u, sl2);
    }
  }

  void buildlca() {
    for (int i = 1; i < 20; i++) {
      for (int j = 1; j <= n; j++) {
        pa[i][j] = pa[i - 1][pa[i - 1][j]];
      }
    }
  }

  void submain() {
    dfs(1, 0, 0);
    buildlca();
  }

  int finddad(int u, int dis) {
    for (int i = 19; i >= 0; i--) {
      if(dis & (1 << i)) {
        u = pa[i][u];
      }
    }
    return u;
  }

  int lca(int u, int v) {
    u = finddad(u, lv[u] - lv[v]);
    if (u == v) {
      return u;
    }
    for (int i = 19; i >= 0; i--) {
      if (pa[i][u] != pa[i][v]) {
        u = pa[i][u];
        v = pa[i][v];
      }
    }
    return pa[0][u];
  }

  void findans(int u, int v) {
    int x = g[u], y = g[v];
    if (lv[x] < lv[y]) {
      swap(u, v);
      swap(x, y);
    }
    int z = lca(x, y), res = 0;
    if (z == y) {
      res = num[x] - num[pa[0][y]];
      cout << power[res] << endl;
    } else {
      res = num[x] + num[y] - num[z] * 2 + (sl[z] > 1);
      cout << power[res] << endl;
    }
  }
} partB;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  partA.submain();
  partB.submain();
  power[0] = 1;
  for (int i = 1; i < N; i++) {
    power[i] = 1ll * power[i - 1] * 2 % mod;
  }
  int k;
  cin >> k;
  while (k--) {
    int u, v;
    cin >> u >> v;
    if (g[u] == g[v]) {
      cout << 2 << endl;
      continue;
    }
    partB.findans(u, v);
  }
  return 0;
}