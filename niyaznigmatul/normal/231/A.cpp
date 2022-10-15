#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    if (x + y + z > 1) ++ans;
  }
  printf("%d\n", ans);
  
}