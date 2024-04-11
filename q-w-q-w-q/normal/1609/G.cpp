#include <cstdio>
#include <iostream>

using namespace std;

typedef long long i64;

const int N = 105, M = 100005;
int n, m, q;
i64 a[N], b[M], da[N], db[M];
i64 f0;

namespace sgt {
i64 s[M << 2], mn[M << 2];
int lazy[M << 2];

void update(int i) {
  s[i] = s[i << 1] + s[i << 1 | 1];
  mn[i] = mn[i << 1];
}

void build(int i, int l, int r) {
  if (l == r) {
    mn[i] = s[i] = db[l];
    return;
  }

  int mid = (l + r) >> 1;
  build(i << 1, l, mid), build(i << 1 | 1, mid + 1, r);
  update(i);
}

void add(int i, int l, int r, int x) {
  lazy[i] += x, mn[i] += x;
  s[i] += 1ll * (r - l + 1) * x;
}

void pushdown(int i, int l, int r) {
  if (lazy[i]) {
    int mid = (l + r) >> 1;
    add(i << 1, l, mid, lazy[i]), add(i << 1 | 1, mid + 1, r, lazy[i]);
    lazy[i] = 0;
  }
}

void modify(int i, int l, int r, int x, int z) {
  if (x <= l) {
    add(i, l, r, z);
    return;
  }

  pushdown(i, l, r);
  int mid = (l + r) >> 1;
  if (x <= mid)
    modify(i << 1, l, mid, x, z);
  modify(i << 1 | 1, mid + 1, r, x, z);

  update(i);
}

i64 query(int i, int l, int r, i64 z) {
  if (mn[i] >= z)
    return s[i] - z * (r - l + 1);
  if (l == r)
    return 0;

  pushdown(i, l, r);
  int mid = (l + r) >> 1;
  if (mn[i << 1 | 1] < z)
    return query(i << 1 | 1, mid + 1, r, z);
  return query(i << 1, l, mid, z) + s[i << 1 | 1] - z * (r - mid);
}
} // namespace sgt

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++)
    cin >> a[i], da[i] = a[i] - a[i - 1];
  for (int i = 1; i <= m; i++)
    cin >> b[i], db[i] = b[i] - b[i - 1];

  for (int i = 1; i <= m; i++)
    f0 += a[1] + b[i];
  for (int i = 2; i <= n; i++)
    f0 += a[i] + b[m];

  sgt::build(1, 2, m);

  while (q--) {
    int op, k, d;
    cin >> op >> k >> d;
    f0 += 1ll * k * (k + 1) / 2 * d;

    if (op == 1) {
      for (int i = n - k + 1; i <= n; i++)
        da[i] += d;
      if (k == n)
        f0 += 1ll * d * (m - 1);
    } else {
      f0 += 1ll * k * d * (n - 1);
      sgt::modify(1, 2, m, m - k + 1, d);
    }

    i64 ans = f0;
    for (int i = 2; i <= n; i++)
      ans -= sgt::query(1, 2, m, da[i]);

    cout << ans << '\n';
  }
}