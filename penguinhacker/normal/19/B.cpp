#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
ll dp[4001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	memset(dp, 0x3f, sizeof(dp));
	dp[0]=0;
	cin >> n;
	for (int i=0; i<n; ++i) {
		int t, c; cin >> t >> c, ++t;
		for (int j=n-1+t; j>=t; --j)
			dp[j]=min(dp[j], dp[j-t]+c);
	}
	ll ans=1e18;
	for (int i=n; i<n+2000; ++i)
		ans=min(ans, dp[i]);
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/