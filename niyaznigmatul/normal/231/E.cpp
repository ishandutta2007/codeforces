#include <cstdio>
#include <algorithm>


const int N = 222222;
const int CO = 20;

const int md = 1000000007;

int cc[N], de[N], pv[N], was[N], ss[N], ff[N], he[N], ne[N], cyc[N], col[N], pr[N];
int colc, lca[CO][N], sc[CO][N], two[N];

void dfs(int v, int p, int d, int c) {
  cc[v] = c;
  de[v] = d;
  pv[v] = p;
  was[v] = true;
  for (int e = he[v]; e >= 0; e = ne[e]) {
    if (ff[e] == p) continue;
    if (was[ff[e]] && de[ff[e]] < de[v]) {
      for (int u = v; u != ff[e]; u = pv[u]) {
        col[u] = colc;
      }
      col[ff[e]] = colc;
      cyc[colc] = true;
      colc++;
    }
    if (!was[ff[e]]) dfs(ff[e], v, d + 1, c);
  }
  if (col[v] < 0) {
    cyc[colc] = false;
    col[v] = colc++;
  }
}

void dfs2(int v) {
  was[v] = true;
  for (int e = he[v]; e >= 0; e = ne[e]) {
    if (!was[ff[e]]) {
      if (col[v] != col[ff[e]]) {
        de[col[ff[e]]] = de[col[v]] + 1;
        pr[col[ff[e]]] = col[v];
      }
      dfs2(ff[e]);
    }
  }
}

int glca(int x, int y) {
  if (de[x] > de[y]) std::swap(x, y);
  for (int j = CO - 1; j >= 0; j--) {
    if (de[lca[j][y]] >= de[x]) y = lca[j][y];
  }
  if (x == y) {
    return x;
  }
  for (int j = CO - 1; j >= 0; j--) 
    if (lca[j][x] != lca[j][y]) {
      x = lca[j][x];
      y = lca[j][y];
    }
  return lca[0][x];
}

int main() {
  two[0] = 1;
  for (int i = 1; i < N; i++) two[i] = (two[i - 1] * 2) % md;
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", ss + i, ff + i);
    --ss[i];
    --ff[i];
    ss[i + m] = ff[i];
    ff[i + m] = ss[i];
  }
  for (int i = 0; i < n; i++) he[i] = -1;
  for (int i = 0; i < m + m; i++) {
    ne[i] = he[ss[i]];
    he[ss[i]] = i;
  }
  for (int i = 0; i < n; i++) col[i] = -1;
  int ccc = 0;
  colc = 0;
  for (int i = 0; i < n; i++) {
    if (!was[i]) {
      dfs(i, -1, 0, ccc);
      ++ccc;
    }
  }
  for (int i = 0; i < colc; i++) pr[i] = -1;
  for (int i = 0; i < n; i++) was[i] = false;
  for (int i = 0; i < n; i++) 
    if (!was[i]) {
      de[i] = 0;
      dfs2(i);
    }
  for (int i = 0; i < colc; i++) {
    lca[0][i] = pr[i];
    sc[0][i] = cyc[i] ? 1 : 0;
  }
  for (int i = 1; i < CO; i++) {
    for (int v = 0; v < colc; v++) {
      if (lca[i - 1][v] < 0) lca[i][v] = -1; else
        lca[i][v] = lca[i - 1][lca[i - 1][v]];
      if (lca[i - 1][v] < 0) sc[i][v] = sc[i - 1][v]; else
        sc[i][v] = sc[i - 1][v] + sc[i - 1][lca[i - 1][v]];
    }
  }
  int k;
  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    --x;
    --y;
    if (cc[x] != cc[y]) {
      puts("0");
      continue;
    }
    x = col[x];
    y = col[y];
    int z = glca(x, y);
    int e = sc[CO - 1][x] + sc[CO - 1][y] - 2 * sc[CO - 1][z] + cyc[z];
//    printf("%d %d %d\n", x, y, z);
//    printf("%d\n", e);
    printf("%d\n", two[e]);
  }
}