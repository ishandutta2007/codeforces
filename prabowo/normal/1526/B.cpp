#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n;

int solve() {
  scanf("%d", &n);

  for (int i = 0; i < 11; ++i) {
    if (111 * i > n) break;
    if ((n - 111 * i) % 11 == 0) return 0 * printf("YES\n");
  }

  printf("NO\n");
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