#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const int INF = 1e9;

int n, m, k;
int a[N];
int b[N];

int solve() {
  scanf("%d", &n);
  int maxA = 0, sumA = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    sumA += a[i];
    maxA = max(maxA, sumA);
  }
  scanf("%d", &m);
  int maxB = 0, sumB = 0;
  for (int i = 0; i < m; ++i) {
    scanf("%d", &b[i]);
    sumB += b[i];
    maxB = max(maxB, sumB);
  }

  // cerr << maxA << " " << maxB << e/ndl;

  int ans = maxA + maxB;

  printf("%d\n", ans);
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