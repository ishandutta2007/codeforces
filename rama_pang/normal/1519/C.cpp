#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

void Main() {
  int N;
  cin >> N;

  vector<vector<int>> ls(N);
  vector<int> X(N), Y(N);
  for (int i = 0; i < N; i++) cin >> X[i];
  for (int i = 0; i < N; i++) cin >> Y[i];
  for (int i = 0; i < N; i++) {
    ls[--X[i]].emplace_back(Y[i]);
  }

  vector<lint> ans(N + 1);
  vector<lint> sum(N + 1);
  for (int i = 0; i < N; i++) {
    sort(begin(ls[i]), end(ls[i]));
    reverse(begin(ls[i]), end(ls[i]));
    for (int j = 0; j < ls[i].size(); j++) {
      sum[j + 1] = sum[j] + ls[i][j];
    }
    for (int k = 1; k <= ls[i].size(); k++) {
      int lo = 1, hi = ls[i].size();
      while (lo < hi) {
        int md = (lo + hi + 1) / 2;
        if (1ll * k * md <= ls[i].size()) {
          lo = md;
        } else {
          hi = md - 1;
        }
      }
      assert(1ll * k * lo <= ls[i].size());
      assert(1ll * k * lo + k > ls[i].size());
      ans[k] += sum[k * lo];
    }
  }

  for (int i = 1; i <= N; i++) {
    cout << ans[i] << " ";
  }
  cout << '\n';
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