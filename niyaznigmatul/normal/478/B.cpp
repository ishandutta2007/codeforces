#include <cstdio>

long long f(long long x) {
  return x * (x - 1) / 2;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  long long mx = f(n - m + 1);
  long long mn = n % m == 0 ? (f(n / m) * m) : (f(n / m) * (m - n % m) + f(n / m + 1) * (n % m));
  printf("%I64d %I64d\n", mn, mx);
}