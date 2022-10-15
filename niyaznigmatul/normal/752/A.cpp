#include <cstdio>

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  k--;
  int right = k % 2;
  k /= 2;
  printf("%d %d %c\n", (k / m) + 1, (k % m) + 1, right ? 'R' : 'L');
}