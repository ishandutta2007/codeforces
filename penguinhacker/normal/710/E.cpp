#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e7;
int n;
ll x, y, dp[mxN+1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> x >> y;
	dp[1]=x;
	for (int i=2; i<=n; ++i) {
		dp[i]=dp[i-1]+x;
		if (i%2==0)
			dp[i]=min(dp[i], dp[i/2]+y);
		else
			dp[i]=min(dp[i], min(dp[(i-1)/2], dp[(i+1)/2])+x+y);
	}
	cout << dp[n];
	return 0;
}