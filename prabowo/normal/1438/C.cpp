#include <bits/stdc++.h>
using namespace std;
 
const int N = 100005;

int n, m;

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int a;
      scanf("%d", &a);
      if ((i + j & 1) != (a & 1)) ++a;
      printf("%d ", a);
    }
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