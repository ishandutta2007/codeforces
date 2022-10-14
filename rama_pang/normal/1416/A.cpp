#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<vector<int>> occ(N);
    for (int i = 0; i < N; i++) {
      cin >> A[i];
      A[i]--;
      occ[A[i]].emplace_back(i);
    }
    vector<int> ans(N + 5, N);
    for (int v = 0; v < N; v++) {
      occ[v].insert(begin(occ[v]), -1);
      occ[v].emplace_back(N);
      int gap = 0;
      for (int i = 0; i + 1 < int(occ[v].size()); i++) {
        gap = max(gap, occ[v][i + 1] - occ[v][i] - 1);
      }
      ans[gap + 1] = min(ans[gap + 1], v);
    }
    for (int i = 1; i <= N; i++) {
      ans[i] = min(ans[i], ans[i - 1]);
    }
    for (int i = 1; i <= N; i++) {
      if (ans[i] == N) {
        cout << -1 << ' ';
      } else {
        cout << ans[i] + 1 << ' ';
      }
    }
    cout << '\n';
  }
  return 0;
}