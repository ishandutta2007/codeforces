#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n;
pair<int, int> cells[N];

int solve() {
  scanf("%d", &n);
  ++n;
  cells[0] = {1, 1};
  for (int i = 1; i < n; ++i) {
    scanf("%d", &cells[i].first);
  }
  for (int i = 1; i < n; ++i) {
    scanf("%d", &cells[i].second);
  }
  sort(cells, cells + n);

  int ans = 0;
  for (int i = 1; i < n; ++i) {
    int dx = cells[i].first - cells[i - 1].first;
    int dy = cells[i].second - cells[i - 1].second;

    int odd = (cells[i - 1].first + cells[i - 1].second) & 1;

    if (dx == dy) {
      if (!odd) ans += dx;
    } else {
      ans += ((dx - (odd ^ 1) - dy) + 1) / 2;
    }
  }

  printf("%d\n", ans);
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