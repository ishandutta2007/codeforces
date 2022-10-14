#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

class SegTree {
 public:
  int sz;
  vector<int> tree;
  vector<int> coords;

  void AddCoord(int x) {
    coords.emplace_back(x);
  }

  void Build() {
    sort(begin(coords), end(coords));
    coords.resize(unique(begin(coords), end(coords)) - begin(coords));
    sz = coords.size();
    tree.assign(2 * sz, INF);
  }

  void Modify(int p, int x) {
    p = lower_bound(begin(coords), end(coords), p) - begin(coords);
    for (p += sz; p > 0; p /= 2) {
      tree[p] = min(tree[p], x);
    }
  }

  int Query(int l, int r) {
    l = lower_bound(begin(coords), end(coords), l) - begin(coords);
    r = upper_bound(begin(coords), end(coords), r) - begin(coords);
    int res = INF;
    for (l += sz, r += sz; l < r; l /= 2, r /= 2) {
      if (l & 1) res = min(res, tree[l++]);
      if (r & 1) res = min(res, tree[--r]);
    }
    return res;
  }
};

class RangeTree {
 public:
  int sz;
  vector<SegTree> tree;

  RangeTree(int n) : sz(n), tree(2 * n) {}

  void AddCoord(int x, int y) {
    for (x += sz; x > 0; x /= 2) {
      tree[x].AddCoord(y);
    }
  }

  void Build() {
    for (int i = 0; i < 2 * sz; i++) {
      tree[i].Build();
    }
  }

  void Modify(int p, int q, int v) {
    for (p += sz; p > 0; p /= 2) {
      tree[p].Modify(q, v);
    }
  }

  int Query(int a, int b, int c, int d) {
    int res = INF;
    for (a += sz, b += sz + 1; a < b; a /= 2, b /= 2) {
      if (a & 1) res = min(res, tree[a++].Query(c, d));
      if (b & 1) res = min(res, tree[--b].Query(c, d));
    }
    return res;
  }
};

void Main() {
  // Let's say for a fixed x
  // There can only be at most N/x accepted offers
  // If we can query fast: given a set of intervals, check
  // the first valid subset
  // Given ranges {L, R}
  // Find next minimum index which is enclosed in this range, index >= k
  // Actually, we don't need to care about index
  // Since < index must not satisfy too
  //
  // Given ranges, find minimum index enclosed in this range.
  // O(N log^3 N)

  int N, M;
  cin >> N >> M;
  vector<int> ans(N + 1);

  RangeTree tree(N);
  vector<int> L(M), R(M);
  vector<vector<int>> pending(N + 1);
  for (int i = 0; i < M; i++) {
    cin >> L[i] >> R[i];
    L[i]--, R[i]--;
    pending[R[i] - L[i] + 1].push_back(i);
    tree.AddCoord(L[i], R[i]);
  }

  tree.Build();
  for (int K = N; K >= 1; K--) {
    for (auto x : pending[K]) {
      tree.Modify(L[x], R[x], x);
    }
    const auto Solve = [&](const auto &self, int l, int r) {
      if (l > r) return 0;
      int res = tree.Query(l, r, l, r);
      if (res == INF) return 0;
      return R[res] - L[res] + 1 + self(self, l, L[res] - 1) + self(self, R[res] + 1, r);
    };
    ans[K] = Solve(Solve, 0, N - 1);
  }

  for (int i = 1; i <= N; i++) {
    cout << ans[i] << '\n';
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