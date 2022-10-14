#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const int H = 20;

class SegTree {
 public:
  struct Node {
    int depth = 0;
    int lc = 0, rc = 0;
    lint sum = 0;
    bitset<H> rev = 0;
    bitset<H> swp = 0;
  };

  int sz = 1;
  vector<Node> tree;

  SegTree() {}
  SegTree(int sz) : tree(2 * sz) {}

  void Reverse(int n) {
    if (tree[n].rev[tree[n].depth]) {
      tree[n].rev[tree[n].depth] = 0;
      if (tree[n].depth > 0) {
        tree[n].rev[tree[n].depth - 1].flip();
      }
      swap(tree[n].lc, tree[n].rc);
    }
  }

  void Swap(int n) {
    if (tree[n].swp[tree[n].depth]) {
      tree[n].swp[tree[n].depth] = 0;
      swap(tree[n].lc, tree[n].rc);
    }
  }

  void Push(int n, int lc, int rc) {
    tree[lc].rev ^= tree[n].rev;
    tree[rc].rev ^= tree[n].rev;
    tree[n].rev = 0;
    Reverse(lc), Reverse(rc);
    tree[lc].swp ^= tree[n].swp;
    tree[rc].swp ^= tree[n].swp;
    tree[n].swp = 0;
    Swap(lc), Swap(rc);
  }

  void Pull(int n, int lc, int rc) {
    tree[n].sum = tree[lc].sum + tree[rc].sum;
  }

  int Build(int d, int tl, int tr) {
    int n = sz++;
    if (tl == tr) return n;
    int md = (tl + tr) / 2;
    tree[n].depth = d;
    tree[n].lc = Build(d - 1, tl, md);
    tree[n].rc = Build(d - 1, md + 1, tr);
    return n;
  }

  void Replace(int n, int tl, int tr, int p, int x) {
    if (tl == tr) {
      tree[n].sum = x;
      return;
    }
    Push(n, tree[n].lc, tree[n].rc);
    int md = (tl + tr) / 2;
    if (p <= md) {
      Replace(tree[n].lc, tl, md, p, x);
    } else {
      Replace(tree[n].rc, md + 1, tr, p, x);
    }
    Pull(n, tree[n].lc, tree[n].rc);
  }

  lint Sum(int n, int tl, int tr, int l, int r) {
    if (r < tl || tr < l || tl > tr || l > r) return 0;
    if (l <= tl && tr <= r) return tree[n].sum;
    Push(n, tree[n].lc, tree[n].rc);
    int md = (tl + tr) / 2;
    return Sum(tree[n].lc, tl, md, l, r) + Sum(tree[n].rc, md + 1, tr, l, r);
  }

  void ReverseUpdate(int k) {
    tree[1].rev[k].flip();    
    Reverse(1);
  }

  void SwapUpdate(int k) {
    k++;
    tree[1].swp[k].flip();
    Swap(1);
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int d, q;
  cin >> d >> q;
  int n = 1 << d;
  SegTree seg(n);
  seg.Build(d, 1, n);
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    seg.Replace(1, 1, n, i, a);
  }
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int p, x;
      cin >> p >> x;
      seg.Replace(1, 1, n, p, x);
    } else if (t == 2) {
      int k;
      cin >> k;
      seg.ReverseUpdate(k);
    } else if (t == 3) {
      int k;
      cin >> k;
      seg.SwapUpdate(k);
    } else if (t == 4) {
      int l, r;
      cin >> l >> r;
      cout << seg.Sum(1, 1, n, l, r) << "\n";
    }
  }
  return 0;
}