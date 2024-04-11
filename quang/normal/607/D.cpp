#include <bits/stdc++.h>

using namespace std;

const int N = 200010, MOD = 1000000007;

int n;
int v[N], cnt[N], x[N], par[N];
vector <int> a[N];
int query[N], op[N];
int in[N], out[N], top;
int sum[N * 4], t[N * 4];

inline int mul(int u, int v) {
  return 1ll * u * v % MOD;
}

int Power(int u, int v) {
  int res = 1;
  while (v) {
    if (v & 1) {
      res = mul(res, u);
    }
    u = mul(u, u);
    v >>= 1;
  }
  return res;
}

inline int add(int u, int v) {
  u += v;
  if (u >= MOD) {
    u -= MOD;
  }
  return u;
}

inline int inv(int u) {
  return Power(u, MOD - 2);
}

void dfs(int u) {
  in[u] = ++top;
  for (int v : a[u]) {
    if (!in[v]) {
      dfs(v);
    }
  }
  out[u] = top;
}

void build(int node, int l, int r) {
  if (l == r) {
    sum[node] = 0;
    t[node] = 1;
    return;
  }
  int m = (l + r) >> 1;
  build(node + node, l, m);
  build(node + node + 1, m + 1, r);
  t[node] = 1;
  sum[node] = 0;
}

void refresh(int u) {
  sum[u] = add(mul(sum[u + u], t[u + u]), mul(sum[u + u + 1], t[u + u + 1]));
}

void addnode(int node, int l, int r, int id, int val) {
  if (id > r || id < l) {
    return;
  }
  if (l == r) {
    sum[node] = val;
    return;
  }
  int m = (l + r) >> 1;
  addnode(node + node, l, m, id, val);
  addnode(node + node + 1, m + 1, r, id, val);
  refresh(node);
}

void update(int node, int l, int r, int x, int y, int id) {
  if (x > r || y < l) {
    return;
  }
  if (x <= l && r <= y) {
    t[node] = mul(t[node], inv(cnt[id]));
    t[node] = mul(t[node], cnt[id] + 1);
    return;
  }
  int m = (l + r) >> 1;
  update(node + node, l, m, x, y, id);
  update(node + node + 1, m + 1, r, x, y, id);
  refresh(node);
}

int getans(int node, int l, int r, int x, int y) {
  if (x > r || y < l) {
    return 0;
  }
  if (x <= l && r <= y) {
    return mul(t[node], sum[node]);
  }
  int m = (l + r) >> 1;
  int p1 = getans(node + node, l, m, x, y);
  int p2 = getans(node + node + 1, m + 1, r, x, y);
  p1 = add(p1, p2);
  return mul(p1, t[node]);
}

struct bit {
  int t[N];

  void init() {
    for (int i = 1; i <= n; i++) {
      t[i] = 1;
    }
  }

  int get(int x) {
    int res = 1;
    while (x) {
      res = mul(res, t[x]);
      x -= (x & -x);
    }
    return res;
  }

  void add(int x, int v) {
    while (x <= n) {
      t[x] = mul(t[x], v);
      x += (x & -x);
    }
  }
} T;

int main() {
  //freopen("input.txt", "r", stdin);
  int q;
  scanf("%d %d", v + 1, &q);
  n = 1;
  for (int i = 1; i <= q; i++) {
    scanf("%d", op + i);
    if (op[i] == 1) {
      int p, val;
      scanf("%d %d", &p, &val);
      a[p].push_back(++n);
      v[n] = val;
      x[i] = n;
      par[n] = p;
    } else {
      scanf("%d", query + i);
    }
  }
  T.init();
  dfs(1);
  build(1, 1, n);
  addnode(1, 1, n, in[1], v[1]);
  cnt[1] = 1;
  for (int i = 1; i <= q; i++) {
    if (op[i] == 1) {
      update(1, 1, n, in[par[x[i]]], out[par[x[i]]], par[x[i]]);
      int nowpar = par[x[i]];
      T.add(in[nowpar], cnt[nowpar] + 1);
      T.add(in[nowpar], inv(cnt[nowpar]));
      T.add(out[nowpar] + 1, cnt[nowpar]);
      T.add(out[nowpar] + 1, inv(cnt[nowpar] + 1));
      cnt[par[x[i]]]++;
      addnode(1, 1, n, in[x[i]], v[x[i]]);
      cnt[x[i]] = 1;
    } else {
      if (query[i] == 1) {
        printf("%d\n", mul(t[1], sum[1]));
      } else {
        int res = getans(1, 1, n, in[query[i]], out[query[i]]);
        int foo = T.get(in[par[query[i]]]);
        res = mul(res, inv(foo));
        printf("%d\n", res);
      }
    }
  }
    return 0;
}