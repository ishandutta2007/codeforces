#include <cstdio>

int cc[1234], cn[1234], a[1234], ans[1234];

int main() {
  int n;
  scanf("%d", &n);
  n += n;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    cn[a[i]]++;
  }
  int c1 = 0;
  for (int i = 10; i < 100; i++) if (cn[i] == 1) ++c1;
  int c2 = 0;
  int first = 0;
  int ans1 = 0;
  int ans2 = 0;
  for (int i = 0; i < n; i++) {
    if (cn[a[i]] >= 2) {
      if (cc[a[i]] == 0) {
        ans[i] = 1;
        ++cc[a[i]];
        ++first;
        ++ans1;
      } else if (cc[a[i]] == 1) {
        ans[i] = 2;
        ++cc[a[i]];
        ++ans2;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (cn[a[i]] == 1) {
      if (c2 < c1 / 2) {
        ans[i] = 1;
        ++first;
        ++ans1;
      } else {
        ans[i] = 2;
        ++ans2;
      }
      ++c2;
    }
  }
  for (int i = 0; i < n; i++) {
    if (ans[i] == 0) {
      if (first < n / 2) {
        ++first;
        ans[i] = 1;
      } else {
        ans[i] = 2;
      }
    }
  }
  printf("%d\n", ans1 * ans2);
  for (int i = 0; i < n; i++) {
    if (i > 0) putchar(' ');
    printf("%d", ans[i]);
  }
  puts("");
}