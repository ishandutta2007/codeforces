#include <stdio.h>

int main() {
  int c = getchar();
  while (c <= 32) {
    c = getchar();
  }
  int first = 1;
  while (c > 32) {
    c -= '0';
    if (9 - c < c) if (!first || c < 9) c = 9 - c;
    first = 0;
    putchar(c + '0');
    c = getchar();
  }
  puts("");
}