#include <cstdio>
#include <algorithm>

int p[1234567];

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < k; i++) scanf("%d", p + i);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x;
      scanf("%d", &x);
      int pos = -1;
      for (int e = 0; e < k; e++) {
        if (p[e] == x) {
          pos = e;
          break;
        }
      }
      ans += pos + 1;
      std::rotate(p, p + pos, p + pos + 1);
    }
  }
  printf("%d\n", ans);
}