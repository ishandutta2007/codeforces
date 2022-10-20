#include <bits/stdc++.h>

using namespace std;

const int N = 100010, MOD = 95542721, len = 48;

int n;
int a[N], b[N * 4];
int t[N * 4][48];

inline int add(int u, int v) {
  u += v;
  if (u >= MOD) {
    u -= MOD;
  }
  return u;
}

void fix(int node) {
  for (int i = 0; i < len; i++) {
    t[node][i] = add(t[node * 2][i], t[node * 2 + 1][i]);
  }
}

void build(int node, int l, int r) {
  if (l == r) {
    t[node][0] = a[l];
    for (int i = 1; i < len; i++) {
      int x = t[node][i - 1];
      t[node][i] = 1ll * x * x % MOD;
      t[node][i] = 1ll * t[node][i] * x % MOD;
    }
    return;
  }
  int m = (l + r) >> 1;
  build(node * 2, l, m);
  build(node * 2 + 1, m + 1, r);
  fix(node);
}

void go(int node, int cnt) {
  int x = 0;
  int t2[len];
  for (int i = cnt; i < len; i++) {
    t2[x++] = t[node][i];
  }
  for (int i = 0; i < cnt; i++) {
    t2[x++] = t[node][i];
  }
  for (int i = 0; i < len; i++) {
    t[node][i] = t2[i];
  }
}

void update(int node, int l, int r, int x, int y) {
  if (x > r || y < l) {
    return;
  }
  if (x <= l && r <= y) {
    go(node, 1);
    b[node] = (b[node] + 1) % len;
    return;
  }
  int m = (l + r) >> 1;
  if (b[node]) {
    go(node * 2, b[node]);
    go(node * 2 + 1, b[node]);
    b[node * 2] = (b[node * 2] + b[node]) % len;
    b[node * 2 + 1] = (b[node * 2 + 1] + b[node]) % len;
    b[node] = 0;
  }
  update(node * 2, l, m, x, y);
  update(node * 2 + 1, m + 1, r, x, y);
  fix(node);
}

int get(int node, int l, int r, int x, int y) {
  if (x > r || y < l) {
    return 0;
  }
  if (x <= l && r <= y) {
    return t[node][0];
  }
  int m = (l + r) >> 1;
  if (b[node]) {
    go(node * 2, b[node]);
    go(node * 2 + 1, b[node]);
    b[node * 2] = (b[node * 2] + b[node]) % len;
    b[node * 2 + 1] = (b[node * 2 + 1] + b[node]) % len;
    b[node] = 0;
  }
  int p1 = get(node * 2, l, m, x, y);
  int p2 = get(node * 2 + 1, m + 1, r, x, y);
  return add(p1, p2);
}

int main() {
  ios_base::sync_with_stdio(0);
  #ifdef Doflamingo
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif // Doflamingo
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] %= MOD;
  }
  build(1, 1, n);
  int q;
  cin >> q;
  while (q--) {
    int c, l, r;
    cin >> c >> l >> r;
    if (c == 1) {
      printf("%d\n", get(1, 1, n, l, r));
    } else {
      update(1, 1, n, l, r);
    }
  }
  return 0;
}