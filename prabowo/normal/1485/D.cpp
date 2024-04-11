#include <bits/stdc++.h>
using namespace std;
 
const int N = 505;
const int M = 1000005;

int n, m;
int a[N][N];

int f(int x) {
  for (int k = 1; ; ++k) {
    if ((720720 - k*k*k*k) % x == 0) return 720720 - k*k*k*k;;
  }
}


int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &a[i][j]);
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i + j & 1) {
        printf("%d ", f(a[i][j]));
      } else {
        printf("%d ", 720720);
      }
    }
    printf("\n");
  }
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}