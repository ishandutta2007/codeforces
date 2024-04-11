#include <cstdio>
#include <algorithm>

int const N = 1234567;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  std::sort(a, a + n);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += (long long) a[i] * std::min(n, i + 2);
  }
  printf("%I64d\n", ans);
}