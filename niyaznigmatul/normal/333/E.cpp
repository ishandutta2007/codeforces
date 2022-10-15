#include <cstdio>
#include <cmath>

int d[3333][3333], x[3333], y[3333], n, mid;
unsigned int msk[3333][3333 >> 5];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d%d", x + i, y + i);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int dx = x[i] - x[j];
      int dy = y[i] - y[j];
      d[i][j] = d[j][i] = dx * dx + dy * dy;
    }
  }
  int l = 0;
  int r = 1000000000;
  while (l < r - 1) {
    mid = (l + r) >> 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (d[i][j] >= mid) {
          msk[i][j >> 5] |= ((unsigned int) 1) << j;
        } else {
          msk[i][j >> 5] &= ~(((unsigned int) 1) << j);
        }        
      }
    }
    bool ok = false;
    for (int i = 0; !ok && i < n; i++) {
      for (int j = i + 1; !ok && j < n; j++) {
        if (d[i][j] < mid) continue;
        for (int k = 0; k <= n >> 5; k++) {
          if ((msk[i][k] & msk[j][k]) != 0) {
            ok = true;
            break;
          }
        }
      }
    } 
    if (ok) l = mid; else r = mid;
  }
  printf("%.17f\n", sqrt(1. * l) * .5);
}