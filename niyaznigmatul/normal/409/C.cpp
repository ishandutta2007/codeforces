#include <cstdio>

const int a[] = {1, 1, 2, 7, 4};

int main() {
  int ans = 1 << 30;
  for (int i = 0; i < 5; i++) {
    int x;
    
    scanf("%d", &x);
    int cur = x / a[i];
    if (ans > cur) ans = cur;
  }
  printf("%d\n", ans);
}