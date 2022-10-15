#include <cstdio>

const int N = 223456;
const int CO = 20;
const int INF = 1 << 30;

int pv[N], de[N], he[N], ne[N], ss[N], ff[N], w[N], dp1[N], go1[N], lca[CO][N], cn[N], has[N];

void dfs(int v, int pr, int d) {
  pv[v] = pr;
  de[v] = d;
  int m1 = -INF;
  int v1 = -1;
  int m2 = -INF;
//  int v2 = -1;
  for (int e = he[v]; e >= 0; e = ne[e]) {
    if (ff[e] == pr) continue;
    dfs(ff[e], v, d + 1);
    int cur = dp1[ff[e]] + w[e];
    if (cur > m1) {
      m2 = m1;
//      v2 = v1;
      m1 = cur;
      v1 = go1[ff[e]];
    } else if (cur > m2) {
      m2 = cur;
//      v2 = go1[ff[e]];
    }
  }
  if (has[v]) {
    int cur = 0;
    if (cur > m1) {
      m2 = m1;
      m1 = 0;
      v1 = v;
    } else if (cur > m2) {
      m2 = cur;
    }
  }
//  printf("%d %d %d\n", v, m1, m2);
  dp1[v] = m1;
  go1[v] = v;
  if (m1 != m2) {
    go1[v] = go1[v1];
  }
}

int glca(int v, int u) {
  if (de[v] > de[u]) {
    int t = v; v = u; u = t;
  }
  for (int i = CO - 1; i >= 0; i--) {
    if (de[lca[i][u]] >= de[v]) u = lca[i][u];
  }
  if (v == u) return v;
  for (int i = CO - 1; i >= 0; i--) {
    if (lca[i][u] != lca[i][v]) {
      u = lca[i][u];
      v = lca[i][v];
    }
  }
  return lca[0][v];
}

void addPath(int v, int u) {
//  printf("add %d %d\n", v, u);
  int z = glca(v, u);
//  printf("lca %d %d %d\n", v, u, z);
  cn[v]++;
  cn[u]++;
  cn[z]--;
  if (lca[0][z] != z) cn[lca[0][z]]--;
}

void dfs2(int v, int m0, int v0) {
  int m1 = m0;
  int v1 = v0;
  int m2 = -INF;
  int v2 = -1;
  int m3 = -INF;
  int v3 = -1;
  for (int e = he[v]; e >= 0; e = ne[e]) {
    if (ff[e] == pv[v]) continue;
    int cur = dp1[ff[e]] + w[e];
    if (cur > m1) {
      m3 = m2;
      v3 = v2;
      m2 = m1;
      v2 = v1;
      m1 = cur;
      v1 = go1[ff[e]];
    } else if (cur > m2) {
      m3 = m2;
      v3 = v2;
      m2 = cur;
      v2 = go1[ff[e]];
    } else if (cur > m3) {
      m3 = cur;
      v3 = go1[ff[e]];
    }
  }  
  if (has[v]) {
    int cur = 0;
    if (cur > m1) {
      m3 = m2;
      v3 = v2;
      m2 = m1;
      v2 = v1;
      m1 = 0;
      v1 = v;
    } else if (cur > m2) {
      m3 = m2;
      v3 = v2;
      m2 = cur;
      v2 = v;
    } else if (cur > m3) {
      m3 = cur;
      v3 = v;
    }
  }
//  printf("type2 %d %d %d %d\n", v, m1, m2, v1);
  if (has[v] && m1 != m2) {
    addPath(v, v1);
  }
  for (int e = he[v]; e >= 0; e = ne[e]) {
    if (ff[e] == pv[v]) continue;
    if (v1 == go1[ff[e]]) dfs2(ff[e], m2 + w[e], m2 == m3 ? v : v2); else {
      if (v2 == go1[ff[e]]) {
        dfs2(ff[e], m1 + w[e], m1 == m3 ? v : v1);
      } else {
        dfs2(ff[e], m1 + w[e], m1 == m2 ? v : v1);
      }
    }
  }
}

void dfs3(int v) {
  for (int e = he[v]; e >= 0; e = ne[e]) {
    if (ff[e] == pv[v]) continue;
    dfs3(ff[e]);
    cn[v] += cn[ff[e]];
  }
//  printf("          %d %d\n", v, cn[v]);
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    cn[i] = 0;
    he[i] = -1;
    has[i] = false;
  }
  for (int i = 0; i < m; i++) {
    int x;
    scanf("%d", &x);
    has[x - 1] = true;
  }
  for (int i = 0; i < n - 1; i++) {
    scanf("%d%d%d", ss + i, ff + i, w + i);
    --ss[i];
    --ff[i];
    ss[i + n - 1] = ff[i];
    ff[i + n - 1] = ss[i];
    w[i + n - 1] = w[i];
  }
  for (int i = 0; i < n + n - 2; i++) {
    ne[i] = he[ss[i]];
    he[ss[i]] = i;
  }
  dfs(0, -1, 0);
  for (int i = 0; i < n; i++) lca[0][i] = pv[i] >= 0 ? pv[i] : i;
  for (int i = 1; i < CO; i++) {
    for (int v = 0; v < n; v++) {
      lca[i][v] = lca[i - 1][lca[i - 1][v]];
    }
  }
  dfs2(0, -INF, -1);
  dfs3(0);
  int ma = -1;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (has[i]) continue;
    if (cn[i] > ma) {
      ma = cn[i];
      ans = 1;
    } else if (cn[i] == ma) {
      ++ans;
    }
//    printf("  %d %d\n", cn[i], i);
  }
  printf("%d %d\n", ma, ans);
}