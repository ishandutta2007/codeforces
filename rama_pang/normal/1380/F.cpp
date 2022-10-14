#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint MOD = 998244353;

class SegmentTree {
 private:
  struct Node {
    int cfirst = 0, clast = 0;
    lint dp[2][2] = {};

    Node(int c = 0) : cfirst(c), clast(c) {
      dp[0][0] = c + 1;
      dp[1][0] = 1;
      dp[0][1] = 1;
      dp[1][1] = 0;
    }

    Node(int c, int d) : cfirst(c), clast(d) {
      dp[0][0] = 0;
      dp[1][0] = 0;
      dp[0][1] = 0;
      dp[1][1] = 0;
    }

    friend Node Merge(const Node &a, const Node &b) {
      if (a.dp[0][0] == -1) return b;
      if (b.dp[0][0] == -1) return a;
      Node res(a.cfirst, b.clast);
      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
          res.dp[i][j] = 1ll * a.dp[i][0] * b.dp[0][j] % MOD;
          if (a.clast == 1 && b.cfirst <= 8) {
            int ways = 9 - (b.cfirst);
            res.dp[i][j] += 1ll * a.dp[i][1] * b.dp[1][j] % MOD * ways % MOD;
          }
          res.dp[i][j] %= MOD;
        }
      }
      return res;
    }
  };

  int sz;
  vector<Node> tree;

  Node Query(int n, int tl, int tr, int l, int r) {
    if (tr <= l || r <= tl || tl >= tr || l >= r) return Node();
    if (l <= tl && tr <= r) return tree[n];
    int md = (tl + tr) / 2;
    int lc = n + 1;
    int rc = n + 2 * (md - tl);
    return Merge(Query(lc, tl, md, l, r), Query(rc, md, tr, l, r));
  }

  void Update(int n, int tl, int tr, int p, int x) {
    if (tr - tl == 1) {
      tree[n] = Node(x);
      return;
    } 
    int md = (tl + tr) / 2;
    int lc = n + 1;
    int rc = n + 2 * (md - tl);
    if (p < md) {
      Update(lc, tl, md, p, x);
    } else {
      Update(rc, md, tr, p, x);
    }
    tree[n] = Merge(tree[lc], tree[rc]);
  }

 public:
  SegmentTree() {}
  SegmentTree(string s) {
    sz = s.size();
    tree.resize(2 * sz);
    for (int i = 0; i < sz; i++) {
      Update(1, 0, sz, i, s[i] - '0');
    }
  }

  void Update(int p, char x) {
    return Update(1, 0, sz, p, x);
  }

  int Query(int l, int r) {
    return Query(1, 0, sz, l, r).dp[0][0];
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  SegmentTree seg(s);
  for (int i = 0; i < m; i++) {
    int p, x;
    cin >> p >> x;
    p--;
    seg.Update(p, x);
    cout << seg.Query(0, n) << "\n";
  }
  return 0;
}