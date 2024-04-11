#include <cstdio>
#include <algorithm>

int ni() {
  int c = getchar();
  while (c < '0' || c > '9') c = getchar();
  int x = 0;
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x;
}

int a[2333444];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  std::sort(a, a + n);
  long long ans = 0;
  for (int i = 1; i <= n; i <<= 2) {
    for (int j = 0; j < i; j++) {
      ans += a[n - j - 1];
    }
  }
  printf("%I64d\n", ans);
}