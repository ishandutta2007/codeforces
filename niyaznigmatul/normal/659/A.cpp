#include <bits/stdc++.h>

int main() {
  int n, a, b;
  scanf("%d%d%d", &n, &a, &b);
  --a;
  while (b != 0) {
    if (b < 0) {
      b++;
      a = (a + n - 1) % n;
    } else {
      b--;
      a = (a + 1) % n;
    }
  }
  printf("%d\n", a + 1);
}