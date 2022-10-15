#include <cstdio>

int s[1234567];

int main() {
  int c = getchar();
  int n = 0;
  while (c <= 32) c = getchar();
  while (c > 32) {
    s[n++] = c;
    c = getchar();
  }
  bool ab = false;
  bool ba = false;
  for (int i = 0; i + 1 < n; i++) {
    if (s[i] == 'A' && s[i + 1] == 'B') {
      if (ba) {
        puts("YES");
        return 0;
      }
    }
    if (s[i] == 'B' && s[i + 1] == 'A') {
      if (ab) {
        puts("YES");
        return 0;
      }
    }
    if (i > 0) {
      if (s[i - 1] == 'A' && s[i] == 'B') {
        ab = true;
      }
      if (s[i - 1] == 'B' && s[i] == 'A') {
        ba = true;
      }
    }
  }
  puts("NO");
}