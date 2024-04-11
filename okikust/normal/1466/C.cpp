#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200100
#define MOD 1000000007  //998244353
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>


int main() {
	int dp[2][2][2];
	int t, n, ans;
	char a[N];
	rep(i, N)a[i] = 0;
	cin >> t;
	rep(tt, t) {
		cin >> a;
		n = strlen(a);
		if (n == 1) {
			cout << 0 << endl;
			rep(i, n + 1)a[i] = 0;
			continue;
		}
		rep(i, 2) {
			rep(j, 2) {
				dp[0][i][j] = i + j;
			}
		}
		if (a[0] == a[1])dp[0][0][0] = MOD;
		rep2(i, 2, n - 1) {
			if (a[i] == a[i - 1])dp[1][0][0] = MOD;
			else if (a[i] == a[i - 2])dp[1][0][0] = dp[0][1][0];
			else dp[1][0][0] = min(dp[0][0][0], dp[0][1][0]);

			if (a[i] == a[i - 2])dp[1][1][0] = dp[0][1][1];
			else dp[1][1][0] = min(dp[0][0][1], dp[0][1][1]);

			dp[1][0][1] = min(dp[0][0][0], dp[0][1][0]) + 1;
			dp[1][1][1] = min(dp[0][0][1], dp[0][1][1]) + 1;

			rep(i, 2) {
				rep(j, 2)dp[0][i][j] = dp[1][i][j];
			}
		}
		ans = MOD;
		rep(i, 2) {
			rep(j, 2)ans = min(ans, dp[0][i][j]);
		}
		cout << ans << endl;
		rep(i, n + 1)a[i] = 0;
	}
	

	return 0;
}