#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

const int N = 10000005, Q = 100005;
int n, m, t, w, q, lgt, lb;
int a[N], p[Q];
int fa[N], sz[N], v[N];
int lt[N];
int tot, cnt;
bool u[N];

pair<int, int> query(int x) {
  x &= lb - 1, x = lb - 1 - x;
  int y = (x & t) ^ t;
  if (!y)
    return {x & ((1 << lgt) - 1), lb};
  y = ((1 << __lg(y)) - 1) & t;
  if (!y)
    return {x & ((1 << lgt) - 1), lb};
  y = __lg(y);
  return {x & ((1 << lgt) - 1), (t & (~((1 << (y + 1)) - 1))) | (x & ((1 << y) - 1))};
}

int findd(int x) {
  while (x != fa[x])
    x = fa[x] = fa[fa[x]];
  return x;
}

int find(int x) {
  while (x != fa[x])
    x = fa[x];
  return x;
}

vector<pair<int, int>> ad[Q << 2];

void add(int i, int l, int r, int x, int y, pair<int, int> z) {
  if (x <= l && y >= r) {
    ad[i].push_back(z);
    return;
  }

  int mid = (l + r) >> 1;
  if (x <= mid)
    add(i << 1, l, mid, x, y, z);
  if (y > mid)
    add(i << 1 | 1, mid + 1, r, x, y, z);
}

void solve(int i, int l, int r) {
  vector<pair<int, pair<int, int>>> cg;
  int re = 0;
  for (auto tp : ad[i]) {
    auto tt = query(tp.first);
    int x = find(tt.first), y = find(tt.second);
    if (tp.second != -1) {
      if (x == y)
        continue;
      cnt -= v[x] != 0, v[x] ^= tp.second, cnt += v[x] != 0;
      cnt -= v[y] != 0, v[y] ^= tp.second, cnt += v[y] != 0;
      cg.push_back({tp.second, {x, y}});
    } else {
      if (x == y)
        tot++, re++;
      else {
        if (sz[x] < sz[y])
          swap(x, y);
        sz[x] += sz[y], fa[y] = x;
        cnt -= v[x] != 0, cnt -= v[y] != 0;
        v[x] ^= v[y], cnt += v[x] != 0;
        cg.push_back({-1, {x, y}});
      }
    }
  }

  if (l == r) {
    auto power = [&](int a, int n, int mod) {
      int tp = 1;
      while (n) {
        if (n & 1)
          tp = 1ll * tp * a % mod;
        a = 1ll * a * a % mod, n >>= 1;
      }
      return tp;
    };

    if (cnt)
      cout << "0\n";
    else
      cout << power(1 << w, tot, p[l]) << '\n';
  } else {
    int mid = (l + r) >> 1;
    solve(i << 1, l, mid), solve(i << 1 | 1, mid + 1, r);
  }

  tot -= re, reverse(cg.begin(), cg.end());
  for (auto tp : cg) {
    int x = tp.second.first, y = tp.second.second;
    if (tp.first != -1) {
      cnt -= v[x] != 0, v[x] ^= tp.first, cnt += v[x] != 0;
      cnt -= v[y] != 0, v[y] ^= tp.first, cnt += v[y] != 0;
    } else {
      sz[x] -= sz[y], fa[y] = y;
      cnt -= v[x] != 0, v[x] ^= v[y];
      cnt += v[x] != 0, cnt += v[y] != 0;
    }
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n >> m >> t >> w, t = min(t, lb = n & (-n));
  lgt = __lg(t);
  for (int i = 0; i <= lb; i++)
    fa[i] = i, sz[i] = 1;
  fill(a, a + n, -1), fill(lt, lt + n, 1);
  for (int i = 1; i <= m; i++) {
    int x;
    cin >> x;
    cin >> a[x - 1];
  }

  cin >> q;
  for (int i = 1; i <= q; i++) {
    int x, y;
    cin >> x >> y >> p[i], x--;
    if (i != 1)
      add(1, 1, q, lt[x], i - 1, {x, a[x]});
    a[x] = y, lt[x] = i;
  }

  for (int i = 0; i != n; i++)
    if (a[i] == -1 && lt[i] == 1) {
      pair<int, int> tp = query(i);
      int x = findd(tp.first), y = findd(tp.second);
      if (x == y)
        tot++;
      else
        fa[x] = y;
    } else
      add(1, 1, q, lt[i], q, {i, a[i]});

  for (int i = 0; i <= lb; i++)
    findd(i);

  solve(1, 1, q);
}