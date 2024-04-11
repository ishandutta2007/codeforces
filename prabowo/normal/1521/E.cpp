#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int M = 5000;

pair<int, int> a[N];

int m, k;
int ans[M + 5][M + 5];

int solve() {
  scanf("%d %d", &m, &k);
  for (int i = 0; i < k; ++i) {
    scanf("%d", &a[i].first);
    a[i].second = i + 1;
  }
  sort(a, a + k, greater<pair<int, int>>());
  while (k > 0 && a[k - 1].first == 0) --k;

  if (k == 0) return 0 * printf("0\n");

  int n = 1;
  while (n * n - (n / 2) * (n / 2) < m) ++n;
  while (n * ((n + 1) / 2) < a[0].first) ++n;

  vector<pair<int, int>> cells[4];
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
    cells[(i & 1) * 2 + (j & 1)].emplace_back(i, j);
  }

  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) ans[i][j] = 0;

  for (int i = 0; i < k; ++i) {
    if (cells[1].size() < cells[2].size()) swap(cells[1], cells[2]);
    for (int j = 0; j < a[i].first; ++j) {
      if (!cells[1].empty()) {
        ans[cells[1].back().first][cells[1].back().second] = a[i].second;
        cells[1].pop_back();
      } else {
        ans[cells[0].back().first][cells[0].back().second] = a[i].second;
        cells[0].pop_back();
      }
    }
  }

  printf("%d\n", n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) printf("%d ", ans[i][j]);
    printf("\n");
  }
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}