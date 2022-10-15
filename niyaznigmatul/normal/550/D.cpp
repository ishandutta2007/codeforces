#include <cstdio>
#include <cassert>
int d[123456], from[1234567], to[1234567];
int main() {
  int k;
  scanf("%d", &k);
  if (k % 2 == 0) {
    puts("NO");
    return 0;
  }
  puts("YES");
  if (k == 1) {
    puts("2 1");
    puts("1 2");
    return 0;
  }
  int n = k + 2;
  int cn = 0;
  for (int i = 0; i < k - 1; i++) {
    for (int j = 1; j <= (k - 3) / 2; j++) {
      from[cn] = i;
      to[cn] = (i + j) % (k - 1);
      ++cn;
    }
  }
  from[cn] = k - 1;
  to[cn] = k;
  ++cn;
  for (int i = 0; i < k - 1; i++) {
    from[cn] = k - 1;
    to[cn] = i;
    ++cn;
    from[cn] = k;
    to[cn] = i;
    ++cn;
  }
  for (int i = 0; i < k - 1; i++) {
    from[cn] = k + 1;
    to[cn] = i;
    ++cn;
  }
  for (int i = 0; i < cn; i++) {
    from[i + cn] = from[i] + n;
    to[i + cn] = to[i] + n;
  }
  cn += cn;
  from[cn] = n - 1;
  to[cn] = 2 * n - 1;
  ++cn;
  n += n;
  for (int i = 0; i < cn; i++) {
    d[from[i]]++;
    d[to[i]]++;
  }
  for (int i = 0; i < n; i++) assert(d[i] == k);
  for (int i = 0; i < n; i++) assert(from[i] >= 0 && from[i] < n && to[i] >= 0 && to[i] < n);
  printf("%d %d\n", n, cn);
  for (int i = 0; i < cn; i++) {
    printf("%d %d\n", from[i] + 1, to[i] + 1);
  }
}