#include <bits/stdc++.h>
using namespace std;

const int N = 35;

int n;
int a[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  int ans = 0;
  for (int i = n - 2; i >= 0; --i) {
    while (a[i] >= a[i + 1]) {
      if (a[i] == 0) return 0 * printf("-1\n");
      ++ans;
      a[i] /= 2;
    }
  }

  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc + 1);
    solve();
  }
}