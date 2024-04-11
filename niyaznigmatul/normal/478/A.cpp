#include <cstdio>

int main() {
  int x = 0;
  for (int i = 0; i < 5; i++) {
    int y;
    scanf("%d", &y);
    x += y;
  }
  if (x % 5 == 0 && x / 5 > 0) printf("%d\n", x / 5); else puts("-1");
}