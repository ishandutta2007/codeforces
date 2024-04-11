#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n, m, k;
int a[N];
int ans[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n*2; ++i) {
    scanf("%d", &a[i]);
  }

  sort(a, a + n*2);
  for (int i = 0; i < n; ++i) {
    ans[i*2 + 0] = a[i];
    ans[i*2 + 1] = a[n + i];
  }

  for (int i = 0; i < n*2; ++i) {
    printf("%d ", ans[i]);
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