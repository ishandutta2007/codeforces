#include <cstdio>

int x[4444], y[4444];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    x[i] = i;
    y[i] = 4000 * i;
  }
  int tot = 0;
  long long d = 1LL << 60;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ++tot;
      if (x[j] - x[i] >= d) break;
      long long dx = x[i] - x[j];
      long long dy = y[i] - y[j];
      long long dd = dx * dx + dy * dy;
      if (d > dd) d = dd;
    }
  }
  if (tot <= k) {
    puts("no solution");
  } else {
    for (int i = 0; i < n; i++) {
      printf("%d %d\n", x[i], y[i]);
    }
  }
}