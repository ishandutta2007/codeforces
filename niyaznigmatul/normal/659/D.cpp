#include <bits/stdc++.h>

int const N = 1234567;
int x[N], y[N];

int main() {
  int n;
  scanf("%d", &n);  
  scanf("%d%d", x, y);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", x + i, y + i);
  }
  long long area = 0;
  for (int i = 0; i < n; i++) {
    int j = (i + 1) % n;
    area += x[i] * y[j] - x[j] * y[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int j = (i + 1) % n;
    int k = (j + 1) % n;
    int v = (x[j] - x[i]) * (y[k] - y[j]) - (x[k] - x[j]) * (y[j] - y[i]);
    if (area > 0) {
      v = -v;
    }
    if (v > 0) {
      ++ans;
    }
  }
  printf("%d\n", ans);
}