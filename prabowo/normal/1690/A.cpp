#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
int a[N];

int solve() {
  scanf("%d", &n);

  int h1 = n / 3 + 1;
  int h2 = n / 3;
  int h3 = n / 3 - 1;

  if (n % 3 == 1) {
    ++h1;
  } else if (n % 3 == 2) {
    ++h1;
    ++h2;
  }

  printf("%d %d %d\n", h2, h1, h3);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc + 1);
    solve();
  }
  return 0;
}