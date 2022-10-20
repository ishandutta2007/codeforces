#include <bits/stdc++.h>

using namespace std;

const int N = 30000, p = 1e7 + 19, MOD = 1e9 + 7;

int n, k;
int v[N], w[N], boundl[N], boundr[N], f[N];
int numquery, res[N];
vector <int> t[N * 4];
int dp[50][1010], cur;

inline int add(int u, int v) {
  u += v;
  if (u >= MOD) {
    u -= MOD;
  }
  return u;
}

inline int mul(int u, int v) {
  return (long long) u * v % MOD;
}

void modify(int node, int l, int r, int x, int y, int id) {
  if (x > r || y < l) {
    return;
  }
  if (x <= l && r <= y) {
    t[node].push_back(id);
    return;
  }
  int m = (l + r) >> 1;
  modify(node + node, l, m, x, y, id);
  modify(node + node + 1, m + 1, r, x , y, id);
}

void go(int node, int l, int r) {
  cur++;
  for (int i = 0; i <= k; i++) {
    dp[cur][i] = dp[cur - 1][i];
  }
  for (int u : t[node]) {
    for (int i = k; i; i--) {
      if (i - w[u] >= 0) {
        dp[cur][i] = max(dp[cur][i], dp[cur][i - w[u]] + v[u]);
      }
    }
  }
  if (l == r) {
    //getres
    for (int i = 1; i <= k; i++) {
      res[l] = add(res[l], mul(f[i - 1], dp[cur][i]));
    }
    cur--;
    return;
  }
  int m = (l + r) >> 1;
  go(node + node, l, m);
  go(node + node + 1, m + 1, r);
  cur--;
}

int main() {
  //freopen("input.txt", "r", stdin);
  scanf("%d %d", &n, &k);
  f[0] = 1;
  for (int i = 1; i <= k; i++) {
    f[i] = mul(f[i - 1], p);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", v + i, w + i);
    boundl[i] = 1;
    boundr[i] = -1;
  }
  int q;
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int op = 0;
    scanf("%d", &op);
    if (op == 1) {
      n++;
      scanf("%d %d", v + n, w + n);
      boundl[n] = numquery + 1;
      boundr[n] = -1;
    }
    if (op == 2) {
      int x;
      scanf("%d", &x);
      boundr[x] = numquery;
    }
    if (op == 3) {
      numquery++;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (boundr[i] == -1) {
      boundr[i] = numquery;
    }
    modify(1, 1, numquery, boundl[i], boundr[i], i);
  }
  go(1, 1, numquery);
  for (int i = 1; i <= numquery; i++) {
    printf("%d\n", res[i]);
  }
  return 0;
}