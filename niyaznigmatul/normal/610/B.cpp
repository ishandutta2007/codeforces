#include <bits/stdc++.h>

int const N = 1234567;

int a[N], b[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  int mn = 1 << 30;
  for (int i = 0; i < n; i++) {
    if (a[i] < mn) mn = a[i];
  }
  int maxb = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == mn) {
      for (int j = 0; j < n; j++) {
        b[j] = a[(i + j) % n];
      }
      break;
    }
  }
  for (int i = 0; i < n; ) {
    if (b[i] == mn) {
      i++;
      continue;
    }
    int j = i;
    while (j < n && b[j] != mn) ++j;
    if (j - i > maxb) maxb = j - i;
    i = j;
  }
  printf("%lld\n", (long long) mn * n + maxb);
}