#include <cstdio>

int main() {
  int n, q; 
  scanf("%d%d", &n, &q);
  int m = n + 1;
  long long ans = 0;
  for (int i = q + 1; i + i <= m; i++) {
    int cc = (q - 2 * i) * (m - i);
    int v = i + q;
    int k = n - q;
    int ad = m - i;
    int x = n - q;
    int cur = 0;
    for (int j = q + 1; j <= x; j++) {
      ++v;
      cc += ad;
      while (k > q && v * k >= -cc) {
        --k;
      }
      if (k <= q) break;
      int z = k - q;
      cur += z;
    }
    ans += cur;
    if (i + i != m) ans += cur;
  }
  printf("%I64d\n", ans * 3);
}