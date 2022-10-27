#include <bits/stdc++.h>
using namespace std;
int n, k, _a[10005], _b[10005];
bool ok[30], v[30];
int a[10005], _xor[10005];
inline int _and(int i, int j) {
  printf("and %d %d\n", i, j), fflush(stdout);
  int x;
  scanf("%d", &x);
  return x;
}
inline int _or(int i, int j) {
  printf("or %d %d\n", i, j), fflush(stdout);
  int x;
  scanf("%d", &x);
  return x;
}
int main() {
  cin >> n >> k;
  for (int i = 2; i <= n; i++) {
    int x = _and(1, i), y = _or(1, i);
    _a[i] = x, _b[i] = y;
    for (int j = 0; j < 30; j++) {
      if (x >> j & 1)
        ok[j] = v[j] = 1, a[1] |= 1 << j;
      else if (y >> j & 1)
        _xor[i] |= 1 << j;
      else
        ok[j] = 1, v[j] = 0;
    }
  }
  int x = _or(2, 3);
  for (int j = 0; j < 30; j++)
    if (!ok[j]) {
      ok[j] = 1;
      if ((x >> j & 1) == 0) a[1] |= 1 << j, v[j] = 1;
    }
  for (int i = 2; i <= n; i++) {
    int x = _a[i], y = _b[i];
    for (int j = 0; j < 30; j++) {
      if (x >> j & 1)
        a[i] |= 1 << j;
      else if (y >> j & 1) {
        if (!v[j]) a[i] |= 1 << j;
      }
    }
  }
  sort(a + 1, a + n + 1);
  printf("finish %d\n", a[k]);
}