#include <cstdio>

int x[222222];
long long a[222222];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", x + i);
  long long s = 0;
  for (int i = 0; i < k; i++) {
    s += x[i];
  }
  a[0] = s;
  for (int i = k; i < n; i++) {
    s += x[i] - x[i - k];
    a[i - k + 1] = s;
  }
  long long best = a[0];
  long long ans = 0;
  int ansi = -1;
  int ansj = -1;
  int curi = 0;
  for (int i = k; i + k <= n; i++) {
    if (best + a[i] > ans) {
      ans = best + a[i];
      ansi = curi;
      ansj = i;
    }
    if (best < a[i - k + 1]) {
      best = a[i - k + 1];
      curi = i - k + 1;
    }
  }
  printf("%d %d\n", ansi + 1, ansj + 1);
}