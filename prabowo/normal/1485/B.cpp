#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const int INF = 1e9;

int n, m, k;
int a[N];
int pre[N];

int solve() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  while (m--) {
    int l, r;
    scanf("%d %d", &l, &r);
    --l, --r;

    printf("%d\n", (a[r] - a[l] - (r - l)) * 2 + a[l] - 1 + (k - a[r]));
  }

  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}