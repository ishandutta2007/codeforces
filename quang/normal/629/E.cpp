#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
vector <int> a[N];
int lv[N], pa[20][N], numChild[N];
long long totLenChild[N], totLen[N];

void dfs(int u, int p) {
  lv[u] = lv[p] + 1;
  pa[0][u] = p;
  for (int i = 1; i < 18; i++) {
    pa[i][u] = pa[i - 1][pa[i - 1][u]];
  }
  numChild[u] = 1;
  totLenChild[u] = 0;
  for (int v : a[u]) {
    if (v == p) {
      continue;
    }
    dfs(v, u);
    numChild[u] += numChild[v];
    totLenChild[u] += totLenChild[v] + numChild[v];
  }
}

void redfs(int u, int p) {
  for (int v : a[u]) {
    if (v == p) {
      continue;
    }
    totLen[v] = totLen[u] + n - 2 * numChild[v];
    redfs(v, u);
  }
}

int par(int u, int v) {
  for (int i = 17; i >= 0; i--) {
    if (v & (1 << i)) {
      u = pa[i][u];
    }
  }
  return u;
}

int lca(int u, int v) {
  if (lv[u] > lv[v]) {
    swap(u, v);
  }
  int h = lv[v] - lv[u];
  v = par(v, h);
  if (v == u) {
    return u;
  }
  for (int i = 17; i >= 0; i--) {
    if (pa[i][u] != pa[i][v]) {
      u = pa[i][u];
      v = pa[i][v];
    }
  }
  return pa[0][u];
}

int main() {
  //freopen("input.txt", "r", stdin);
  scanf("%d %d", &n, &m);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    a[u].push_back(v);
    a[v].push_back(u);
  }
  dfs(1, 0);
  totLen[1] = totLenChild[1];
  redfs(1, 0);
  while (m--) {
    int u, v;
    scanf("%d %d", &u, &v);
    if (lv[u] > lv[v]) {
      swap(u, v);
    }
    int w = lca(u, v);
    int len = lv[u] + lv[v] - 2 * lv[w];
    int cnt1, cnt2;
    long long len1, len2;
    if (w == u) {
      cnt2 = numChild[v];
      len2 = totLenChild[v];
      int vv = par(v, lv[v] - lv[u] - 1);
      cnt1 = n - numChild[vv];
      len1 = totLen[u] - (totLenChild[vv] + numChild[vv]);
    } else {
      cnt1 = numChild[u];
      cnt2 = numChild[v];
      len1 = totLenChild[u];
      len2 = totLenChild[v];
    }
    long long x = len1 * cnt2 + len2 * cnt1 + 1ll * (len + 1) * cnt1 * cnt2;
    long long y = 1ll * cnt1 * cnt2;
    printf("%0.17f\n", (double)x / y);
  }
  return 0;
}