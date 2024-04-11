#include <bits/stdc++.h>
using namespace std;
using lint = long long;

void Solve() {
  int N, M, K;
  cin >> N >> M;

  vector<vector<int>> adj(N);
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].emplace_back(v);
  }
  vector<int> len(N, 0);
  vector<int> ans;
  for (int i = 0; i < N; i++) {
    if (len[i] == 2) {
      ans.emplace_back(i);
    } else {
      for (auto j : adj[i]) {
        len[j] = max(len[j], len[i] + 1);
      }
    }
  }

  cout << ans.size() << "\n";
  for (auto i : ans) {
    cout << i + 1 << " ";
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    Solve();
  }
}