#include <bits/stdc++.h>


using namespace std;

int const N = 1234567;

int a[N], b[N];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int c = getchar();
  while (c <= 32) c = getchar();
  for (int i = 0; i < n; i++) {
    a[i] = c - '0';
    b[i] = 1 - a[i];
    c = getchar();
  }
  for (int i = 1; i < n; i++) b[i] += b[i - 1];
  int ans = n + 1;
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) continue;
    int l = 0;
    int r = n + 1;
    while (l < r - 1) {
      int mid = (l + r) >> 1;
      int left = i - mid;
      if (left < 0) left = 0;
      int right = i + mid;
      if (right >= n) right = n - 1;
      int sum = b[right];
      if (left > 0) sum -= b[left - 1];
      if (sum >= k + 1) {
        r = mid;
      } else {
        l = mid;
      }
    }
    if (ans > r) ans = r;
  }
  printf("%d\n", ans);
}