#include <cstdio>

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n, m;
  scanf("%d%d", &n, &m);
  char c = 'B';
  char d = 'G';
  if (n > m) {
    int t = n; n = m; m = t;
    char tt = c; c = d; d = tt;
  }
  for (int i = 0; i < n; i++) {
    putchar(d);
    putchar(c);
  }
  for (int i = 0; i < m - n; i++) putchar(d);
  puts("");
}