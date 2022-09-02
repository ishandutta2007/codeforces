#include <cstdio>
#include <cassert>

int main() {
  int n, a, b;
  scanf("%d%d%d",&n,&a,&b);
  if (a * b < n) {
    printf("-1\n");
    return 0;
  }
  int xo = 1;
  int xe = 2;
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      if ((i + j) & 1) {
        printf("%d ", xe > n ? 0 : xe);
        xe += 2;
      } else {
        printf("%d ", xo > n ? 0 : xo);
        xo += 2;
      }
    }
    printf("\n");
  }
  assert(xo > n && xe > n);
  return 0;
}