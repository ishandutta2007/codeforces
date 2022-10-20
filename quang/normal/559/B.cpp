#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
char a[N], b[N];

bool cmp(char *u, int l1, int r1, int l2, int r2) {
  for (int i = l1, j = l2; i <= r1; i++, j++) {
    if (u[i] != u[j]) {
      return u[i] > u[j];
    }
  }
  return 0;
}

void build(char *u, int l, int r) {
  if ((r - l + 1) % 2) {
    return;
  }
  int m = (l + r) >> 1;
  build(u, l, m);
  build(u, m + 1, r);
  if (cmp(u, l, m, m + 1, r)) {
    for (int i = l; i <= m; i++) {
      swap(u[i], u[i + m + 1 - l]);
    }
  }
}

void out() {
  for (int i = 1; i <= n; i++) {
    if (a[i] != b[i]) {
      puts("NO");
      return;
    }
  }
  puts("YES");
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> (a + 1) >> (b + 1);
  n = strlen(a + 1);
  build(a, 1, n);
  build(b, 1, n);
  out();
  return 0;
}