#include <cstdio>
#include <algorithm>

int const N = 123456;

int a[N];
int n;

int has(int x) {
  int j = 0;
  for (int i = 0; i < n; i++) {
    while (j < n && a[j] - a[i] < x) ++j;
    if (j < n && a[j] - a[i] == x) return i;
  }
  return -1;
}

int main() {
  int len, x, y;
  scanf("%d%d%d%d", &n, &len, &x, &y);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  if (has(x) >= 0 && has(y) >= 0) {
    puts("0");
    return 0;
  }
  int id = has(x + y);
  if (id >= 0) {
    puts("1");
    printf("%d\n", a[id] + x);
    return 0;
  }
  id = has(x);
  if (id >= 0) {
    puts("1");
    printf("%d\n", y);
    return 0;
  }
  id = has(y);
  if (id >= 0) {
    puts("1");
    printf("%d\n", x);
    return 0;
  }
  id = has(y - x);
  if (id >= 0 && a[id] + y <= len) {
    puts("1");
    printf("%d\n", a[id] + y);
    return 0;
  }
  for (int i = 0; i < n; i++) a[i] = -a[i];
  std::reverse(a, a + n);
  id = has(y - x);
  if (id >= 0 && a[id] + y <= 0) {
    puts("1");
    printf("%d\n", -(a[id] + y));
    return 0;
  }
  puts("2");
  printf("%d %d\n", x, y);
}