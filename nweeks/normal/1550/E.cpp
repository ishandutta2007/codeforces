#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;
const int MAXN = 2e5 + 1;
const int MAXK = 17;
int prefSum[MAXN][MAXK];
int dp[1 << MAXK];
int fstGood[MAXN][MAXK];

bool check(int want) {
  for (int i = 0; i < (1 << k); ++i)
    dp[i] = n + 1;
  dp[0] = 0;

  for (int j = 0; j < k; ++j)
    fstGood[n][j] = n + 1;
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < k; ++j) {
      fstGood[i][j] = fstGood[i + 1][j];
      if (i + want <= n and prefSum[i + want][j] - prefSum[i][j] == want)
        fstGood[i][j] = i;
    }
  }

  for (int mask = 1; mask < (1 << k); ++mask)
    for (int j = 0; j < k; ++j)
      if ((1 << j) & mask)
        if (dp[mask - (1 << j)] < n)
          dp[mask] = min(dp[mask], fstGood[dp[mask - (1 << j)]][j] + want);

  return dp[(1 << k) - 1] <= n;
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k >> s;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < k; ++j)
      prefSum[i + 1][j] = prefSum[i][j] + (s[i] == 'a' + j or s[i] == '?');
  int lo = 0, up = n;
  while (lo < up) {
    int mid = (lo + up + 1) / 2;
    if (check(mid))
      lo = mid;
    else
      up = mid - 1;
  }
  cout << lo << endl;
}