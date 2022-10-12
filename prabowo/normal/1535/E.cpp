#include <bits/stdc++.h>
using namespace std;
 
const int N = 300005;
const int LN = 19;

int n, m, k;
int a[N], c[N];

int par[LN][N];

int find(int x) {
  for (int i = LN - 1; i >= 0; --i) {
    if (a[par[i][x]] > 0) x = par[i][x];
  }
  if (a[par[0][x]] > 0) x = par[0][x];
  return x;
}

int solve() {
  int q;
  scanf("%d %d %d", &q, &a[0], &c[0]);

  for (int i = 1; i <= q; ++i) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d %d %d", &par[0][i], &a[i], &c[i]);
      for (int j = 1; j < LN; ++j) {
        par[j][i] = par[j - 1][par[j - 1][i]];
      }
    } else {
      int v, w;
      scanf("%d %d", &v, &w);

      long long ans1 = 0, ans2 = 0;
      while (w > 0) {
        int u = find(v);
        if (u == v && a[u] == 0) break;

        int take = min(w, a[u]);
        a[u] -= take; w -= take;
        ans1 += take, ans2 += 1LL * take * c[u];
      }

      printf("%lld %lld\n", ans1, ans2);
      fflush(stdout);
    }
  }
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}