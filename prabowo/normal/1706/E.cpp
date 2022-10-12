#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, m, q;

int par[N];
int root(int u) {
  if (par[u] == u) return u;
  return par[u] = root(par[u]);
}

int mini[N];

set<int> comp[N];
void merge(int u, int v, int id) {
  if (root(u) == root(v)) return;

  u = root(u), v = root(v);
  if (comp[u].size() < comp[v].size()) swap(u, v);

  for (int i : comp[v]) {
    if (i > 0 && comp[u].find(i - 1) != comp[u].end()) mini[i - 1] = id;
    if (i + 1 < n && comp[u].find(i + 1) != comp[u].end()) mini[i] = id;
  }

  for (int i : comp[v]) comp[u].insert(i);
  comp[v].clear();
  par[v] = u;
}

struct SegTree {
  int size;
  int maxi[N << 2];

  void build(int idx, int l, int r, int a[]) {
    if (l + 1 == r) {
      maxi[idx] = a[l];
      return;
    }
    int mid = (l + r) / 2;
    build(idx * 2 + 1, l, mid, a);
    build(idx * 2 + 2, mid, r, a);
    maxi[idx] = max(maxi[idx * 2 + 1], maxi[idx * 2 + 2]);
  }
  
  int query(int idx, int l, int r, int ll, int rr) {
    if (l >= rr || r <= ll) return -1;
    if (l >= ll && r <= rr) return maxi[idx];
    int mid = (l + r) / 2;
    return max(query(idx * 2 + 1, l, mid, ll, rr), query(idx * 2 + 2, mid, r, ll, rr));
  }
  
  void build(int _size, int a[]) {
    size = _size;
    build(0, 0, size, a);
  }
  int query(int l, int r) {
    return query(0, 0, size, l, r);
  }
} tree;

int solve() {
  scanf("%d %d %d", &n, &m, &q);

  for (int i = 0; i < n; ++i) {
    par[i] = i;
    comp[i].clear(); comp[i].insert(i);
    mini[i] = -1;
  }

  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;

    merge(u, v, i);
  }

  tree.build(n - 1, mini);
  // for (int i = 0; i < n - 1; ++i) cerr << mini[i] << " "; cerr << endl;

  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    --l, --r;

    if (l == r) printf("0 ");
    else printf("%d ", tree.query(l, r) + 1);
  }
  printf("\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc + 1);
    solve();
  }
  return 0;
}