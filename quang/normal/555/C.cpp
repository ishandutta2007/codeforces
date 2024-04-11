#include <bits/stdc++.h>

using namespace std;

const int N = 200100;

int n, q;
map<int, int> M;

struct it {
  struct node {
    int smax;
    node* l;
    node* r;

    node() {
      smax = 0;
      l = NULL;
      r = NULL;
    }
  };

  node* root;

  node* newnode() {
    node* res = new node;
    res->smax = 0;
    res->l = NULL;
    res->r = NULL;
    return res;
  }

  void update(node* u, int x, int y, int l, int r, int val) {
    int foo = u->smax;
    if (y < l || x > r) {
      return;
    }
    if (l <= x && y <= r) {
      u->smax = max(u->smax, val);
      return;
    }
    int m = (x + y) / 2;
    if (u->l == NULL) {
      u->l = newnode();
      u->r = newnode();
    }
    update(u->l, x, m, l, r, val);
    update(u->r, m + 1, y, l, r, val);
  }

  int get(node* u,int l, int r, int x) {
    int foo = u->smax;
    if (l > x || r < x) {
      return 0;
    }
    if (l == r) {
      return u->smax;
    }
    int m = (l + r) / 2;
    int res = u->smax;
    if (u->l == NULL) {
      return res;
    }
    res = max(res, get(u->l, l, m, x));
    res = max(res, get(u->r, m + 1, r, x));
    return res;
  }

  void up(int l,int  r,int val) {
    if (l > r) {
      return;
    }
    update(root, 1, n, l, r, val);
  }

  int get2(int x) {
    return get(root, 1, n, x);
  }

  void init() {
    root = newnode();
  }
} ngang, doc;

int main() {
  ios_base::sync_with_stdio(0);
  //freopen("inp.txt", "r", stdin);
  cin >> n >> q;
  ngang.init();
  doc.init();
  for (int i = 1; i <= q; i++) {
    int u, v;
    char huong;
    cin >> v >> u;
    cin >> huong;
    if (M[u]) {
      cout << 0 << endl;
      continue;
    }
    if (huong == 'U') {
      int x = ngang.get2(v);
      doc.up(x + 1, u, v);
      cout << u - x << endl;
    } else {
      int x = doc.get2(u);
      ngang.up(x + 1, v, u);
      cout << v - x << endl;
    }
    M[u] = 1;
  }
  return 0;
}