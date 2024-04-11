#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1005;
int t, n, m, a[N], b[N], cnt;
int fa[N], np;
bool v[N], d[N], gu;
vector<int> to[N], tt[N];
void dfs(int i, int g) {
  v[i] = 1;
  g = min(g, 1 << 30);
  bool ok = 0;
  for (int j : to[i]) {
    if (g <= a[j]) continue;
    if (d[j] && j != 1) continue;
    if (i == 1 && j == 1) continue;
    if (j == fa[i] && ok == 0) {
      ok = 1;
      continue;
    }
    if (!v[j]) {
      fa[j] = i, dfs(j, g + b[j]);
      if (gu) return;
      continue;
    }
    gu = 1;
    for (int x = i; !d[x]; x = fa[x]) {
      d[x] = 1, cnt++;
      np += b[x], np = min(np, 1 << 30);
      for (int y : to[x])
        if (!d[y])
          to[y].push_back(1), to[1].push_back(y);
    }
    for (int x = j; !d[x]; x = fa[x]) {
      d[x] = 1, cnt++;
      np += b[x], np = min(np, 1 << 30);
      for (int y : to[x])
        if (!d[y])
          to[y].push_back(1), to[1].push_back(y);
    }
    return;
  }
}
bool check(int z) {
  for (int i = 1; i <= n; i++) to[i] = tt[i];
  memset(d, 0, sizeof d);
  cnt = 1, np = z, d[1] = 1;
  while (1) {
    if (cnt == n) return 1;
    gu = 0;
    memset(v, 0, sizeof v);
    dfs(1, np);
    if (!gu) return 0;
  }
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 2; i <= n; i++) scanf("%d", a + i);
    for (int i = 2; i <= n; i++) scanf("%d", b + i);
    while (m--) {
      int x, y;
      scanf("%d%d", &x, &y);
      tt[x].push_back(y), tt[y].push_back(x);
    }
    int l = 0, r = 1e9 + 1, ans = -1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (check(mid))
        ans = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++) tt[i].clear();
  }
}