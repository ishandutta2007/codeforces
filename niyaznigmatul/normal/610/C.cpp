#include <bits/stdc++.h>

int a[1111][1111];

int main() {
  int n;
  scanf("%d", &n);
  a[0][0] = 1;
  for (int i = 0; i < n; i++) {
    int half = 1 << i;
    for (int j = 0; j < half; j++) {
      for (int k = 0; k < half; k++) {
        a[j + half][k] = a[j][k + half] = a[j][k];
        a[j + half][k + half] = 1 - a[j][k];
      }
    }
  }
  for (int i = 0; i < 1 << n; i++) {
    for (int j = 0; j < 1 << n; j++) {
      putchar(a[i][j] ? '*' : '+');
    }
    puts("");
  }
}