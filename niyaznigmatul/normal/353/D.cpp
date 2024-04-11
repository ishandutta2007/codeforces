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
  int had = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'F') {
      if (i != had) {
        if (i - had <= ans) ++ans; else ans = i - had;
      }
      had++;
    }
  }
  printf("%d\n", ans);
}