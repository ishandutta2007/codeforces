#include <bits/stdc++.h>
using namespace std;

const int N = 33;

int n, m;

int solve() {
  scanf("%d %d", &n, &m);
  printf("%d\n", (n*m+1) / 2);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}