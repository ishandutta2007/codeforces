#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

typedef long long i64;

const int N = 100005;
int n, m, b[N], k[N];
int v[N], vb[N], cnt, sb[N];
vector<int> a[N];

namespace sgt {
int lazy[N << 2], mn[N << 2];

void build(int i, int l, int r) {
  lazy[i] = 0, mn[i] = sb[r];
  if (l == r)
    return;

  int mid = (l + r) >> 1;
  build(i << 1, l, mid), build(i << 1 | 1, mid + 1, r);
}

void modify(int i, int l, int r, int x, int y) {
  if (x >= r) {
    mn[i] += y, lazy[i] += y;
    return;
  }

  int mid = (l + r) >> 1;
  if (x > mid)
    modify(i << 1 | 1, mid + 1, r, x, y);
  modify(i << 1, l, mid, x, y);
  mn[i] = min(mn[i << 1], mn[i << 1 | 1]) + lazy[i];
}

int query(int i, int l, int r, int x, int y) {
  if (x > y)
    return 1 << 30;
  if (x <= l && y >= r)
    return mn[i];
  int mid = (l + r) >> 1, tp = 1 << 30;
  if (x <= mid)
    tp = query(i << 1, l, mid, x, y);
  if (y > mid)
    tp = min(tp, query(i << 1 | 1, mid + 1, r, x, y));
  return tp + lazy[i];
}
} // namespace sgt

void solve() {
  cin >> m >> n;
  for (int i = 1; i <= m; i++)
    cin >> b[i];
  sort(b + 1, b + m + 1, greater<int>());
  reverse(b + 1, b + n + 1);

  for (int i = 1; i <= n; i++) {
    if (b[i] != b[i - 1])
      cnt++, vb[cnt] = b[i], sb[cnt] = 1;
    else
      sb[cnt]++;
  }
  cnt++, vb[cnt] = 1 << 30;
  for (int i = cnt - 1; i; i--)
    sb[i] += sb[i + 1];
  sgt::build(1, 1, cnt);

  for (int i = 1; i <= n; i++) {
    cin >> k[i];
    a[i].resize(k[i]);
    i64 s = 0;
    for (int j = 0; j < k[i]; j++) {
      cin >> a[i][j];
      s += a[i][j];
    }
    v[i] = (s - 1) / k[i] + 1;
    v[i] = lower_bound(vb + 1, vb + cnt + 1, v[i]) - vb;
    sgt::modify(1, 1, cnt, v[i], -1);
  }

  for (int i = 1; i <= n; i++) {
    sgt::modify(1, 1, cnt, v[i], 1);
    i64 s = 0;
    for (int j = 0; j < k[i]; j++)
      s += a[i][j];
    for (int j = 0; j < k[i]; j++) {
      int tp = (s - a[i][j] - 1) / (k[i] - 1) + 1;
      tp = lower_bound(vb + 1, vb + cnt + 1, tp) - vb;
      if (sgt::query(1, 1, cnt, 1, tp) < 1 || sgt::query(1, 1, cnt, tp + 1, cnt) < 0)
        cout << '0';
      else
        cout << '1';
    }
    sgt::modify(1, 1, cnt, v[i], -1);
  }
  cout << '\n';
}

void clear() {
  for (int i = 1; i <= n; i++)
    a[i].clear();
  for (int i = 1; i <= cnt; i++)
    sb[i] = vb[i] = 0;
  cnt = 0;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
    clear();
  }
}