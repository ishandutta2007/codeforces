#include <bits/stdc++.h>

using namespace std;

const int N = 100100, MOD = 1000000007, base = 10007;

int n, m, k;
char a[N];
long long f[N], g[10][N];
long long t[N * 4];
int b[N * 4];

void build(int node, int l, int r) {
  b[node] = -1;
  if (l == r) {
    t[node] = a[l] - '0';
    return;
  }
  int m = (l + r) >> 1;
  build(node + node, l, m);
  build(node + node + 1, m + 1, r);
  t[node] = (t[node + node] * f[r - m] + t[node + node + 1]) % MOD;
}

void update(int node, int l, int r, int x, int y, int val) {
  if (x > r || y < l) {
    return;
  }
  if (x <= l && r <= y) {
    b[node] = val;
    t[node] = g[val][r - l + 1];
    return;
  }
  int m = (l + r) >> 1;
  int node_l = node << 1;
  int node_r = node_l + 1;
  if (b[node] != -1) {
    b[node_l] = b[node_r] = b[node];
    t[node_l] = g[b[node]][m - l + 1];
    t[node_r] = g[b[node]][r - m];
    b[node] = -1;
  }
  update(node_l, l, m, x, y, val);
  update(node_r, m + 1, r, x, y, val);
  t[node] = (t[node + node] * f[r - m] + t[node + node + 1]) % MOD;
}

long long get(int node, int l, int r, int x, int y) {
  if (x > r || y < l) {
    return 0;
  }
  if (x <= l && r <= y) {
    return t[node] * f[y - r] % MOD;
  }
  int m = (l + r) >> 1;
  int node_l = node << 1;
  int node_r = node_l + 1;
  if (b[node] != -1) {
    b[node_l] = b[node_r] = b[node];
    t[node_l] = g[b[node]][m - l + 1];
    t[node_r] = g[b[node]][r - m];
    b[node] = -1;
  }
  long long p1 = get(node_l, l, m, x, y);
  long long p2 = get(node_r, m + 1, r, x, y);
  return (p1 + p2) % MOD;
}

int main() {
  //ios_base::sync_with_stdio(0);
  #ifdef Doflamingo
  freopen("input.txt", "r", stdin);
  #endif // Doflamingo
  scanf("%d %d %d", &n, &m, &k);
  m += k;
  scanf("%s", a + 1);
  f[0] = 1;
  for (int i = 1; i <= n; i++) {
    f[i] = f[i - 1] * base % MOD;
  }
  for  (int i = 0; i <= 9; i++) {
    g[i][0] = 0;
    for (int j = 1; j <= n; j++) {
      g[i][j] = (g[i][j - 1] * base + i) % MOD;
    }
  }
  build(1, 1, n);
  while (m--) {
    int type, l, r, d;
    scanf("%d %d %d %d", &type, &l, &r, &d);
    if (type == 1) {
      update(1, 1, n, l, r, d);
    } else {
      if (d == r - l + 1) {
        puts("YES");
        continue;
      }
      int l1 = l + d;
      int r1 = r - d;
      long long x = get(1, 1, n, l, r1);
      long long y = get(1, 1, n, l1, r);
      if (x == y) {
        puts("YES");
      } else {
        puts("NO");
      }
    }
  }
  return 0;
}