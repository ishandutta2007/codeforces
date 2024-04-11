#include <cstdio>

int a[42];

int main() {
  int x, y, z, x1, y1, z1;
  scanf("%d%d%d", &x, &y, &z);
  scanf("%d%d%d", &x1, &y1, &z1);
  for (int i = 0; i < 6; i++) scanf("%d", a + i);
  int ans = 0;
  if (y < 0) ans += a[0];
  if (y > y1) ans += a[1];
  if (z < 0) ans += a[2];
  if (z > z1) ans += a[3];
  if (x < 0) ans += a[4];
  if (x > x1) ans += a[5];
  printf("%d\n", ans);
}