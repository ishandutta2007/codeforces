#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  if (n <= 2) {
    puts("1");
    puts("1");
    return 0;
  }
  if (n == 3) {
    puts("2");
    puts("1 3");
    return 0;
  }
  printf("%d\n", n);
  int last = n;
  if (~last & 1) last--;
  while (last >= 1) {
    printf("%d ", last);
    last -= 2;
  }
  last = n;
  if (last & 1) last--;
  while (last >= 1) {
    printf("%d", last);
    if (last != 2) putchar(' ');
    last -= 2;
  }
  puts("");
}