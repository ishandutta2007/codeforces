#include <bits/stdc++.h>
using namespace std;
using lint = long long;

const double PI = acos(-1);

class SegmentTree {
 public:
  struct Node {
    double x, y;
    Node() {}
    Node(double x, double y) : x(x), y(y) {}

    friend Node Merge(const Node &a, const Node &b) {
      return Node(a.x + b.x, a.y + b.y);
    }
  };

  int sz;
  vector<Node> tree;
  vector<int> lazy;

  void Add(int n, int tl, int tr, int p, int x) {
    if (tr - tl == 1) {
      double deg = atan2(tree[n].y, tree[n].x);
      tree[n].x += 1.00 * x * cos(deg);
      tree[n].y += 1.00 * x * sin(deg);
      return;
    }
    int md = (tl + tr) / 2;
    int lc = n + 1;
    int rc = n + 2 * (md - tl);
    Push(n, lc, rc);
    if (p < md) {
      Add(lc, tl, md, p, x);
    } else {
      Add(rc, md, tr, p, x);
    }
    tree[n] = Merge(tree[lc], tree[rc]);
  }

  void Apply(int n, int x) {
    double deg = atan2(tree[n].y, tree[n].x);
    double len = hypot(tree[n].x, tree[n].y);
    deg -= 1.00 * PI * x / 180.00;
    tree[n].x = len * cos(deg);
    tree[n].y = len * sin(deg);
    lazy[n] += x;
  }

  void Push(int n, int lc, int rc) {
    if (lazy[n] % 360 != 0) {
      lazy[n] %= 360;
      Apply(lc, lazy[n]);
      Apply(rc, lazy[n]);
      lazy[n] = 0;    
    }
  }

  void Rotate(int n, int tl, int tr, int l, int r, int x) {
    if (tl >= r || l >= tr || tl >= tr || l >= r) return;
    if (l <= tl && tr <= r) return Apply(n, x);
    int md = (tl + tr) / 2;
    int lc = n + 1;
    int rc = n + 2 * (md - tl);
    Push(n, lc, rc);
    Rotate(lc, tl, md, l, r, x);
    Rotate(rc, md, tr, l, r, x);
    tree[n] = Merge(tree[lc], tree[rc]);
  }

  void Build(int n, int tl, int tr) {
    if (tr - tl == 1) {
      tree[n].x = 1;
      tree[n].y = 0;
      return;
    }
    int md = (tl + tr) / 2;
    int lc = n + 1;
    int rc = n + 2 * (md - tl);
    Build(lc, tl, md);
    Build(rc, md, tr);
    tree[n] = Merge(tree[lc], tree[rc]);
  }

  SegmentTree() {}
  SegmentTree(int n) : sz(n) {
    tree.resize(2 * sz);
    lazy.assign(2 * sz, 0);
    Build(1, 0, sz);
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N, M;
  cin >> N >> M;
  SegmentTree seg(N);
  cout << fixed << setprecision(20);
  for (int i = 0; i < M; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    y--;
    if (x == 1) {
      seg.Add(1, 0, N, y, z);
    } else {
      seg.Rotate(1, 0, N, y, N, z);
    }
    cout << seg.tree[1].x << " " << seg.tree[1].y << "\n";
  }
  return 0;
}