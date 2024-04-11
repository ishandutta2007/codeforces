#include <cstdio>

int a[333][333];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int c = getchar();
      while (c <= 32) c = getchar();
      a[i][j] = c;
    }
  }
  int x = a[0][0];
  int y = a[0][1];
  bool ok = x != y;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j || i == n - j - 1) {
        if (a[i][j] != x) ok = false;
      } else {
        if (a[i][j] != y) ok = false;
      }
    }
  }
  puts(ok ? "YES" : "NO");
}