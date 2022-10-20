#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

struct tree {
  int n;
  long long sumdis, dis;
  int cnt[N], d[N];
  long long len[N];
  int x, y;
  long long maxans;
  vector <int> a[N];

  tree() {
    n = 0;
    sumdis = 0;
  }

  void dfs(int u, int p) {
    cnt[u] = 1;
    len[u] = 0;
    d[u] = d[p] + 1;
    for (int v : a[u]) {
      if (v == p) {
        continue;
      }
      dfs(v, u);
      cnt[u] += cnt[v];
      len[u] += len[v] + cnt[v];
    }
  }

  void redfs(int u, int p) {
    for (int v : a[u]) {
      if (v == p) {
        continue;
      }
      len[v] = len[u] + n - 2 * cnt[v];
      redfs(v, u);
    }
  }

  void init() {
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      a[u].push_back(v);
      a[v].push_back(u);
    }
    dfs(1, 0);
    redfs(1, 0);
    for (int i = 1; i <= n; i++) {
      sumdis += len[i];
      dis = max(dis, len[i]);
    }
    sumdis /= 2;
  }

  pair<long long, int> f[N][2], g[N][2];

  void go(int u, int p) {
    f[u][0] = make_pair(len[u] * x + 1ll * d[u] * x * y, u);
    f[u][1] = make_pair(-(1ll << 60), u);
    g[u][0] = make_pair(len[u] * y + 1ll * d[u] * x * y, u);
    g[u][1] = make_pair(-(1ll << 60), u);
    for (int v : a[u]) {
      if (v == p) {
        continue;
      }
      go(v, u);
      for (int i = 0; i < 2; i++) {
        if (f[u][i] < f[v][0]) {
          swap(f[u][i], f[v][0]);
        }
      }
      for (int i = 0; i < 2; i++) {
        if (g[u][i] < g[v][0]) {
          swap(g[u][i], g[v][0]);
        }
      }
    }
    if (f[u][0].second == g[u][0].second) {
      long long foo = max(f[u][0].first + g[u][1].first, f[u][1].first + g[u][0].first);
      maxans = max(maxans, -2ll * x * y * d[u] + foo);
    } else {
      maxans = max(maxans, -2ll * d[u] * x * y + f[u][0].first + g[u][0].first);
    }
  }

  long long getmax(int xx, int yy) {
    x = xx;
    y = yy;
    maxans = 0;
    go(1, 0);
    return maxans;
  }
} *A, *B, *C;


long long get(tree *a, tree *b, tree *c) {
  long long res = a->sumdis + b->sumdis + c->sumdis;
  res += a->dis * b->n + c->dis * b->n + 1ll * a->n * b->n + 1ll * b->n * c->n + 2ll * a->n * c->n;
  res += a->dis * c->n + c->dis * a->n;
  res += b->getmax(a->n, c->n);
  return res;
}

int main() {
  A = new tree;
  B = new tree;
  C = new tree;
  scanf("%d %d %d", &A->n, &B->n, &C->n);
  A->init();
  B->init();
  C->init();
  long long res = get(A, B, C);
  res = max(res, get(A, C, B));
  res = max(res, get(C, A, B));
  cout << res << endl;
  return 0;
}