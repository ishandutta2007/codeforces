#include <cstdio>

int s[1234567];

int main() {
  int c = getchar();
  while (c <= 32) c = getchar();
  int n = 0;
  while (c > 32) {
    s[n++] = c;
    c = getchar();
  }
  for (int i = 1; i < n; i++) {
    if (s[i] == s[i - 1]) {
      int d = 'a';
      while (d == s[i - 1] || (i + 1 < n && s[i + 1] == d)) {
        ++d;
      }
      s[i] = d;
    }
  }
  for (int i = 0; i < n; i++) putchar(s[i]);
  puts("");
}