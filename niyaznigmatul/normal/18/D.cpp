#include <cstdio>

int const N = 123456;

int ans[N], type[N], f[N], was[N];
int cn;

void two() {
  for (int i = 0; i < cn; i++) ans[i] *= 2;
  for (int i = 0; i < cn; i++) {
    if (ans[i] >= 10) {
      ans[i + 1]++;
      ans[i] -= 10;
    }
  }
  while (ans[cn] != 0) ++cn;
}

void add() {
  ans[0]++;
  for (int i = 0; ; i++) {
    if (ans[i] >= 10) {
      ans[i + 1]++;
      ans[i] -= 10;
    } else break;
  }
  while (ans[cn] != 0) ++cn;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    char s[10];
    int x;
    scanf("%s%d", s, &x);
    type[i] = s[0] == 'w';
    f[i] = x;
  }
  cn = 0;
  for (int i = 2000; i >= 0; i--) {
    two();
    int sell = -1;
    for (int j = 0; j < n; j++) {
      if (f[j] != i || type[j] != 0) continue;
      sell = j;
      break;
    }
    if (sell < 0) continue;
    int win = -1;
    for (int j = sell; j >= 0; j--) {
      if (was[j]) break;
      if (f[j] != i || type[j] != 1) continue;
      win = j;
      break;
    }
    if (win < 0) continue;
    for (int j = win; j <= sell; j++) was[j] = true;
    add();
  }
  if (cn <= 0) cn = 1;
  for (int i = cn - 1; i >= 0; i--) putchar('0' + ans[i]);
  puts("");
}