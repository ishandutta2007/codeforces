#include <cstdio>

int const N = 123456;

int a[N];
int n;

bool solve() {
  int m1 = 1 << 30;
  int m2 = -(1 << 30);
  int third = -1;
  int second = -1;
  int first = -1;
  for (int i = 0; i < n; i++) {
    if (a[i] < m2) {
      third = i;
      --i;
      while (a[i] != m2) --i;
      second = i;
      --i;
      while (a[i] >= m2) --i;
      first = i;
      break;
    }
    if (a[i] > m1 && a[i] > m2) m2 = a[i];
    if (a[i] < m1) m1 = a[i];
  }
  if (first >= 0) {
    puts("3");
    printf("%d %d %d\n", first + 1, second + 1, third + 1);
    return true;
  } else return false;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  if (solve()) return 0;
  for (int i = 0; i < n; i++) a[i] = -a[i];
  if (solve()) return 0;
  puts("0");
}