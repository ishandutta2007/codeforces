#include <bits/stdc++.h>

int a[42][42], b[42][42];

int main() {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      int c = getchar();
      while (c <= 32) c = getchar();
      a[i][j] = c;
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      int c = getchar();
      while (c <= 32) c = getchar();
      b[i][j] = c;
    }
  }
  for (int it = 0; it < 1000; it++) {
    if (a[0][0] == 'X') {
      std::swap(a[0][0], a[0][1]);
    } else if (a[1][0] == 'X') {
      std::swap(a[1][0], a[0][0]);
    } else if (a[1][1] == 'X') {
      std::swap(a[1][1], a[1][0]);
    } else {
      std::swap(a[0][1], a[1][1]);
    }
    bool eq = true;
    for (int i = 0; eq && i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        if (a[i][j] != b[i][j]) {
          eq = false;
          break;
        }
      }
    }
    if (eq) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
}