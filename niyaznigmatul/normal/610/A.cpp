#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  if ((n & 1) == 0) --n; else n = 0;
  n /= 2;
  n /= 2;
  printf("%d\n", n);
}