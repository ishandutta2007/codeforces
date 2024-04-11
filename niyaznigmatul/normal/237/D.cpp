#include <cstdio>

int pe[223456], pv[223456], a[222222], b[222222], he[222222], ne[222222], deg[222222];
int n;

void dfs(int v, int p) {
  pv[v] = p;
  for (int e = he[v]; e >= 0; e = ne[e]) {
    if (b[e] == p) continue;
    pe[b[e]] = e >= n - 1 ? (e - (n - 1)) : e;
    dfs(b[e], v);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i + 1 < n; i++) {
    scanf("%d%d", a + i, b + i);
    --a[i];
    --b[i];
  }
  for (int i = 0; i + 1 < n; i++) {
    deg[a[i]]++;
    deg[b[i]]++;
  }
  printf("%d\n", n - 1);
  for (int i = 0; i + 1 < n; i++) {
    printf("%d %d %d\n", 2, a[i] + 1, b[i] + 1);
  }
  for (int i = 0; i + 1 < n; i++) {
    a[i + n - 1] = b[i];
    b[i + n - 1] = a[i];
  }
  for (int i = 0; i < n; i++) he[i] = -1;
  for (int i = 0; i < n + n - 2; i++) {
    ne[i] = he[a[i]];
    he[a[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    if (deg[i] == 1) {
      dfs(i, -1);
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if (pv[i] >= 0 && pv[pv[i]] >= 0) {
      printf("%d %d\n", pe[i] + 1, pe[pv[i]] + 1);
    }
  }
}