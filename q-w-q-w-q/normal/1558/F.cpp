#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 200005;
int t, n, a[N], p[N];
namespace sgt {
int lazy[N << 3], mx[N << 3];
void build(int i, int l, int r) {
  lazy[i] = mx[i] = 0;
  if (l == r) {
    int tp = r + (r % 2 == 0);
    mx[i] = -((2 * n - 1 - tp) / 2 + 1);
    return;
  }
  int mid = (l + r) >> 1;
  build(i << 1, l, mid), build(i << 1 | 1, mid + 1, r);
  mx[i] = max(mx[i << 1], mx[i << 1 | 1]);
}
void modify(int i, int l, int r, int x, int z) {
  if (l > x) return;
  if (r <= x) {
    lazy[i] += z, mx[i] += z;
    return;
  }
  int mid = (l + r) >> 1;
  modify(i << 1, l, mid, x, z), modify(i << 1 | 1, mid + 1, r, x, z);
  mx[i] = max(mx[i << 1], mx[i << 1 | 1]) + lazy[i];
}
int query(int i, int l, int r, int x, int y) {
  if (x <= l && y >= r) return mx[i];
  int mid = (l + r) >> 1;
  if (y <= mid) return lazy[i] + query(i << 1, l, mid, x, y);
  if (x > mid) return lazy[i] + query(i << 1 | 1, mid + 1, r, x, y);
  return lazy[i] + max(query(i << 1, l, mid, x, y), query(i << 1 | 1, mid + 1, r, x, y));
}
}  // namespace sgt
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", a + i), p[a[i]] = i;
    sgt::build(1, 1, 2 * n - 1);
    int ans = 0;
    for (int i = 1, x = 1, t = 0; i < n; i++) {
      while (a[x] <= i) x++;
      int y = p[i];
      t = max(t, y);
      sgt::modify(1, 1, 2 * n - 1, 2 * y - 1, 2);
      if (y % 2 == 0 && a[y + 1] < i) {
        sgt::modify(1, 1, 2 * n - 1, 2 * y, -1);
        sgt::modify(1, 1, 2 * n - 1, 2 * y - 1, 1);
      }
      if (y % 2 == 1 && a[y - 1] > i) {
        sgt::modify(1, 1, 2 * n - 1, 2 * y - 2, 1);
        sgt::modify(1, 1, 2 * n - 1, 2 * y - 3, -1);
      }
      if (t == i) continue;
      int tp = sgt::query(1, 1, 2 * n - 1, 2 * x - 1, 2 * t - 1) - sgt::query(1, 1, 2 * n - 1, 2 * t - 1, 2 * t - 1);
      ans = max(ans, t - i + tp);
    }
    cout << ans << endl;
    memset(a + 1, 0, n << 2);
  }
}