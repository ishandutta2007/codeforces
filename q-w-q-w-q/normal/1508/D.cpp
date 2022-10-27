#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
int n, rt, rx, ry, cnt;
int fa[2001], k, x[4001], y[4001], mp[2001];
inline void add(int a, int b) { k++, x[k] = a, y[k] = b; }
struct pt {
  int x, y, v, id;
  bool operator<(const pt &j) const {
    if (id == rt)
      return 1;
    if (j.id == rt)
      return 0;
    return atan2(y - ry, x - rx) < atan2(j.y - ry, j.x - rx);
  }
} a[2001];
inline int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    fa[i] = i;
  for (int i = 1; i <= n; i++) {
    cnt++;
    cin >> a[cnt].x >> a[cnt].y >> a[cnt].v, a[cnt].id = i;
    if (a[cnt].v == i) {
      cnt--;
      continue;
    }
    if (rt == 0 || rx > a[cnt].x)
      rt = i, rx = a[cnt].x, ry = a[cnt].y;
    fa[i] = find(a[cnt].v);
  }
  if (!rt) {
    cout << 0;
    return 0;
  }
  n = cnt;
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++)
    mp[a[i].id] = i;
  for (int i = 2; i < n; i++)
    if (find(a[i].id) != find(a[i + 1].id)) {
      fa[find(a[i].id)] = a[i + 1].id;
      add(a[i].id, a[i + 1].id);
      swap(a[i].v, a[i + 1].v);
    }
  for (int i = 1, j; i < n; i++) {
    j = mp[a[1].v];
    add(a[1].id, a[1].v);
    swap(a[1].v, a[j].v);
  }
  cout << k << endl;
  for (int i = 1; i <= k; i++)
    cout << x[i] << ' ' << y[i] << endl;
}