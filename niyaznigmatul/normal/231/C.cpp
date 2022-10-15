#include <cstdio>
#include <algorithm>

const int N = 222222;
int a[N];
long long b[N];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  std::sort(a, a + n);
  b[0] = a[0];
  for (int i = 1; i < n; i++) b[i] = b[i - 1] + a[i];
  int bc = -1;
  int ans = -(1 << 30);
  for (int i = 0; i < n; ) {
    int j = i;
    while (j < n && a[i] == a[j]) ++j;
    int l = 0;
    int r = i + 1;
    while (l < r - 1) {
      int mid = (l + r) >> 1;
      long long z = b[i - 1];
      if (i - mid > 0) z -= b[i - mid - 1];
      z = (long long) mid * a[i] - z;
      if (z <= k) l = mid; else r = mid;
    }
    l += j - i;
    if (bc < l) {
      bc = l;
      ans = a[i];
    }
    i = j;
  }
  printf("%d %d\n", bc, ans);
}