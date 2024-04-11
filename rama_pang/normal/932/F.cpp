#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

const int MAX = 1e5 + 5;

struct Line {
  lint a, b;
  Line(lint a = 0, lint b = INF) : a(a), b(b) {}
  lint get(lint x) { return a * x + b; }
};

class LiChao {
 public:
  struct Node {
    Line line;
    int ch[2] = {0, 0};
  };

  vector<Node> T;
  LiChao(int n) : T(n + 1) {}

  void Insert(int root, Line x) {
    int n = root;
    int tl = -MAX, tr = MAX;
    while (tl <= tr) {
      int md = (tl + tr) >> 1;
      if (T[n].line.get(tl) > x.get(tl)) {
        swap(T[n].line, x);
      }
      if (T[n].line.get(tr) <= x.get(tr)) {
        return;
      }
      if (T[n].line.get(md) <= x.get(md)) {
        tl = md + 1;
        if (!T[n].ch[1]) {
          T[n].ch[1] = T.size();
          T.emplace_back();
        }
        n = T[n].ch[1];
      } else {
        swap(T[n].line, x);
        tr = md;
        if (!T[n].ch[0]) {
          T[n].ch[0] = T.size();
          T.emplace_back();
        }
        n = T[n].ch[0];
      }
    }
  }

  lint Query(int root, lint x) {
    lint res = INF;
    int n = root;
    int tl = -MAX, tr = MAX;
    while (tl <= tr) {
      if (!n) break;
      int md = (tl + tr) >> 1;
      res = min(res, T[n].line.get(x));
      if (x <= md) {
        tr = md;
        n = T[n].ch[0];
      } else {
        tl = md + 1;
        n = T[n].ch[1];
      }
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> B[i];
  vector<vector<int>> adj(N);
  for (int i = 1; i < N; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  LiChao lc(N);
  vector<int> sz(N);
  vector<lint> dp(N);
  vector<int> tree(N);
  vector<vector<Line>> lines(N);
  const auto Dfs = [&](const auto &self, int u, int p) -> void {
    if (p != -1) {
      adj[u].erase(find(begin(adj[u]), end(adj[u]), p));
    }
    sz[u] = 1;
    for (auto &v : adj[u]) {
      self(self, v, u);
      sz[u] += sz[v];
      if (sz[adj[u][0]] < sz[v]) {
        swap(adj[u][0], v);
      }
    }
    if (sz[u] == 1) {
      dp[u] = 0;
      tree[u] = u + 1;
      lc.Insert(tree[u], Line(B[u], dp[u]));
      lines[u].emplace_back(Line(B[u], dp[u]));
      return;
    }
    for (auto v : adj[u]) {
      if (v == adj[u][0]) {
        swap(tree[u], tree[v]);
        swap(lines[u], lines[v]);
      } else {
        for (auto l : lines[v]) {
          lc.Insert(tree[u], l);
          lines[u].emplace_back(l);
        }
      }
    }
    dp[u] = lc.Query(tree[u], A[u]);
    lc.Insert(tree[u], Line(B[u], dp[u]));
    lines[u].emplace_back(Line(B[u], dp[u]));
  };

  Dfs(Dfs, 0, -1);
  for (int i = 0; i < N; i++) {
    cout << dp[i] << " \n"[i + 1 == N];
  }
  return 0;
}