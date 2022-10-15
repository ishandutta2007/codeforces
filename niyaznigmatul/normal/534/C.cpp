#include <cstdio>

int d[1234567];

int main() {
  int n;
  long long got;
  scanf("%d%lld", &n, &got);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", d + i);
    sum += d[i];
  }
  for (int i = 0; i < n; i++) {
    int ans = 0;
    long long max = sum - d[i];
    long long need = got - max;
    if (need > 1) {
      ans += need - 1;
    }
    long long min = n - 1;
    need = got - min;
    if (need < d[i]) {
      ans += d[i] - need;
    }
    if (i > 0) putchar(' ');
    printf("%d", ans);
  }
  puts("");
}