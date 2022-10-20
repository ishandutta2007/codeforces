#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int a[N];
int res = 0;

struct it {
  struct node {
    int cost[60];
    node* child1;
    node* child2;

    node () {
      for (int i = 0; i < 60; i++) {
        cost[i] = 0;
      }
      child1 = child2 = NULL;
    }
  };

  node* base;
  void init() {
    base = new node;
  }

  void build(node* &u, int l, int r) {
    if (l == r) {
      for (int i = 0; i < 60; i++) {
        u -> cost[i] = 1 + ((i % a[l]) == 0);
      }
    } else {
      int m = (l + r) >> 1;
      u -> child1 = new node;
      build(u -> child1, l, m);
      u -> child2 = new node;
      build(u -> child2, m + 1, r);
      for (int i = 0; i < 60; i++) {
        int f = u -> child1 -> cost[i];
        u -> cost[i] = f + u -> child2 -> cost[(i + f) % 60];
      }
    }
  }

  void query(node* &u, int l, int r, int x, int y) {
    if (x > r || y < l) {
      return;
    }
    if (x <= l && r <= y) {
      res += u -> cost[res % 60];
      return;
    }
    int m = (l + r) >> 1;
    query(u -> child1, l, m, x, y);
    query(u -> child2, m + 1, r, x, y);
  }

  void update(node* &u, int l, int r, int x, int y) {
    if (l > x || r < x) {
      return;
    }
    if (l == r) {
      for (int i = 0; i <= 59; i++) {
        u -> cost[i] = 1 + ((i % y) == 0);
      }
      return;
    }
    int m = (l + r) >> 1;
    update(u -> child1, l, m, x, y);
    update(u -> child2, m + 1, r, x, y);
    for (int i = 0; i < 60; i++) {
      int f = u -> child1 -> cost[i];
      u -> cost[i] = f + u -> child2 -> cost[(i + f) % 60];
    }
  }
} t;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  t.init();
  t.build(t.base, 1, n);
  int q;
  scanf("%d", &q);
  while (q--) {
    char type;
    int x, y;
    cin >> type;
    scanf("%d %d", &x, &y);
    if (type == 'A') {
      res = 0;
      t.query(t.base, 1, n, x, y - 1);
      printf("%d\n", res);
    } else {
      t.update(t.base, 1, n, x, y);
    }
  }
  return 0;
}