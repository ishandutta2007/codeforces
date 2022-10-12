#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n;

int solve() {
  scanf("%d", &n);

  if (n == 1) return 0 * printf("a\n");

  for (int i = 0; i < n / 2; ++i) {
    printf("a");
  }
  printf("b");
  for (int i = 0; i < n / 2 - 1; ++i) {
    printf("a");
  }
  if (n & 1) printf("c");

  printf("\n");
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