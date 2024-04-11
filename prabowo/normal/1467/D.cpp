#include <bits/stdc++.h>
using namespace std;
 
const int N = 5005;
const int MOD = 1000000007;
const int INF = 1e9;

int n, k, q;
int a[N];
int cnt[N];

int dp[N][N];
int f(int x, int move) {
  if (x < 0 || x >= n) return 0;
  if (move == 0) return 1;
  if (~dp[x][move]) return dp[x][move];
  return dp[x][move] = (f(x - 1, move - 1) + f(x + 1, move - 1)) % MOD;
}

int solve() {
  memset(dp, -1, sizeof dp);
  scanf("%d %d %d", &n, &k, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  int sum = 0;
  for (int i = 0; i < n; ++i) {
    cnt[i] = 0;
    for (int j = 0; j <= k; ++j) {
      cnt[i] = (1LL * f(i, j) * f(i, k - j) + cnt[i]) % MOD;
    }
    sum = (1LL * cnt[i] * a[i] + sum) % MOD;
  }

  while (q--) {
    // cerr << q << endl;
    int i, x;
    scanf("%d %d", &i, &x);
    --i;

    sum = (sum + 1LL * cnt[i] * (x - a[i])) % MOD;
    a[i] = x;
    if (sum < 0) sum += MOD;

    printf("%d\n", sum);
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