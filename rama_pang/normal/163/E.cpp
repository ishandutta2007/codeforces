#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 5;

namespace AhoCorasick {
  int sz = 1;
  int link[MAX];
  int to[MAX][26];

  int NewNode() {
    return sz++;
  }

  vector<int> endpoint;

  void AddString(string s, int idx) {
    int n = 0;
    for (auto i : s) {
      if (!to[n][i - 'a']) {
        int nn = NewNode();
        to[n][i - 'a'] = nn;
      }
      n = to[n][i - 'a'];
    }
    endpoint.emplace_back(n);
  }

  void Build() {
    for (queue<int> q({0}); !q.empty(); q.pop()) {
      int u = q.front();
      for (int i = 0; i < 26; i++) {
        int v = to[u][i];
        to[u][i] = 0;
        if (v) {
          q.emplace(v);
          link[v] = to[link[u]][i];
          to[u][i] = v;
        } else {
          to[u][i] = to[link[u]][i];
        }
      }
    }
  }
};

class SegTree {
 public:
  int sz;
  vector<int> tree;

  SegTree() {}
  SegTree(int sz) : sz(sz), tree(2 * sz) {}

  void Modify(int p, int x) {
    for (p += sz; p > 0; p /= 2) {
      tree[p] += x;
    }
  }

  int Query(int l, int r) {
    int res = 0;
    for (l += sz, r += sz + 1; l < r; l /= 2, r /= 2) {
      if (l & 1) res += tree[l++];
      if (r & 1) res += tree[--r];
    }
    return res;
  }
};

class Tree {
 public:
  int sz;
  vector<vector<int>> adj;

  SegTree seg;
  vector<int> st, et;

  Tree() {}
  Tree(int sz) : sz(sz), adj(sz), seg(sz + 1), st(sz), et(sz) {}

  void AddEdge(int u, int v) {
    adj[u].emplace_back(v);
  }

  void Build() {
    int timer = 0;
    const auto Dfs = [&](const auto &self, int u, int p) -> void {
      st[u] = timer++;
      for (auto v : adj[u]) {
        self(self, v, u);
      }
      et[u] = timer;
    };
    Dfs(Dfs, 0, -1);
  }

  void Modify(int u, int x) {
    seg.Modify(st[u], +x);
    seg.Modify(et[u], -x);
  }

  int Query(int u) {
    return seg.Query(0, st[u]);
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int Q, N;
  cin >> Q >> N;

  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    AhoCorasick::AddString(s, i);
  }
  AhoCorasick::Build();

  Tree tree(AhoCorasick::sz);
  for (int i = 1; i < AhoCorasick::sz; i++) {
    tree.AddEdge(AhoCorasick::link[i], i);
  }
  tree.Build();

  vector<int> include(N);
  for (int i = 0; i < N; i++) {
    include[i] = 1;
    tree.Modify(AhoCorasick::endpoint[i], +1);
  }

  while (Q--) {
    char t;
    cin >> t;
    if (t == '+') {
      int i;
      cin >> i;
      i--;
      if (include[i] == 0) {
        include[i] = 1;
        tree.Modify(AhoCorasick::endpoint[i], +1);
      }
    } else if (t == '-') {
      int i;
      cin >> i;
      i--;
      if (include[i] == 1) {
        include[i] = 0;
        tree.Modify(AhoCorasick::endpoint[i], -1);
      }
    } else if (t == '?') {
      string s;
      cin >> s;
      int n = 0;
      long long ans = 0;
      for (auto i : s) {
        n = AhoCorasick::to[n][i - 'a'];
        ans += tree.Query(n);
      }
      cout << ans << '\n';
    }
  }
  return 0;
}