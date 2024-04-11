#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int LN = 18;

int n;
int a[N], b[N], c[N];

pair<int, int> nodes[N];

vector<int> edges[N];
int L[N], R[N];

struct SegTree {
  int mini[N << 2];

  SegTree() {
    memset(mini, -1, sizeof mini);
  }

  int merge(int lc, int rc) {
    if (lc != -1) return lc;
    if (rc != -1) return rc;
    return -1;
  }

  void update(int node, int l, int r, int x, int val) {
    if (l > x || r < x) return;
    if (l == x && r == x) {
      if (val > 0) mini[node] = x;
      else mini[node] = -1;
      return;
    }

    int mid = (l + r) >> 1;
    update(node*2 + 1, l, mid+0, x, val);
    update(node*2 + 2, mid+1, r, x, val);
    mini[node] = merge(mini[node*2 + 1], mini[node*2 + 2]);
  }

  int get(int node, int l, int r, int ll, int rr) {
    // cerr << node << " " << l << " " << r << " " << ll << " " << rr << endl;
    if (l > rr || r < ll) return -1;
    if (l >= ll && r <= rr) return mini[node];
    int mid = (l + r) >> 1;
    return merge(get(node*2 + 1, l, mid, ll, rr), get(node*2 + 2, mid+1, r, ll, rr));
  }

  void update(int x, int val) {
    update(0, 0, n-1, x, val);
  }

  int get(int l, int r) {
    return get(0, 0, n-1, l, r);
  }
} tree[2];

int order = 0;
void dfs(int u, int p) {
  L[u] = order;
  for (int v: edges[u]) {
    if (v == p) continue;
    dfs(v, u);
  }
  R[u] = order++;
}

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d %d", &a[i], &b[i], &c[i]);
  }

  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;

    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  dfs(0, -1);

  // cerr << "BFS" << endl;

  int cnt[2] = {0, 0};
  for (int i = 0; i < n; ++i) {
    nodes[i] = make_pair(a[i], i);
    if (b[i] == c[i]) continue;
    tree[b[i]].update(R[i], 1);
    ++cnt[b[i]];
  }

  if (cnt[0] != cnt[1]) return 0 * printf("-1\n");

  sort(nodes, nodes + n);

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int idx = nodes[i].second;
    while (true) {
      int l = tree[0].get(L[idx], R[idx]);
      int r = tree[1].get(L[idx], R[idx]);

      if (l == -1 || r == -1) break;

      ans += nodes[i].first * 2;
      tree[0].update(l, -1);
      tree[1].update(r, -1);
    }
  }

  printf("%lld\n", ans);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}