#include <stdio.h>

int vx[1234], vy[1234];

int main() {
  int n, x0, y0;
  scanf("%d%d%d", &n, &x0, &y0);
  int i;
  int ans = n;
  for (i = 0; i < n; i++) {
    scanf("%d%d", vx + i, vy + i);
    vx[i] -= x0;
    vy[i] -= y0;
    int j;
    for (j = 0; j < i; j++) if (vx[i] * vy[j] == vx[j] * vy[i]) {
      --ans;
      break;
    }
  }
  printf("%d\n", ans);
  return 0;
}