#include <bits/stdc++.h>
using namespace std;

using lint = long long;

struct Item {
  int lft = 0;
  int rgt = 0;
  int sum = 0;
  int ans = 0;
  Item(int v = 0) {
    lft = max(0, v);
    rgt = max(0, v);
    ans = max(0, v);
    sum = v;
  }
  friend Item merge(const Item &a, const Item &b) {
    Item c;
    c.lft = max(a.lft, a.sum + b.lft);
    c.rgt = max(b.rgt, b.sum + a.rgt);
    c.sum = a.sum + b.sum;
    c.ans = max({a.ans, b.ans, a.rgt + b.lft});
    return c;
  }
};

class SegTree {
 public:

  int sz;
  vector<Item> tree;

  SegTree(int n) {
    sz = n;
    tree.assign(2 * sz, Item(0));
  }

  void Modify(int p, int x) {
    p += sz;
    tree[p] = Item(x);
    for (p /= 2; p > 0; p /= 2) {
      tree[p] = merge(tree[p * 2], tree[p * 2 + 1]);
    }
  }

  Item Query(int l, int r) {
    Item lft(0), rgt(0);
    for (l += sz, r += sz + 1; l < r; l /= 2, r /= 2) {
      if (l & 1) lft = merge(lft, tree[l++]);
      if (r & 1) rgt = merge(tree[--r], rgt);
    }
    return merge(lft, rgt);
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // Is it possible to get
  // distToCenter: (upper center)
  // If < x is -1, >= x is +1
  // Then, dist element x to center is some array:
  // 1 2 3 6
  // -1 1 1 1, sum: 2, dist: 1
  // -1 -1 1 1, sum: 0, dist: 0
  // -1 -1 -1 1, sum: -2, dist: 1
  // dist = abs(sum) / 2
  // 1 2 3
  // 1 1 1: sum: 3, dist: 1
  // -1 1 1: sum: 1, dist: 0
  // -1 -1 1: sum: -1, dist 1
  // dist = abs((sum - 1) / 2)
  // Find max possible abs(sum) / 2
  // Find minimum sum, maximum sum
  // Max/Min subarray segment

  int N;
  cin >> N;
  vector<int> A(N);
  vector<vector<int>> occ(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    A[i]--;
    occ[A[i]].emplace_back(i);
  }
  SegTree minim(N), maxim(N);
  for (int i = 0; i < N; i++) {
    minim.Modify(i, -1);
    maxim.Modify(i, +1);
  }
  vector<int> ans(N, 0);
  for (int v = 0; v < N; v++) {
    for (auto x : occ[v]) {
      int lft = -minim.Query(0, x - 1).rgt;
      int rgt = -minim.Query(x + 1, N - 1).lft;
      int all = lft + rgt + 1;
      if (all % 2 != 0) all--;
      ans[x] = max(ans[x], (abs(all)) / 2);
      lft = maxim.Query(0, x - 1).rgt;
      rgt = maxim.Query(x + 1, N - 1).lft;
      all = lft + rgt + 1;
      if (all % 2 != 0) all--;
      ans[x] = max(ans[x], (abs(all)) / 2);
    }
    for (auto x : occ[v]) {
      minim.Modify(x, +1);
      maxim.Modify(x, -1);
    }
    for (auto x : occ[v]) {
      int lft = -minim.Query(0, x - 1).rgt;
      int rgt = -minim.Query(x + 1, N - 1).lft;
      int all = lft + rgt + 1;
      if (all % 2 != 0) all--;
      ans[x] = max(ans[x], (abs(all)) / 2);
      lft = maxim.Query(0, x - 1).rgt;
      rgt = maxim.Query(x + 1, N - 1).lft;
      all = lft + rgt + 1;
      if (all % 2 != 0) all--;
      ans[x] = max(ans[x], (abs(all)) / 2);
    }
  }
  for (int i = 0; i < N; i++) {
    cout << ans[i] << " \n"[i + 1 == N];
  }
  return 0;
}