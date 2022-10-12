#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n, k1, k2;
int w, b;

bool can(int k1, int k2, int x) {
  int cnt = 0;
  if (k1 % 2 == 0 && k2 % 2 == 0) {
    cnt = k1 / 2 + k2 / 2;
  } else if (k1 % 2 == 1 && k2 % 2 == 1) {
    cnt = 1 + (k1 / 2) + (k2 / 2);
  } else {
    cnt = (k1 / 2) + (k2 / 2);
  }
  return cnt >= x;
}

int solve() {
  scanf("%d %d %d", &n, &k1, &k2);
  scanf("%d %d", &w, &b);

  printf(can(k1, k2, w) && can(n - k1, n - k2, b) ? "YES\n" : "NO\n");

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