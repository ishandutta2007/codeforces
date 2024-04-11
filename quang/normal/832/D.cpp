#include <bits/stdc++.h>

using namespace std;

const int N = 100010, LOG = 18;

int n, q;
vector<int> a[N];
int lv[N], par[LOG][N];
int in[N], out[N], cnt;

void dfs(int u, int p) {
  lv[u] = lv[p] + 1;
  par[0][u] = p;
  in[u] = ++cnt;
  for (int i = 1; i < LOG; i++) {
    par[i][u] = par[i - 1][par[i - 1][u]];
  }
  for (int v : a[u]) {
    if (v == p) {
      continue;
    }
    dfs(v, u);
  }
  out[u] = cnt;
}

bool isPar(int u, int v) {
  return in[u] <= in[v] && out[v] <= out[u];
}

int lca(int u, int v) {
  if (lv[u] < lv[v]) {
    swap(u, v);
  }
  int h = lv[u] - lv[v];
  for (int i = LOG - 1; i >= 0; i--) {
    if ((h >> i) & 1) {
      u = par[i][u];
    }
  }
  if (u == v) {
    return u;
  }
  for (int i = LOG - 1; i >= 0; i--) {
    if (par[i][u] != par[i][v]) {
      u = par[i][u];
      v = par[i][v];
    }
  }
  return par[0][u];
}

int get(int a, int b, int c) {
  int cnt = 0;
  cnt += isPar(c, a);
  cnt += isPar(c, b);
  if (cnt == 2) {
    int w = lca(a, b);
    return lv[w] - lv[c] + 1;
  } else if (cnt == 1) {
    return 1;
  }
//  cout << a << " " << b << " " << c << endl;
  int u = lca(a, c);
  int v = lca(b, c);
  if (u != v) {
    return lv[c] - max(lv[u], lv[v]) + 1;
  }
  return lv[c] - lv[u] + get(a, b, u);
}

int main() {
  scanf("%d %d", &n, &q);
  for (int i = 2; i <= n; i++) {
    int u;
    scanf("%d", &u);
    a[u].push_back(i);
    a[i].push_back(u);
  }
  dfs(1, 0);
  while (q--) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int res = get(a, b, c);
    res = max(res, get(a, c, b));
    res = max(res, get(b, c, a));
    printf("%d\n", res);
  }
  return 0;
}