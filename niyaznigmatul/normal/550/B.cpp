#include <cstdio>

int c[12345];

int main() {
  int n, l, r, x;
  scanf("%d%d%d%d", &n, &l, &r, &x);
  for (int i = 0; i < n; i++) scanf("%d", c + i);
  int ans = 0;
  for (int mask = 0; mask < 1 << n; mask++) {
    int sum = 0;
    int mx = 0;
    int mn = 1 << 30;
    for (int i = 0; i < n; i++) {
      if (((mask >> i) & 1) == 1) {
        sum += c[i];
        if (c[i] > mx) mx = c[i];
        if (c[i] < mn) mn = c[i];
      }
    }
    if (sum >= l && sum <= r && mx - mn >= x) {
      ++ans;
    }
  }
  printf("%d\n", ans);
}