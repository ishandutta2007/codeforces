#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;
  vector<int> A(N + 2);
  vector<int> nxt(N + 2);
  for (int i = 1; i <= N; i++) { // by pigeonhole principle, with N nodes and N edges, a cycle always exist since all nodes have outgoing edges
    cin >> A[i]; // 1 <= (i - A[i]) <= N
    nxt[i] = (i - A[i]); // Directed graph, a loop has subset sum of zero
  }

  vector<int> ans; // a cycle in the graph always have subset sum of 0
  vector<int> vis(N + 2);

  int v = 1;
  while (!vis[v]) {
    vis[v] = 1;
    v = nxt[v];
  }

  int st = v;
  do {
    ans.emplace_back(v);
    v = nxt[v];
  } while (v != st);

  cout << ans.size() << "\n";
  for (auto &i : ans) {
    cout << i << " ";
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}