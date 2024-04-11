#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

int n;
vector <int> a[N];
int in[N], out[N], cnt, f[N];
bool t[N * 4], b[N * 4];

void dfs(int u, int p) {
  f[u] = p;
  in[u] = ++cnt;
  for (int v : a[u]) {
    if (v == p) {
      continue;
    }
    dfs(v, u);
  }
  out[u] = cnt;
}

void build(int node, int l, int r) {
  if (l == r) {
    b[node] = 0;
    t[node] = 1;
    return;
  }
  int m = (l + r) >> 1;
  build(node * 2, l, m);
  build(node * 2 + 1, m + 1, r);
  b[node] = 0;
  t[node] = 1;
}

void mark(int node, int l, int r, int id) {
  if (id > r || id < l) {
    return;
  }
  if (l == r) {
    t[node] = 1;
    return;
  }
  int m = (l + r) >> 1;
  if (b[node]) {
    t[node * 2] = 0;
    t[node * 2 + 1] = 0;
    b[node * 2] = b[node * 2 + 1] = 1;
    b[node] = 0;
  }
  mark(node * 2, l, m, id);
  mark(node * 2 + 1, m + 1, r, id);
  t[node] = t[node * 2] | t[node * 2 + 1];
}

void update(int node, int l, int r, int x, int y) {
  if (x > r || y < l) {
    return;
  }
  if (x <= l && r <= y) {
    b[node] = 1;
    t[node] = 0;
    return;
  }
  int m = (l + r) >> 1;
  if (b[node]) {
    t[node * 2] = 0;
    t[node * 2 + 1] = 0;
    b[node * 2] = b[node * 2 + 1] = 1;
    b[node] = 0;
  }
  update(node * 2, l, m, x, y);
  update(node * 2 + 1, m + 1, r, x, y);
  t[node] = t[node * 2] | t[node * 2 + 1];
}

bool check(int node, int l, int r, int x, int y) {
  if (x > r || y < l) {
    return 0;
  }
  if (x <= l && r <= y) {
    return t[node];
  }
  int m = (l + r) >> 1;
  if (b[node]) {
    t[node * 2] = 0;
    t[node * 2 + 1] = 0;
    b[node * 2] = b[node * 2 + 1] = 1;
    b[node] = 0;
  }
  bool p1 = check(node * 2, l, m, x, y);
  bool p2 = check(node * 2 + 1, m + 1, r, x, y);
  return p1 | p2;
}

int main() {
  //ios_base::sync_with_stdio(0);
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    a[u].push_back(v);
    a[v].push_back(u);
  }
  dfs(1, 0);
  build(1, 1, n);
  int q;
  scanf("%d", &q);
  while (q--) {
    int c, v;
    scanf("%d %d", &c, &v);
    if (c == 1) {
      bool foo = check(1, 1, n, in[v], out[v]);
      if (foo) {
        update(1, 1, n, in[v], out[v]);
        if (f[v]) {
          mark(1, 1, n, in[f[v]]);
        }
      }
    }
    if (c == 2) {
      mark(1, 1, n, in[v]);
    }
    if (c == 3) {
      bool foo = check(1, 1, n, in[v], out[v]);
      printf("%d\n", foo ? 0 : 1);
    }
  }
  return 0;
}