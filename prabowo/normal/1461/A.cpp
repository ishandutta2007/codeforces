#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
 
int n, k;
int a[N];

int solve() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    printf("%c", 'a' + (i % 3));
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