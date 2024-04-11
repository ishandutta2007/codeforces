#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
int s[N], f[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &s[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &f[i]);
  }

  int lst = -1;
  for (int i = 0; i < n; ++i) {
    if (lst < s[i]) {
      printf("%d ", f[i] - s[i]);
    } else {
      printf("%d ", f[i] - lst);
    }
    lst = f[i];
  }
  printf("\n");
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