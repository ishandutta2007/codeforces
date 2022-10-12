#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 12;
const int Q = 1 << 16;
const int SQ = 1 << 8;

mt19937_64 rng(2020);

int n, q;
int a[N];
long long val[N];
int idx[N];
int sets[N];

int ans[Q];

int cnt;
pair<int, int> ops[2200005];
int merge(int u, int v) {
  if (u == -1) return v;
  if (v == -1) return u;
  ops[cnt++] = make_pair(u, v);
  return cnt-1;
}

struct SegTree {
  long long h[N << 2];
  unordered_map<long long, int> elements[N << 2];

  void update(int node, int l, int r, int x) {
    if (l > x || r < x) return;
    h[node] ^= val[x];
    if (l == x && r == x) return;

    int mid = (l + r) >> 1;

    update(node*2 + 1, l, mid+0, x);
    update(node*2 + 2, mid+1, r, x);
  }

  int query(int node, int l, int r) {
    if (h[node] == 0) return -1;
    if (l == r) return idx[l];
    if (elements[node].find(h[node]) != elements[node].end()) {
      return elements[node][h[node]];
    }

    int mid = (l + r) >> 1;

    return elements[node][h[node]] = merge(
      query(node*2 + 1, l, mid+0),
      query(node*2 + 2, mid+1, r)
    );
  }

  void update(int x) {
    update(0, 0, n-1, x);
  }

  int query() {
    return query(0, 0, n-1);
  }
} tree;

int main() {
  scanf("%d %d", &n, &q);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    idx[--a[i]] = i;
    val[i] = rng();
  }

  vector<tuple<int, int, int>> queries(q);
  for (int i = 0; i < q; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);
    --l, --r;

    queries[i] = make_tuple(l, r, i);
  }

  sort(queries.begin(), queries.end(), [](tuple<int, int, int> p, tuple<int, int, int> q) {
    return make_tuple(get<0>(p) / SQ, get<1>(p), get<2>(p)) < make_tuple(get<0>(q) / SQ, get<1>(q), get<2>(q));
  });

  cnt = n;

  int L = 0, R = -1;
  for (int i = 0; i < q; ++i) {
    int l, r, idx;
    tie(l, r, idx) = queries[i];

    while (L < l) tree.update(a[L++]);
    while (L > l) tree.update(a[--L]);
    while (R < r) tree.update(a[++R]);
    while (R > r) tree.update(a[R--]);

    ans[idx] = tree.query();
  }

  printf("%d\n", cnt);
  for (int i = n; i < cnt; ++i) {
    printf("%d %d\n", ops[i].first + 1, ops[i].second + 1);
  }

  for (int i = 0; i < q; ++i) printf("%d ", ans[i] + 1);
  printf("\n");
  return 0;
}