#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 200005;
int n, m, up, a[N], b[N], v[N];
int l[N], r[N], ml[N], mr[N];
long long ans;
vector<pair<int, int>> q[N];
struct p {
  int x, v;
  bool operator<(const p &j) const { return v > j.v; }
} c[N];
namespace bits {
int s[N];
inline int lb(int x) { return x & (-x); }
inline void add(int x, int v) {
  while (x <= up) s[x] += v, x += lb(x);
}
inline int query(int l, int r) {
  int ans = 0;
  while (r) ans += s[r], r -= lb(r);
  while (l) ans -= s[l], l -= lb(l);
  return ans;
}
}  // namespace bits
namespace st {
int d[18][N];
void build(int n, int *a) {
  memcpy(d[0], a, (n + 1) << 2);
  for (int j = 1; (1 << j) <= n; j++)
    for (int i = 1; i + (1 << j) - 1 <= n; i++) d[j][i] = min(d[j - 1][i], d[j - 1][i + (1 << (j - 1))]);
}
inline int query(int l, int r) {
  if (l > r) return up;
  int k = __lg(r - l + 1);
  return min(d[k][l], d[k][r - (1 << k) + 1]);
}
}  // namespace st
int main() {
  cin >> n >> m >> up;
  for (int i = 1; i <= n; i++) scanf("%d", a + i), a[i] = min(a[i], up);
  for (int i = 1; i <= m; i++) scanf("%d", b + i), b[i] = min(b[i], up);
  r[0] = 1, l[m + 1] = m;
  for (int i = 1; i <= m; i++) {
    l[i] = i - 1, r[i] = i + 1;
    ml[i] = max(b[i], b[i - 1]), mr[i] = max(b[i], b[i + 1]);
    c[i] = p{i, b[i]};
  }
  sort(c + 1, c + m + 1), st::build(m, b);
  for (int i = 1; i <= m; i++) {
    int x = c[i].x;
    if (l[x] && ml[x] < up) q[up - ml[x]].push_back(make_pair(up - st::query(l[x] + 1, x - 1), up - b[x]));
    if (r[x] <= m && mr[x] < up) q[up - mr[x]].push_back(make_pair(up - st::query(x + 1, r[x] - 1), up - b[x]));
    l[r[x]] = l[x], ml[r[x]] = max(ml[r[x]], ml[x]);
    r[l[x]] = r[x], mr[l[x]] = max(mr[l[x]], mr[x]);
  }
  r[0] = 1, l[n + 1] = n;
  for (int i = 1; i <= n; i++) {
    l[i] = i - 1, r[i] = i + 1;
    ml[i] = max(a[i], a[i - 1]), mr[i] = max(a[i], a[i + 1]);
    c[i] = p{i, a[i]};
  }
  for (int i = 1; i < n; i++) bits::add(max(a[i], a[i + 1]), 1);
  sort(c + 1, c + n + 1);
  for (int i = up, j = 1; i; i--) {
    for (auto tp : q[i]) ans += bits::query(tp.first, tp.second);
    while (j <= n && c[j].v == i) {
      int x = c[j++].x;
      if (l[x]) bits::add(ml[x], -1);
      if (r[x] <= n) bits::add(mr[x], -1);
      if (l[x] && r[x] <= n) bits::add(max(ml[x], mr[x]), 1);
      l[r[x]] = l[x], ml[r[x]] = max(ml[r[x]], ml[x]);
      r[l[x]] = r[x], mr[l[x]] = max(mr[l[x]], mr[x]);
    }
  }
  memcpy(v, b, (m + 1) << 2), sort(v + 1, v + m + 1);
  for (int i = 1; i <= n; i++) ans += upper_bound(v + 1, v + m + 1, up - a[i]) - v - 1;
  for (int i = 1; i < n; i++) ans -= upper_bound(v + 1, v + m + 1, up - max(a[i], a[i + 1])) - v - 1;
  memcpy(v, a, (n + 1) << 2), sort(v + 1, v + n + 1);
  for (int i = 1; i < m; i++) ans -= upper_bound(v + 1, v + n + 1, up - max(b[i], b[i + 1])) - v - 1;
  cout << ans;
}