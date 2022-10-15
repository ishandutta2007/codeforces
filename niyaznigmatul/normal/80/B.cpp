#include <cstdio>

int main() {
  int h, m;
  scanf("%d:%d", &h, &m);
  h %= 12;
  printf("%.17lf %.17lf\n", 30 * h + m * .5, 6. * m);
}