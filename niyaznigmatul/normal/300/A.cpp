#include <cstdio>
#include <cassert>
#include <algorithm>

int a[111], ans[111], n;

void print(int x) {
  int cn = 0;
  for (int i = 0; i < n; i++) if (ans[i] == x) ++cn;
  assert(cn);
  printf("%d", cn);
  for (int i = 0; i < n; i++) {
    if (ans[i] == x) printf(" %d", a[i]);
  }
  puts("");
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) ans[i] = 3; else {
      if (a[i] > 0) ans[i] = 2; else ans[i] = 1;
    }
  }
  int cn[4];
  cn[1] = cn[2] = cn[3] = 0;
  for (int i = 0; i < n; i++) cn[ans[i]]++;
  if (cn[2] == 0) {
    for (int i = 0, j = 2; j > 0; i++) {
      if (a[i] < 0) ans[i] = 2, j--;
    }
    cn[2] += 2;
    cn[1] -= 2;
  }
  if ((cn[1] & 1) == 0) {
    for (int i = 0; i < n; i++) if (ans[i] == 1) {
      ans[i] = 3;
      break;
    }
  }
  for (int i = 1; i <= 3; i++) print(i);
}