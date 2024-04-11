#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  if (n > 0) {
    printf("%d\n", n);
  } else {
    n = -n;
    int d1 = n % 10;
    int d2 = n / 10 % 10;
    n /= 100;
    if (d1 > d2) d1 = d2;
    printf("%d\n", -(n * 10 + d1));
  }
}