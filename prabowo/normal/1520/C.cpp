#include <bits/stdc++.h>
using namespace std;
 
const int N = 205;

int n;
int ans[N][N];

int solve() {
  scanf("%d", &n);
  if (n == 2) return 0 * printf("-1\n");
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i + j & 1) {
        ans[i][j] = ++cur;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i + j & 1); else {
        ans[i][j] = ++cur;
      }
    }
  }

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