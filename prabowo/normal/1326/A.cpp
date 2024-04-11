#include <bits/stdc++.h>
using namespace std;

int n, m;

int solve() {
  scanf("%d", &n);
  if (n == 1) return 0 * printf("-1\n");
  printf("2");
  for (int i = 1; i < n; ++i) printf("3");
  printf("\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}