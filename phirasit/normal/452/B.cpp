#include <stdio.h>

int n, m;

int main() {
  scanf("%d%d", &n, &m);
  if(n == 0) {
    printf("0 1\n");
    printf("0 %d\n", m);
    printf("0 0\n");
    printf("0 %d\n", m-1);
  }else if(m == 0) {
    printf("1 0\n");
    printf("%d 0\n", n);
    printf("0 0\n");
    printf("%d 0\n", n-1);
  }else if(n <= 3 and n <= m) {
    printf("0 0\n");
    printf("%d %d\n", n, m);
    printf("%d 0\n", n);
    printf("0 %d\n", m);
  }else if(m <= 3 and m <= n) {
    printf("0 0\n");
    printf("%d %d\n", n, m);
    printf("0 %d\n", m);
    printf("%d 0\n", n);
  }else if(n > m) {
    printf("%d %d\n", 0, 1);
    printf("%d %d\n", n, m);
    printf("%d %d\n", 0, 0);
    printf("%d %d\n", n, m-1);
  }else {
    printf("%d %d\n", 1, 0);
    printf("%d %d\n", n, m);
    printf("%d %d\n", 0, 0);
    printf("%d %d\n", n-1, m);
  }
  return 0;
}