#include <bits/stdc++.h>
using namespace std;

using lint = long long;

 
class StronglyConnected {
 public:
  int N;
  vector<bool> vis;
  vector<int> todo, comp;
  vector<vector<int>> adj, radj, comps;
 
  StronglyConnected(int N) : N(N), vis(N, false), comp(N, -1), adj(N), radj(N) {}
 
  void AddEdge(int x, int y) {
    adj[x].emplace_back(y);
    radj[y].emplace_back(x);
  }
 
  void Dfs(int u) {
    vis[u] = true;
    for (auto v : adj[u]) if (!vis[v]) Dfs(v);
    todo.emplace_back(u);
  }
 
  void Dfs2(int u, int x, vector<int> &vec) {
    comp[u] = x; vec.emplace_back(u);
    for (auto v : radj[u]) if (comp[v] == -1) Dfs2(v, x, vec);
  }
 
  void Kosaraju() {
    for (int i = 0; i < N; i++) if (!vis[i]) Dfs(i);
    reverse(begin(todo), end(todo));
    for (auto i : todo) if (comp[i] == -1) {
      comps.emplace_back();
      Dfs2(i, int(comps.size()) - 1, comps.back());
    }
  }
};
 

void Main() {
  int n;
  cin >> n;
  vector<int> coordA, coordB;
  vector<array<int, 3>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i][0];
    coordA.emplace_back(a[i][0]);
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i][1];
    coordB.emplace_back(a[i][1]);
  }
  sort(begin(coordA), end(coordA));
  coordA.resize(unique(begin(coordA), end(coordA)) - begin(coordA));
  sort(begin(coordB), end(coordB));
  coordB.resize(unique(begin(coordB), end(coordB)) - begin(coordB));
  for (int i = 0; i < n; i++) {
    a[i][0] = lower_bound(begin(coordA), end(coordA), a[i][0]) - begin(coordA);
    a[i][1] = lower_bound(begin(coordB), end(coordB), a[i][1]) - begin(coordB);
  }

  StronglyConnected G(coordA.size() + coordB.size());
  for (int i = 1; i < coordA.size(); i++) {
    G.AddEdge(i, i - 1);
  }
  for (int i = 1; i < coordB.size(); i++) {
    G.AddEdge(coordA.size() + i, coordA.size() + i - 1);
  }

  for (int i = 0; i < n; i++) {
    G.AddEdge(a[i][0], coordA.size() + a[i][1]);
    G.AddEdge(coordA.size() + a[i][1], a[i][0]);
  }

  G.Kosaraju();
  string ans(n, '0');
  vector<int> mark(4 * n);
  for (auto i : G.comps[0]) {
    // cout << i << ' ';
    mark[i] = 1;
  }
  for (int i = 0; i< n; i++) {
    if (mark[a[i][0]]) ans[i] = '1';
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