#include <cstdio>

int main() {
  int n, a, b;
  scanf("%d%d%d", &n, &a, &b);
  if (n > a * b) {
    puts("-1");
    return 0;
  }
  int odd = 1;
  int even = 2;
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      if (j > 0) putchar(' ');
      if (((i + j) & 1) == 0) {
        if (odd <= n) {
          printf("%d", odd);
          odd += 2;
        } else putchar('0');
      } else {
        if (even <= n) {
          printf("%d", even);
          even += 2;
        } else putchar('0');
      }
    }
    puts("");
  }
}