#include <bits/stdc++.h>
using namespace std;

class SegTree {
 public:
  int sz;
  vector<int> tree;

  SegTree(int n) {
    sz = 1;
    while (sz < n) sz *= 2;
    tree.assign(2 * sz, 0);
  }

  int Query(int p) {
    int z = 0;
    for (p += sz; p > 0; p /= 2) {
      z += tree[p];
    }
    return z;
  }

  void Update(int l, int r, int v) {
    for (l += sz, r += sz + 1; l < r; l /= 2, r /= 2) {
      if (l & 1) tree[l++] += v;
      if (r & 1) tree[--r] += v;
    }
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, Q;
  cin >> N >> Q;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  // A[1], A[2], ..., A[N]
  // Find largest index id, s.t. A[id] = id
  // Remove id
  //
  // Let B[i] = A[i] - i
  // Find largest index id, s.t. B[id] = 0
  // Remove id by: setting B[id] = INF;
  // All x > id, increase B[x] by 1
  //
  // Sweep, fix R
  // Calculate answer for A[L...R], for all L <= R
  // Assume we have answer ans[L]
  // Move from R-1 to R
  // Set ans[R] = 0
  // If B[R] == 0:
  //   Increase ans[L] by 1 for all L <= R
  // If B[R] > 0:
  //   Will never get removed, ignore it.
  // If B[R] < 0:
  //   If we can remove abs(B[R]) zeroes, we can remove R
  //   If ans[L] >= abs(B[R]), increase ans[L] by 1
  //   ans[L] >= ans[L + 1] by definitioin (since we can do every operation [L+1...R] on [L...R])
  //   binary search for maximum L, s.t. ans[L] >= abs(B[R])

  vector<int> ans(Q);
  vector<vector<pair<int, int>>> query(N);
  for (int i = 0; i < Q; i++) {
    int x, y;
    cin >> x >> y;
    query[N - 1 - y].emplace_back(x, i);
  }

  SegTree seg(N);
  for (int R = 0; R < N; R++) {
    int B = A[R] - R - 1;
    if (B <= 0) {
      B *= -1;
      int lo = -1, hi = R;
      while (lo < hi) {
        int md = (lo + hi + 1) >> 1;
        if (seg.Query(md) >= B) {
          lo = md;
        } else {
          hi = md - 1;
        }
      }
      seg.Update(0, lo, 1);
    }
    for (auto [L, id] : query[R]) {
      ans[id] = seg.Query(L);
    }
  }

  for (int i = 0; i < Q; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}