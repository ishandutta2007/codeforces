#include <cstdio>
#include <iostream>
using namespace std;
const int N = 100005, K = 6;
int n, k, m;
bool ok[N][K];
namespace dsu {
int fa[N];
inline int find(int x) {
  while (x != fa[x]) x = fa[x] = fa[fa[x]];
  return x;
}
inline bool merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return 0;
  fa[x] = y;
  return 1;
}
}  // namespace dsu
namespace sgt {
using namespace dsu;
int f[N << 2], fal[N << 2][5], far[N << 2][5];
void build(int i, int l, int r) {
  if (l == r) {
    f[i] = 1;
    fa[l] = fal[i][0] = far[i][0] = l;
    return;
  }
  int mid = (l + r) >> 1;
  build(i << 1, l, mid), build(i << 1 | 1, mid + 1, r);
  f[i] = f[i << 1] + f[i << 1 | 1];
  for (int j = 1; j <= k; j++)
    if (mid + j <= r) {
      int x = mid + j;
      for (int y = j; y <= k; y++)
        if (ok[x][y] && x - y >= l && dsu::merge(x - y, x)) f[i]--;
    }
  for (int j = 0; j < k; j++)
    if (l + j <= r) fal[i][j] = find(l + j), far[i][j] = find(r - j);
}
int query(int i, int l, int r, int x, int y) {
  if (x <= l && y >= r) {
    for (int j = 0; j < k; j++)
      if (l + j <= r)
        fa[l + j] = fa[fal[i][j]] = fal[i][j], fa[r - j] = fa[far[i][j]] = far[i][j];
    return f[i];
  }
  int mid = (l + r) >> 1;
  if (y <= mid) return query(i << 1, l, mid, x, y);
  if (x > mid) return query(i << 1 | 1, mid + 1, r, x, y);
  x = max(x, l), y = min(y, r);
  int ans = query(i << 1, l, mid, x, y) + query(i << 1 | 1, mid + 1, r, x, y);
  for (int j = 1; j <= k; j++)
    if (mid + j <= y) {
      int g = mid + j;
      for (int t = j; t <= k; t++)
        if (ok[g][t] && g - t >= x && merge(g, g - t)) ans--;
    }
  return ans;
}
}  // namespace sgt
int main() {
  cin >> n >> k >> m;
  while (m--) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x > y) swap(x, y);
    ok[y][y - x] = 1;
  }
  sgt::build(1, 1, n);
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", sgt::query(1, 1, n, l, r));
  }
}