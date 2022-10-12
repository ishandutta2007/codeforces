#include <bits/stdc++.h>
using namespace std;
 
const int N = 1000005;

int dp[N];
int f(int n) {
  if (n == 0) return 1;
  if (n < 0) return 0;
  if (~dp[n]) return dp[n];
  return dp[n] = f(n - 2020) | f(n - 2021);
}

int solve() {
  int n;
  scanf("%d", &n);

  if (f(n)) printf("YES\n"); else printf("NO\n");
  return 0;
}

int main() {
  memset(dp, -1, sizeof dp);
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}