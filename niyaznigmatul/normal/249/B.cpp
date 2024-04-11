#include <cstdio>

char s[1234567];

int main() {
  int n, t;
  scanf("%d%d", &n, &t);
  scanf("%s", s);
  int cn = 0;
  int ls = -1;
  for (int i = 0; i < n; i++) if (s[i] == 'H') {
    ++cn;
    ls = i;
  }
  int l = -1;
  int r = cn + 1;
  while (l < r - 1) {
    int mid = (l + r) >> 1;
    int id = 0;
    int count = mid;
    while (id < n && count < cn) {
      if (s[id] == 'S') {
        ++count;
      }
      ++id;
    }
    if (count < cn) {
      l = mid;
      continue;
    }
    --id;
    if (id < ls) id = ls;
    int cur = mid;
    int lb = -1;
    int ans = 1 << 30;
    int dist = 0;
//    printf("mid = %d, id = %d\n", mid, id);
    for (int i = 0; dist <= t && i <= ls; i++) {
      if (s[i] == 'S') {
        ++cur;
        if (cur == 0) {
          dist += 2 * (i - lb);
          lb = -1;
        }
      } else if (s[i] == 'H') {
        --cur;
        if (cur == -1) {
          lb = i;
        }
        if (cur >= -1) {
          int all = dist + 1 + id + id - i;
          if (all < ans) {
            ans = all;
          }
        }
      }
//      printf("i = %d, dist = %d, ans = %d\n", i, dist, ans);
    }
    if (ans <= t) r = mid; else l = mid;
  }
  if (r == cn + 1) r = -1;
  printf("%d\n", r);
}