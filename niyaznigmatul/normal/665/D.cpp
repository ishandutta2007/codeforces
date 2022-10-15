#include <cstdio>

int const N = 3234567;
int np[N];
int a[1234];

int main() {
  for (int i = 2; i < N; i++) {
    if (!np[i]) {
      for (int j = i + i; j < N; j += i) {
        np[j] = true;
      }
    }
  }
  np[0] = np[1] = true;
  int n;
  scanf("%d", &n);
  int ones = 0;
  int mprime = -1;
  int has = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    if (a[i] == 1) ones++;
    if (a[i] != 1 && !np[a[i] + 1]) mprime = a[i];
  }
  has = mprime >= 0 ? 1 : 0;
  if (ones + has > 2) {
    printf("%d\n", ones + has);
    for (int i = 0; i < ones; i++) {
      if (i > 0) putchar(' ');
      putchar('1');
    }
    if (has == 1) {
      putchar(' ');
      printf("%d", mprime);
    }
    puts("");
    return 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (!np[a[i] + a[j]]) {
        puts("2");
        printf("%d %d\n", a[i], a[j]);
        return 0;
      }
    }
  }
  puts("1");
  printf("%d\n", a[0]);
}