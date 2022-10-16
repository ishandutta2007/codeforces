#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x = -1, y = -1;
  scanf("%d", &n);
  for (int i = 2; i * i <= n; i++) if (n % i == 0) {
    if (__gcd(i, n / i) == 1) {
      x = i;
      y = n / i;
      break;
    }
  }
  if (x == -1) {
    puts("NO");
    return 0;
  }
  puts("YES\n2");
  for (int i = 1; ; i++) if ((n - 1 - y * i) % x == 0) {
    int j = (n - 1 - y * i) / x;
    printf("%d %d\n%d %d", i, x, j, y);
    return 0;
  }
}