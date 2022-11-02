#include <bits/stdc++.h>
#define int long long
#pragma O3

using namespace std;

int const inf = 1LL << 60;



signed main() {
#ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin);
  	freopen("output.txt", "w", stdout);
#endif

  	int n, h, l, r;
  	cin >> n >> h >> l >> r;
  	int a[n];
  	for(int i = 0;i < n;i++) cin >> a[i];
  	int dp[n][h][2];

  	for(int i = 0;i < n;i++) {
  		for(int j = 0;j < h;j++) {
  			dp[i][j][0] = -inf;
  			dp[i][j][1] = -inf;
  		}
  	}

  	for(int i = 0;i < n;i++) {
  		for(int j = 0;j < h;j++) {
  			for(int q = 0;q <= 1;q++) {
  				int cnt = 0;
  				int num = (j + a[i] - 1 + q) % h;

  				if (num >= l && num <= r) cnt++;
  				if (i == 0 && j == 0) dp[i][j][q] = max(dp[i][j][q], cnt);
  				else if (i != 0) dp[i][j][q] = max(dp[i][j][q], cnt + max(dp[i - 1][(j - a[i - 1] + h) % h][1], dp[i - 1][(j - a[i - 1] + 1 + h) % h][0]));
  			}
  		}
  	}

  	int res = 0;
  	for(int i = 0;i < h;i++) res = max(res, max(dp[n - 1][i][0], dp[n - 1][i][1]));
  	cout << res;
}