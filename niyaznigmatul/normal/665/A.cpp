#include <cstdio>

int main() {
  int a, ta, b, tb;
  scanf("%d%d%d%d", &a, &ta, &b, &tb);
  int h, m;
  scanf("%d:%d", &h, &m);
  int start = h * 60 + m;
  int end = start + ta;
  int ans = 0;
  for (int i = 5 * 60; i < 24 * 60; i += b) {
    if (i < end && i + tb > start) {
      ++ans;
    }
  }
  printf("%d\n", ans);
}