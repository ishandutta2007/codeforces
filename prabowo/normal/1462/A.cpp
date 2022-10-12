#include <bits/stdc++.h>
using namespace std;
 
const int N = 300005;

int n;
int a[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  for (int l = 0, r = n - 1; l <= r; ++l, --r) {
    printf("%d ", a[l]);
    if (l != r) printf("%d ", a[r]);
  }
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