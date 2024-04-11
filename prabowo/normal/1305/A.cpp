#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, m;
int a[N];
int b[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
  }

  sort(a, a + n);
  sort(b, b + n);

  for (int i = 0; i < n; ++i) {
    printf("%d ", a[i]);
  }
  printf("\n");
  for (int i = 0; i < n; ++i) {
    printf("%d ", b[i]);
  }
  printf("\n");

  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    solve();
  }

  return 0;
}