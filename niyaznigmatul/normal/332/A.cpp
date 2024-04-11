#include <cstdio>
#include <cstring>

char s[3333];

int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  int m = strlen(s);
  int ans = 0;
  for (int i = n; i < m; i += n) {
    if (s[i - 3] == s[i - 2] && s[i - 2] == s[i - 1]) ++ans;
  }
  printf("%d\n", ans);
}