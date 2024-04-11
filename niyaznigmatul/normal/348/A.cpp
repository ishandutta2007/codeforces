#include <cstdio>

int a[123456];

int main() {
  int n;
  scanf("%d", &n);
  int ma = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    if (a[i] > ma) ma = a[i];
  }
  long long l = ma - 1;
  long long r = 1LL << 60;
  while (l < r - 1) {
    long long mid = (l + r) >> 1;
    long long s = 0;
    for (int i = 0; i < n; i++) {
      s += mid - a[i];
      if (s > mid) break;
    }
    if (s >= mid) r = mid; else l = mid;
  }
  printf("%I64d\n", r);
}