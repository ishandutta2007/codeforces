#ifndef LOCAL
#include <bits/stdc++.h>
#else
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#endif
using namespace std;
const int maxn = 1e6 + 5;
long long dp[maxn][2],a[maxn];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  memset(dp,0x3f3f3f3f,sizeof(dp));
  long long n,r1,r2,r3,d;
  cin >> n >> r1 >> r2 >> r3 >> d;
  for(int i = 1; i <= n; i++) cin >> a[i];
  dp[0][0] = 0;
  r1 = min(min(r1,r3),r2);
  for(int i = 1; i <= n; i++)
  {
    dp[i][0] = min(min(dp[i-1][0],dp[i-1][1]) + r1*a[i]+r3, dp[i][0]);
    dp[i][0] = min(dp[i-1][1] + min(r1*(a[i]+2), r2+r1), dp[i][0]);
    dp[i][1] = min(dp[i-1][0] + min(r1*(a[i]+2), r2+r1) + d*2, dp[i][1]);
  }
  cout << min(min(dp[n][0], dp[n][1]), dp[n-1][1] + r1*a[n]+r3-d) + d*(n-1) << endl;
  return 0;
}