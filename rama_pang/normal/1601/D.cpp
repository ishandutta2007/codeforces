#include <bits/stdc++.h>
using namespace std;

class SegTree {
 public:
  int sz;
  vector<int> tree;
  SegTree(int n) : sz(n), tree(2 * n) {}
  void Update(int p, int x) {
    for (p += sz; p > 0; p /= 2) tree[p] += x;
  }
  int Query(int l, int r) {
    if (l > r) return 0;
    int z = 0;
    for (l += sz, r += sz + 1; l < r; l /= 2, r /= 2) {
      if (l & 1) z += tree[l++];
      if (r & 1) z += tree[--r];
    }
    return z;
  }
};

void Main() {
  int N, D;
  cin >> N >> D;
  vector<int> coords;
  vector<int> adder;
  vector<pair<int, int>> inter;
  vector<pair<int, int>> special;
  for (int i = 0; i < N; i++) {
    int s, a;
    cin >> s >> a;
    if (s >= D) {
      coords.emplace_back(s);
      coords.emplace_back(a);
      if (s >= a) {
        adder.emplace_back(s);
        special.emplace_back(s, a);
      } else {
        inter.emplace_back(s, a);
      }
    }
  }  
  sort(begin(coords), end(coords));
  coords.resize(unique(begin(coords), end(coords)) - begin(coords));
  for (auto &x : inter) {
    x.first = lower_bound(begin(coords), end(coords), x.first) - begin(coords);
    x.second = lower_bound(begin(coords), end(coords), x.second) - begin(coords);
  }
  for (auto &x : special) {
    x.first = lower_bound(begin(coords), end(coords), x.first) - begin(coords);
    x.second = lower_bound(begin(coords), end(coords), x.second) - begin(coords);
  }
  for (auto &x : adder) {
    x = lower_bound(begin(coords), end(coords), x) - begin(coords);
  }
  vector<vector<int>> upd(coords.size());
  for (auto [y, x] : special) {
    upd[x].emplace_back(y);
  }
  vector<vector<int>> adj(coords.size());
  for (auto [x, y] : inter) {
    adj[x].emplace_back(y);
  }
  vector<int> score(coords.size());
  for (auto a : adder) score[a]++;
  vector<int> dp(coords.size());
  SegTree seg(coords.size());
  for (int u = 0; u < int(coords.size()); u++) {
    for (auto y : upd[u]) {
      seg.Update(y, 1);
    }
    dp[u] += score[u];
    if (u + 1 < int(coords.size())) {
      dp[u + 1] = max(dp[u + 1], dp[u]);
    }
    for (auto y : adj[u]) {
      dp[y] = max(dp[y], dp[u] + 1 + seg.Query(u + 1, y - 1));
    }
  }
  cout << *max_element(begin(dp), end(dp)) << '\n';
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