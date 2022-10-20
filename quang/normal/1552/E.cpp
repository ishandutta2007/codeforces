#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n, k;
vector<int> ls[N];
int cur[N];
bool used[N];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n * k; i++) {
    int u;
    cin >> u;
    ls[u].push_back(i);
  }
  vector<pair<int, int>> res(n + 1);

  auto Solve = [&](int l, int r) {
    for (int it = 1; it <= r - l + 1; it++) {
      pair<int, int> min_val(n * k + 1, n * k + 1);
      for (int i = l; i <= r; i++) {
        if (used[i]) continue;
        min_val = min(min_val, {ls[i][cur[i] + 1], i});
      }
      int id = min_val.second;
      int pos = cur[id];
      used[id] = 1;
      res[id] = {ls[id][pos], ls[id][pos + 1]};
      
      for (int i = l; i <= r; i++) {
        if (used[i]) continue;
        while (ls[i][cur[i]] < min_val.first) cur[i]++;
      }
    }
  };

  for (int i = 1; i <= n; i += k - 1) {
    Solve(i, min(i + k - 2, n));
  }
  for (int i = 1; i <= n; i++) {
    cout << res[i].first << ' ' << res[i].second << '\n';
  }
}