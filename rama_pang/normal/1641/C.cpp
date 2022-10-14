#include <bits/stdc++.h>
using namespace std;

using lint = long long;

class SegTree {
 public:
  int sz;
  vector<int> tree;
  SegTree(int sz) : sz(sz), tree(2 * sz) {}
  void Update(int p, int x) {
    for (p += sz; p > 0; p /= 2) {
      tree[p] += x;
    }
  }
  int Query(int l, int r) {
    int z = 0;
    for (l += sz, r += sz + 1; l < r; l /= 2, r /= 2) {
      if (l & 1) z += tree[l++];
      if (r & 1) z += tree[--r];
    }
    return z;
  }
};

class SegTreeMin {
 public:
  int sz;
  vector<int> tree;
  SegTreeMin(int sz, int v) : sz(sz), tree(2 * sz, v) {}
  int Query(int p) {
    int z = 1e9;
    for (p += sz; p > 0; p /= 2) {
      chmin(z, tree[p]);
    }
    return z;
  }
  void chmin(int &a, int b) {
    a = min(a, b);
  }
  void Update(int l, int r, int x) {
    for (l += sz, r += sz + 1; l < r; l /= 2, r /= 2) {
      if (l & 1) chmin(tree[l++], x);
      if (r & 1) chmin(tree[--r], x);
    }
  }
};

void Main() {
  int n, q;
  cin >> n >> q;

  set<int> unknown;
  for (int i = 0; i < n; i++) {
    unknown.emplace(i);
  }

  // We have multiple ranges [l, r]. Each has value v.
  // Update(x): for all ranges l <= x <= r, v -= 1
  // Query(): find minimum value
  //
  // 
  // For each range [l, r] with x = 1, determine when it first
  // gets degree = 1. Need max and second max.
  // 
  // For each range [l, r], suppose it gets degree = 1 on time t.
  // Then before t-1, [l, r] is okay.

  vector<string> ans(q, "?");
  vector<array<int, 3>> query(q);

  vector<vector<int>> become_zero(q);

  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 0) {
      int l, r, x;
      cin >> l >> r >> x;
      l--, r--;
      query[i] = {l, r, x};
      if (x == 0) {
        auto it = unknown.lower_bound(l);
        while (it != end(unknown) && *it <= r) {
          // confirm it zero
          become_zero[i].emplace_back(*it);
          it = unknown.erase(it);
        }
      } else {
      }
    } else {
      int x;
      cin >> x;
      x--;
      query[i] = {x, x, -1};
      // if (unknown.count(x)) {
      //   // can be yes or no
      //   // need to check if no is possible

      // } else {
      //   cout << "NO\n";
      // }
    }
  }

  vector<int> lo(q, 0), hi(q, q);
  for (int i = 0; i < q; i++) lo[i] = i;
  while (true) {
    SegTree seg(n);
    int cnt = 0;
    vector<vector<int>> ls(q);
    for (int i = 0; i < q; i++) {
      if (query[i][2] == 1) {
        if (lo[i] < hi[i]) {
          int md = (lo[i] + hi[i]) / 2;
          cnt += 1;
          ls[md].emplace_back(i);
        }
      }
    }
    if (cnt == 0) break;
    for (int i = 0; i < q; i++) {
      for (auto pos : become_zero[i]) {
        seg.Update(pos, 1);
      }
      for (auto id : ls[i]) {
        int v = seg.Query(query[id][0], query[id][1]);
        if (v + 1 == query[id][1] - query[id][0] + 1) {
          hi[id] = i;
        } else {
          lo[id] = i + 1;
        }
      }
    } 
  }

  SegTreeMin seg(n, 1e9);
  for (int i = 0; i < q; i++) {
    if (query[i][2] == 1) {
      // cout << i << ' ' << lo[i] << endl;
      assert(lo[i] == hi[i]);
      int t = lo[i];
      seg.Update(query[i][0], query[i][1], t - 1);
    }
  }

  // for (int i = 0; i< n; i++) {
  //   cout << seg.Query(i) << ' ';
  // }
  // cout << '\n';

  vector<int> isZero(n, 0);
  for (int i = 0; i < q; i++) {
    for (auto j : become_zero[i]) isZero[j] = 1;
    if (query[i][2] == -1) {
      int x = query[i][0];
      if (isZero[x]) {
        cout << "NO\n";
      } else {
        if (i <= seg.Query(x)) {
          cout << "N/A\n";
        } else {
          cout << "YES\n";
        }
      }
    }
  }

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}