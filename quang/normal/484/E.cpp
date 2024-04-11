#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int h[N], id[N];

struct node {
  int l, r, res;
  bool full;
  node* sonl;
  node* sonr;
  node() {
    l = r = res = full = 0;
    sonl = sonr = NULL;
  }
};

node* root[N];
node* null;

bool cmp(int u, int v) {
  return h[u] > h[v];
}

void build(node* u, int l, int r) {
  if (l == r) {
    return;
  }
  int m = (l + r) >> 1;
  u->sonl = new node();
  u->sonr = new node();
  build(u->sonl, l, m);
  build(u->sonr, m + 1, r);
}

void update(node* u, node* x, node* y) {
  u->res = max(x->res, y->res);
  u->res = max(x->r + y->l, u->res);
  if (x->full) {
    u->l = x->l + y->l;
  } else {
    u->l = x->l;
  }
  if (y->full) {
    u->r = y->r + x->r;
  } else {
    u->r = y->r;
  }
  u->full = x->full & y->full;
}

void rebuild(node* pre, node* u, int l, int r, int id) {
  if (id > r || id < l) {
    return;
  }
  if (l == r) {
    u->l = u->r = u->res = u->full = 1;
    return;
  }
  int m = (l + r) >> 1;
  if (id <= m) {
    u->sonr = pre->sonr;
    u->sonl = new node();
    rebuild(pre->sonl, u->sonl, l, m, id);
  } else {
    u->sonl = pre->sonl;
    u->sonr = new node();
    rebuild(pre->sonr, u->sonr, m + 1, r, id);
  }
  update(u, u->sonl, u->sonr);
}

node get(node* u, int l, int r, int x, int y) {
  if (x > r || y < l) {
    return *null;
  }
  if (x <= l && r <= y) {
    return *u;
  }
  int m = (l + r) >> 1;
  node p1 = get(u->sonl, l, m, x, y);
  node p2 = get(u->sonr, m + 1, r, x, y);
  node res;
  update(&res, &p1, &p2);
  return res;
}

int main() {
  null = new node();
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", h + i);
    id[i] = i;
  }
  sort(id + 1, id + n + 1, cmp);
  root[0] = new node();
  build(root[0], 1, n);
  for (int i = 1; i <= n; i++) {
    root[i] = new node();
    rebuild(root[i - 1], root[i], 1, n, id[i]);
  }
  int m;
  scanf("%d", &m);
  while (m--) {
    int l, r, w;
    scanf("%d %d %d", &l, &r, &w);
    int low = 0, high = n + 1;
    while (high - low > 1) {
      int mid = (low + high) >> 1;
      node x = get(root[mid], 1, n, l, r);
      if (x.res >= w) {
        high = mid;
      } else {
        low = mid;
      }
    }
    printf("%d\n", h[id[high]]);
  }
  return 0;
}