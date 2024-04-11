#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  int la = -1;
  int lb = -1;
  int cn = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (la == a && lb == b) {
      ++cn;
    } else {
      cn = 1;
    }
    la = a;
    lb = b;
    if (cn > ans) ans = cn;
  }
  printf("%d\n", ans);
}