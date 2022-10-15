#include <cstdio>
#include <algorithm>

int const INF = 1 << 30;

int const N = 1234567;
int a[N], p[N], ans[N], id[N];

int main() {
  int n, l, r;
  scanf("%d%d%d", &n, &l, &r);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 0; i < n; i++) scanf("%d", p + i);
  for (int i = 0; i < n; i++) id[i] = i;
  std::sort(id, id + n, [](int i, int j) {
    return p[i] < p[j];
  });
  int cmin = -INF;
  for (int it = 0; it < n; it++) {
    int i = id[it];
    int cur = std::max(cmin + 1, l - a[i]);
    if (cur > r - a[i]) {
      puts("-1");
      return 0;
    }
    ans[i] = cur + a[i];
    cmin = cur;
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) putchar(' ');
    printf("%d", ans[i]);
  }
  puts("");
}