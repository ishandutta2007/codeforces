#include <bits/stdc++.h>
using namespace std;

using lint = long long;

class SegTree {
 public:
  int sz;
  vector<int> tree;
  SegTree(int sz) : sz(sz), tree(2 * sz) {}
  void Update(int p, int x) {
    tree[p += sz] = x;
    for (p /= 2; p > 0; p /= 2) {
      tree[p] = min(tree[p * 2], tree[p * 2 + 1]);
    }
  }
  int Query(int l, int r) {
    int z = 1e9;
    for (l += sz, r += sz + 1; l < r; l /= 2, r /= 2) {
      if (l & 1) z = min(z, tree[l++]);
      if (r & 1) z = min(z, tree[--r]);
    }
    return z;
  }
};

void Main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<vector<int>> adj(2 * n);
  vector<int> st;
  int cur = 0;
  SegTree seg(2 * n);
  vector<vector<int>> ls(2 * n + 5);
  for (int i = 0; i < 2 * n; i++) {
    int level = -1;
    if (s[i] == '(') {
      level = cur++;
    } else {
      level = --cur;
    }
    ls[level].emplace_back(i);
    seg.Update(i, level);
  }
  for (int lev = 0; lev < int(ls.size()); lev++) {
    for (int i = 1; i < int(ls[lev].size()); i++) {
      int u = ls[lev][i - 1];
      int v = ls[lev][i];
      if (seg.Query(u, v) >= lev) {
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
      }
    }
  }
  vector<int> vis(2 * n);
  int ans = 0;
  for (int s = 0; s < 2 * n; s++) {
    if (vis[s]) continue;
    ans++;
    vector<int> que = {s};
    vis[s] = 1;
    for (int q = 0; q < int(que.size()); q++) {
      int u = que[q];
      for (auto v : adj[u]) {
        if (!vis[v]) {
          vis[v] = 1;
          que.emplace_back(v);
        }
      }
    }
  }
  cout << ans << '\n';

  


}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}