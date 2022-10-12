#include <bits/stdc++.h>
using namespace std;

int n, x, m;

int solve() {
  scanf("%d %d %d", &n, &x, &m);
  int L = x, R = x;
  while (m--) {
    int l, r;
    scanf("%d %d", &l, &r);

    if (max(l, L) <= min(r, R)) {
      L = min(l, L);
      R = max(r, R);
    }
  }

  printf("%d\n", R - L + 1);
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