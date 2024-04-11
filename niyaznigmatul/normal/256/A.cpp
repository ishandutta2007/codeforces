#include <algorithm>
#include <cstdio>

int dp[4444][4444], a[4444], b[4444];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 0; i < n; i++) b[i] = a[i];
  std::sort(b, b + n);
  int m = std::unique(b, b + n) - b;
  for (int i = 0; i < n; i++) {
    a[i] = std::lower_bound(b, b + m, a[i]) - b;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      int val = dp[j][a[i]] + 1;
      int & cur = dp[i][a[j]];
      if (cur < val) cur = val;
      if (ans < val) ans = val;
    }
  }
  printf("%d\n", ans + 1);
}