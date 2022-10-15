#include <cstring>
#include <cstdio>
#include <algorithm>

int a[123456];
char s[123456];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  for (int i = 1; i < n; i++) {
    a[i] = s[i] == s[i - 1];
  }
  a[0] = 0;
  for (int i = 1; i < n; i++) {
    a[i] += a[i - 1];
  }
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", a[r - 1] - a[l - 1]);
  }
}