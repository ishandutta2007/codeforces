#include <cstdio>
#include <algorithm>

int ans[123];

int main() {
  int n, d, m;
  scanf("%d%d%d", &n, &d, &m);
  for (int i = 0; i < n - 2; i++) {
    int cur = std::max(1, std::min(d, m));
    ans[i] = cur;
    d = cur - d;
  }
  if (d > m - 1 || d < -m + 1) puts("-1"); else {
    if (d >= 0) ans[n - 2] = 1 + d, ans[n - 1] = 1; else
      ans[n - 2] = 1, ans[n - 1] = 1 - d;
    for (int i = 0; i < n; i++) {
      if (i > 0) putchar(' ');
      printf("%d", ans[i]);
    }
    puts("");
  }
}