#include <cstdio>
#include <algorithm>

int a[1234567], was[1234567];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  std::sort(a, a + n);
  int l = (n - 1) / 2;
  int r = n;
  while (l < r - 1) {
    int mid = (l + r) >> 1;
    int k = n - mid;
    bool ok = true;
    for (int i = 0; i < k; i++) {
      if (a[i] * 2 > a[n - k + i]) {
        ok = false;
        break;
      }
    }
    if (ok) r = mid; else l = mid;
  }
  printf("%d\n", r);
}