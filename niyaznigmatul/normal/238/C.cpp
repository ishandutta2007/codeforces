#include <cstdio>

const int INF = 1 << 30;

int ss[11111], ff[11111], he[11111], dp[11111], dwn[11111], bad[11111], was[11111];
int ne[11111];

int n, got;

void dfs(int v, int p) {
  was[v] = true;
  dwn[v] = 0;
  for (int e = he[v]; e >= 0; e = ne[e]) {
    if (bad[e]) continue;
    if (ff[e] == p) continue;
    dfs(ff[e], v);
    dwn[v] += dwn[ff[e]];
    if (e >= n - 1) dwn[v]++;
  }  
}

void dfs2(int v, int p, int dd) {
  dp[v] = dd + dwn[v];
  if (got > dp[v]) got = dp[v];
  for (int e = he[v]; e >= 0; e = ne[e]) {
    if (bad[e] || ff[e] == p) continue;
    int cur = e >= n - 1 ? 1 : -1;
    dfs2(ff[e], v, dd + dwn[v] - dwn[ff[e]] - cur);
  }
}

int main() {
  scanf("%d", &n);
  if (n == 1) {
    puts("0");
    return 0;
  }
  for (int i = 0; i + 1 < n; i++) {
    scanf("%d%d", ss + i, ff + i);
    --ss[i];
    --ff[i];
    ss[i + n - 1] = ff[i];
    ff[i + n - 1] = ss[i];
  }
  for (int i = 0; i < n; i++) he[i] = -1;
  for (int i = 0; i < n + n - 2; i++) {
    ne[i] = he[ss[i]];
    he[ss[i]] = i;
  }
  int ans = INF;
  for (int i = 0; i + 1 < n; i++) {
    bad[i] = bad[i + n - 1] = true;
    for (int j = 0; j < n; j++) was[j] = false;
    int cur = 0;
    for (int j = 0; j < n; j++) {
      if (was[j]) continue;
      got = INF;
      dfs(j, -1);
      dfs2(j, -1, 0);
      cur += got;
    }
    if (ans > cur) ans = cur;
    bad[i] = bad[i + n - 1] = false;
  }
  printf("%d\n", ans);
}