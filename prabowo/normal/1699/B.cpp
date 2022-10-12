#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m;

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int bit = (i ^ j) & 1;
      if ((i % 4 >= 2) != (j % 4 >= 2)) bit ^= 1;
      printf("%d ", bit);
    }
    printf("\n");
  }
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc + 1);
    solve();
  }
  return 0;
}