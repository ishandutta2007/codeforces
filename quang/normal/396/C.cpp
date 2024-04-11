#include <bits/stdc++.h>

using namespace std;

const int N = 300010, MOD = 1000000007;

int n;
vector <int> a[N];
int in[N], out[N], cnt, h[N];

void dfs(int u) {
  in[u] = ++cnt;
  for (int v : a[u]) {
    h[v] = h[u] + 1;
    dfs(v);
  }
  out[u] = cnt;
}

inline int qadd(int u, int v) {
  u += v;
  if (u >= MOD) {
    u -= MOD;
  }
  if (u < 0) {
    u += MOD;
  }
  return u;
}

inline int mul(int u, int v) {
  return (long long) u * v % MOD;
}

struct bit {
  int t[N];

  void add(int x, int v) {
    while (x < N) {
      t[x] = qadd(t[x], v);
      x += (x & -x);
    }
  }

  int get(int x) {
    int res = 0;
    while (x) {
      res = qadd(res, t[x]);
      x -= (x & -x);
    }
    return res;
  }
} t, tk;

int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    int u;
    scanf("%d", &u);
    a[u].push_back(i);
  }
  dfs(1);
  int q;
  scanf("%d", &q);
  while (q--) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int u, k, x;
      scanf("%d %d %d", &u, &x, &k);
      t.add(in[u], qadd(x, mul(k, h[u])));
      t.add(out[u] + 1, -qadd(x, mul(k, h[u])));
      tk.add(in[u], k);
      tk.add(out[u] + 1, -k);
    } else {
      int u;
      scanf("%d", &u);
      int res = t.get(in[u]);
      int f = mul(h[u], tk.get(in[u]));
      res = qadd(res, -f);
      printf("%d\n", res);
    }
  }
  return 0;
}