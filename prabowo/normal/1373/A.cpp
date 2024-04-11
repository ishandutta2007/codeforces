#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
const int MOD = 998244353;

int a, b, c;

int solve() {
  scanf("%d %d %d", &a, &b, &c);
  int ans1 = (a < c ? 1 : -1);
  int ans2 = (c < 1LL * a * b ? b : -1);
  printf("%d %d\n", ans1, ans2);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}