#include <bits/stdc++.h>

using namespace std;

const int N = 100010, MOD = 1000000007;

int n, q;
vector <pair<int, int> > a[N];
int lv[N], pa[20][N];
long long d[N];
long long f[N], g[N], rf[N], rg[N], cnt[N];

void dfs(int u, int p) {
  cnt[u] = 1;
  f[u] = g[u] = 0;
  for (int i = 0; i < a[u].size(); i++) {
    int v = a[u][i].first;
    long long len = a[u][i].second;
    if (v == p) {
      continue;
    }
    d[v] = (d[u] + len) % MOD;
    lv[v] = lv[u] + 1;
    pa[0][v] = u;
    dfs(v, u);
    cnt[u] += cnt[v];
    g[u] = (g[u] + g[v] + cnt[v] * len) % MOD;
    f[u] = (f[u] + f[v] + g[v] * len * 2 + cnt[v] * (len * len % MOD)) % MOD;
  }
}

void dfs2(int u, int p) {
  vector <long long> ff(a[u].size(), rf[u]);
  vector <long long> gg(a[u].size(), rg[u]);
  long long curf = 0, curg = 0;
  for (int i = 0; i < a[u].size(); i++) {
    int v = a[u][i].first;
    long long len = a[u][i].second;
    if (v == p) {
      continue;
    }
    ff[i] = (ff[i] + curf) % MOD;
    gg[i] = (gg[i] + curg) % MOD;
    curg = (curg + g[v] + cnt[v] * len) % MOD;
    curf = (curf + f[v] + g[v] * len * 2 + cnt[v] * (len * len % MOD)) % MOD;
  }
  curf = 0, curg = 0;
  for (int i = (int)a[u].size() - 1; i >= 0; i--) {
    int v = a[u][i].first;
    long long len = a[u][i].second;
    if (v == p) {
      continue;
    }
    ff[i] = (ff[i] + curf) % MOD;
    gg[i] = (gg[i] + curg) % MOD;
    curg = (curg + g[v] + cnt[v] * len) % MOD;
    curf = (curf + f[v] + g[v] * len * 2 + cnt[v] * (len * len % MOD)) % MOD;
  }
  for (int i = 0; i < a[u].size(); i++) {
    int v = a[u][i].first;
    long long len = a[u][i].second;
    if (v == p) {
      continue;
    }
    rg[v] = (rg[v] + gg[i] + len * (1ll * n - cnt[v])) % MOD;
    rf[v] = (rf[v] + ff[i] + gg[i] * len * 2 + (len * len % MOD) * (1ll * n - cnt[v])) % MOD;
    dfs2(v, u);
  }
}

int lca(int u, int v) {
  if (lv[u] < lv[v]) swap(u, v);
  int l = (lv[u] - lv[v]);
  for (int i = 19; i >= 0; i--) {
    if (l & ( 1 << i)) {
      u = pa[i][u];
    }
  }
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

int main() {
  ios_base::sync_with_stdio(0);
  #ifdef Doflamingo
  freopen("input", "r", stdin);
  #endif // Doflamingo
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    a[u].push_back(make_pair(v, w));
    a[v].push_back(make_pair(u, w));
  }
  dfs(1, 0);
  for (int i = 1; i < 20; i++) {
    for (int j = 1; j <= n; j++) {
      pa[i][j] = pa[i - 1][pa[i - 1][j]];
    }
  }
  dfs2(1, 0);
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    long long res = 0;
    int w = lca(u, v);
    if (w == v) {
      long long len = (d[u] - d[v] + MOD) % MOD;
      res = (rf[v] + len * rg[v] * 2 + (len * len % MOD) * (1ll * n - cnt[v])) % MOD;
      res = (f[u] + rf[u] - res * 2 + MOD + MOD) % MOD;
      cout << res << endl;
    } else {
      long long len = (d[u] + d[v] - d[w] - d[w] + MOD + MOD) % MOD;
      res = (f[v] + len * g[v] * 2 + (len * len % MOD) * cnt[v]) % MOD;
      res = (res * 2 - f[u] - rf[u] + MOD + MOD) % MOD;
      cout << res << endl;
    }
  }
  return 0;
}