#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 150005;
int n, q, len;
int l[N], r[N], op[N], s[N][26], mx[N][26];
int v[N][26];
int sz[N], son[N];
int fa[N], top[N], d[N];
int cnt, lt[N], rt[N];
int tot, dfn[N], val[N];
int mp[N];

namespace sgt {
int lazy[N << 2][26], f[N << 2][26];

void update(int i) {
  for (int j = 0; j < 26; j++)
    f[i][j] = max(f[i << 1][j], f[i << 1 | 1][j]);
}

void pushdown(int i) {
  for (int j = 0; j < 26; j++) {
    int x = lazy[i][j];
    lazy[i << 1][j] += x, lazy[i << 1 | 1][j] += x;
    f[i << 1][j] += x, f[i << 1 | 1][j] += x;
    lazy[i][j] = 0;
  }
}

void build(int i, int l, int r) {
  if (l == r) {
    memcpy(f[i], v[l], sizeof v[l]);
    return;
  }

  int mid = (l + r) >> 1;
  build(i << 1, l, mid), build(i << 1 | 1, mid + 1, r);
  update(i);
}

void modify(int i, int l, int r, int x, int y, int add, int sub) {
  if (x <= l && y >= r) {
    if (add != -1)
      f[i][add]++, lazy[i][add]++;
    if (sub != -1)
      f[i][sub]--, lazy[i][sub]--;
    return;
  }

  pushdown(i);

  int mid = (l + r) >> 1;
  if (x <= mid)
    modify(i << 1, l, mid, x, y, add, sub);
  if (y > mid)
    modify(i << 1 | 1, mid + 1, r, x, y, add, sub);

  if (add != -1)
    f[i][add] = max(f[i << 1][add], f[i << 1 | 1][add]);
  if (sub != -1)
    f[i][sub] = max(f[i << 1][sub], f[i << 1 | 1][sub]);
}

int query(int i, int l, int r, int x, int y, int op) {
  if (x <= l && y >= r)
    return f[i][op];
  pushdown(i);

  int mid = (l + r) >> 1;
  if (y <= mid)
    return query(i << 1, l, mid, x, y, op);
  if (x > mid)
    return query(i << 1 | 1, mid + 1, r, x, y, op);
  return max(query(i << 1, l, mid, x, y, op), query(i << 1 | 1, mid + 1, r, x, y, op));
}

int findl(int i, int l, int r, int x, int op, int v) {
  if (l > x)
    return -1;
  if (r <= x) {
    if (f[i][op] <= v)
      return -1;
    if (l == r)
      return l;
    pushdown(i);
    int mid = (l + r) >> 1;
    if (f[i << 1 | 1][op] > v)
      return findl(i << 1 | 1, mid + 1, r, x, op, v);
    return findl(i << 1, l, mid, x, op, v);
  }

  int mid = (l + r) >> 1;
  pushdown(i);
  int tp = findl(i << 1 | 1, mid + 1, r, x, op, v);
  if (tp != -1)
    return tp;
  return findl(i << 1, l, mid, x, op, v);
}

int findr(int i, int l, int r, int x, int op, int v) {
  if (r < x)
    return -1;
  if (l >= x) {
    if (f[i][op] <= v)
      return -1;
    if (l == r)
      return l;
    pushdown(i);
    int mid = (l + r) >> 1;
    if (f[i << 1][op] > v)
      return findr(i << 1, l, mid, x, op, v);
    return findr(i << 1 | 1, mid + 1, r, x, op, v);
  }

  int mid = (l + r) >> 1;
  pushdown(i);
  int tp = findr(i << 1, l, mid, x, op, v);
  if (tp != -1)
    return tp;
  return findr(i << 1 | 1, mid + 1, r, x, op, v);
}
} // namespace sgt

namespace sgt2 {
int mn[N << 2], lazy[N << 2];

void build(int i, int l, int r) {
  if (l == r) {
    mn[i] = val[l];
    return;
  }

  int mid = (l + r) >> 1;
  build(i << 1, l, mid), build(i << 1 | 1, mid + 1, r);
  mn[i] = min(mn[i << 1], mn[i << 1 | 1]);
}

void modify(int i, int l, int r, int x, int y, int z) {
  if (x <= l && y >= r) {
    mn[i] += z, lazy[i] += z;
    return;
  }

  int mid = (l + r) >> 1;
  if (x <= mid)
    modify(i << 1, l, mid, x, y, z);
  if (y > mid)
    modify(i << 1 | 1, mid + 1, r, x, y, z);
  mn[i] = min(mn[i << 1], mn[i << 1 | 1]) + lazy[i];
}
} // namespace sgt2

int lca(int x, int y) {
  while (top[x] != top[y]) {
    if (d[top[x]] < d[top[y]])
      swap(x, y);
    x = fa[top[x]];
  }
  return d[x] < d[y] ? x : y;
}

void dfs(int i, int d) {
  if (i != 1 && op[i] != -1)
    s[i][op[i]]++;
  sz[i] = 1;

  lt[i] = cnt + 1;
  if (!l[i]) {
    if (len && len != d) {
      while (q--)
        cout << "Fou\n";
      exit(0);
    }
    cnt++;
    mp[cnt] = i;
    memcpy(v[cnt], s[i], sizeof s[i]);
    memcpy(mx[i], s[i], sizeof s[i]);
    len = d;
  } else {
    memcpy(s[l[i]], s[i], sizeof s[i]);
    dfs(l[i], d + 1);
    son[i] = l[i];
    sz[i] += sz[l[i]];
    memcpy(mx[i], mx[l[i]], sizeof mx[l[i]]);

    if (r[i]) {
      memcpy(s[r[i]], s[i], sizeof s[i]);
      dfs(r[i], d + 1);
      if (sz[l[i]] < sz[r[i]])
        son[i] = r[i];
      sz[i] += sz[r[i]];
      for (int j = 0; j < 26; j++)
        mx[i][j] = max(mx[i][j], mx[r[i]][j]);
    }
  }
  rt[i] = cnt;
}

void dfs2(int i, int tp) {
  top[i] = tp;
  if (i != 1)
    d[i] = d[fa[i]] + 1;
  dfn[i] = ++tot, val[tot] = len - d[i];
  for (int j = 0; j < 26; j++)
    val[tot] -= mx[i][j] - s[i][j];

  if (son[i]) {
    fa[son[i]] = i;
    dfs2(son[i], tp);
  }
  if (l[i] && l[i] != son[i]) {
    fa[l[i]] = i;
    dfs2(l[i], l[i]);
  }
  if (r[i] && r[i] != son[i]) {
    fa[r[i]] = i;
    dfs2(r[i], r[i]);
  }
}

void modify(int x, int x1, int x2, int v) {
  if (x1 == -1)
    x1 = 0;
  else
    x1 = lca(x, x1);
  if (x2 == -1)
    x2 = 0;
  else
    x2 = lca(x, x2);
  int y = x1;
  if (dfn[x2] > dfn[y])
    y = x2;
  x = fa[x];
  while (1) {
    if (x == y)
      return;

    if (dfn[top[x]] > dfn[y]) {
      sgt2::modify(1, 1, n, dfn[top[x]], dfn[x], v);
      x = fa[top[x]];
    } else {
      sgt2::modify(1, 1, n, dfn[y] + 1, dfn[x], v);
      return;
    }
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n >> q;
  for (int i = 2; i <= n; i++) {
    int x;
    char c;
    cin >> x >> c;
    if (l[x])
      r[x] = i;
    else
      l[x] = i;

    if (c == '?')
      op[i] = -1;
    else
      op[i] = c - 'a';
  }

  dfs(1, 0);
  dfs2(1, 1);
  sgt::build(1, 1, cnt);
  sgt2::build(1, 1, n);

  while (q--) {
    int x, y;
    char c;
    cin >> x >> c;
    if (c == '?')
      y = -1;
    else
      y = c - 'a';

    if (op[x] != -1) {
      int v = sgt::query(1, 1, cnt, lt[x], rt[x], op[x]);
      v--;
      sgt::modify(1, 1, cnt, lt[x], rt[x], -1, op[x]);
      int _l = sgt::findl(1, 1, cnt, lt[x] - 1, op[x], v);
      int _r = sgt::findr(1, 1, cnt, rt[x] + 1, op[x], v);
      if (_l != -1)
        _l = mp[_l];
      if (_r != -1)
        _r = mp[_r];
      modify(x, _l, _r, 1);
    }
    if (y != -1) {
      int v = sgt::query(1, 1, cnt, lt[x], rt[x], y);
      sgt::modify(1, 1, cnt, lt[x], rt[x], y, -1);
      int _l = sgt::findl(1, 1, cnt, lt[x] - 1, y, v);
      int _r = sgt::findr(1, 1, cnt, rt[x] + 1, y, v);
      if (_l != -1)
        _l = mp[_l];
      if (_r != -1)
        _r = mp[_r];
      modify(x, _l, _r, -1);
    }
    op[x] = y;

    if (sgt2::mn[1] < 0)
      cout << "Fou\n";
    else {
      int s = 0;
      for (int i = 0; i < 26; i++)
        s += sgt::f[1][i];
      int ans = 0;
      for (int i = 0; i < 26; i++)
        ans += (i + 1) * (len - s + sgt::f[1][i]);
      cout << "Shi " << ans << '\n';
    }
  }
}