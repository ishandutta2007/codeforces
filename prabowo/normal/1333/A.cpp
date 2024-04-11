#include <bits/stdc++.h>
using namespace std;

int n, m;

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i == 0 && j == 0) printf("W");
      else printf("B");
    }
    printf("\n");
  }
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}