#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
const int LN = 19;

struct Node {
  long long val;
  Node *l, *r;
  Node(long long _val=0): val(_val) {
    l = r = 0;
  }
  Node(Node *node) {
    val = node->val;
    l = node->l; r = node->r;
  }
};

int n, q;
int c[N];

mt19937_64 rng;
long long h[N];

Node *roots[N];

vector<int> edges[N];
int depth[N];
int par[LN][N];

namespace PersistentSegTree {

Node* build(int l, int r) {
  if (l == r) return new Node();

  int mid = (l + r) >> 1;
  Node *ret = new Node();
  ret->l = build(l, mid + 0);
  ret->r = build(mid + 1, r);
  return ret;
}

Node* update(Node *node, int l, int r, int x, long long val) {
  Node *ret = new Node(node);
  if (l == x && r == x) {
    ret->val ^= val;
    return ret;
  }

  int mid = (l + r) >> 1;
  if (x <= mid) ret->l = update(node->l, l, mid, x, val);
  else ret->r = update(node->r, mid + 1, r, x, val);

  ret->val = ret->l->val ^ ret->r->val;
  return ret;
}

Node *build() {
  return build(0, n - 1);
}

Node *update(Node *node, int x, long long val) {
  return update(node, 0, n - 1, x, val);
}

} // namespace PersistentSegTree

void dfs(int u, int p) {
  par[0][u] = p;
  roots[u] = PersistentSegTree::update(roots[p], c[u], h[c[u]]);
  for (int v : edges[u]) {
    if (v == p) continue;

    depth[v] = depth[u] + 1;
    dfs(v, u);
  }
}

void initLca() {
  for (int i = 1; i < LN; ++i) {
    for (int j = 0; j < n; ++j) {
      par[i][j] = par[i - 1][par[i - 1][j]];
    }
  }
}

int query(Node *u, Node *v, Node *par, Node *ppar, int l, int r, int ll, int rr) {
  int mid = (l + r) >> 1;
  if (l > rr || r < ll) return -1;
  if (l >= ll && r <= rr) {
    if (u->val ^ v->val ^ par->val ^ ppar->val) {
      if (l == r) return l;

      int ret = query(u->l, v->l, par->l, ppar->l, l, mid + 0, ll, rr);
      if (ret != -1) return ret;
      return query(u->r, v->r, par->r, ppar->r, mid + 1, r, ll, rr);
    }
    return -1;
  }

  int ret = query(u->l, v->l, par->l, ppar->l, l, mid, ll, rr);
  if (ret != -1) return ret;
  return query(u->r, v->r, par->r, ppar->r, mid + 1, r, ll, rr);
}

int lca(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  while (depth[u] != depth[v]) u = par[__builtin_ctz(depth[u] - depth[v])][u];

  if (u == v) return u;

  for (int i = LN - 1; i >= 0; --i) {
    if (par[i][u] == par[i][v]) continue;
    u = par[i][u];
    v = par[i][v];
  }
  return par[0][u];
}

int main() {
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &c[i]);
    --c[i];
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;

    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  for (int i = 0; i < n; ++i) h[i] = rng();

  par[0][0] = n;
  roots[n] = PersistentSegTree::build();
  dfs(0, n);
  initLca();

  while (q--) {
    int u, v, l, r;
    scanf("%d %d %d %d", &u, &v, &l, &r);
    --u, --v, --l, --r;

    int p = lca(u, v);
    int res = query(roots[u], roots[v], roots[p], roots[par[0][p]], 0, n - 1, l, r);
    printf("%d\n", res == -1 ? -1 : res + 1);
  }
  return 0;
}