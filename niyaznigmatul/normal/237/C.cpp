#include <cstdio>

int ip[1234567];

int main() {
  for (int i = 2; i <= 1000000; i++) ip[i] = 1;
  for (int i = 2; i <= 1000000; i++) {
    if (!ip[i]) continue;
    for (int j = i + i; j <= 1000000; j += i) ip[j] = 0;
  }
  int a, b, k;
  scanf("%d%d%d", &a, &b, &k);
  int left = k - 1;
  int right = b - a + 2;
  while (left < right - 1) {
    int mid = (left + right) >> 1;
    int cn = 0;
    for (int i = 0; i < mid; i++) {
      cn += ip[i + a];
    }
    bool ok = cn >= k;
    for (int i = a + mid; ok && i <= b; i++) {
      cn += ip[i] - ip[i - mid];
      ok &= cn >= k;
    }
    if (ok) right = mid; else left = mid;
  }
  printf("%d\n", right > b - a + 1 ? -1 : right);
}