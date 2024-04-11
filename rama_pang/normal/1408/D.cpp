#include <bits/stdc++.h>
using namespace std;

class SegTree {
 public:
  int sz;
  vector<int> tree;

  SegTree() {}
  SegTree(int sz) : sz(sz), tree(2 * sz, -1) {}

  void Update(int p, int x) {
    p += sz;
    tree[p] = max(tree[p], x);
    for (p /= 2; p > 0; p /= 2) {
      tree[p] = max(tree[p * 2], tree[p * 2 + 1]);
    }
  }

  int Query(int l, int r) {
    int res = -1;
    for (l += sz, r += sz; l < r; l /= 2, r /= 2) {
      if (l & 1) res = max(res, tree[l++]);
      if (r & 1) res = max(res, tree[--r]);
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> A(N), B(M);
  for (int i = 0; i < N; i++) {
    cin >> A[i].first >> A[i].second;
  }
  for (int i = 0; i < M; i++) {
    cin >> B[i].first >> B[i].second;
  }
  const int MAX = 1e6 + 5;
  vector<array<int, 3>> C;
  for (int i = 0; i < N; i++) {
    C.push_back({MAX, -1, i});
    for (int j = 0; j < M; j++) {
      if (A[i].first <= B[j].first && A[i].second <= B[j].second) {
        C.push_back({B[j].first - A[i].first, B[j].second - A[i].second, i});
      }
    }
  }

  sort(begin(C), end(C));
  SegTree seg(N);

  int ans = 2 * MAX;
  for (int rgt = MAX; rgt >= 0; rgt--) {
    while (!C.empty() && C.back()[0] >= rgt) {
      seg.Update(C.back()[2], C.back()[1]);
      C.pop_back();
    }
    ans = min(ans, rgt + seg.Query(0, N) + 1);
  }

  cout << ans << "\n";
  return 0;
}