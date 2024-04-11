#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  vector<pair<int, int>> ans;

  int p = 1;
  while (2 * p <= N) {
    p *= 2;
  }

  const auto Solve = [&](const auto &self, int l, int r) {
    if (l == r) {
      return;
    }
    int m = (l + r) / 2;
    self(self, l, m);
    self(self, m + 1, r);
    for (int i = l; i <= m; i++) {
      ans.emplace_back(i, m + 1 + i - l);
    }
  };

  Solve(Solve, 0, p - 1);
  Solve(Solve, N - p, N - 1);

  cout << ans.size() << "\n";
  for (auto i : ans) {
    cout << i.first + 1 << ' ' << i.second + 1 << '\n';
  }
  return 0;
}