#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const ll INF=1e18;
int n, m;
ll a[100][100], dp[100][100];

ll check(ll x) {
	if (x>a[0][0])
		return INF;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			dp[i][j]=i||j?INF:a[0][0]-x;
			if (x+i+j>a[i][j])
				continue;
			ll cur=a[i][j]-(x+i+j);
			if (i)
				dp[i][j]=min(dp[i][j], dp[i-1][j]+cur);
			if (j)
				dp[i][j]=min(dp[i][j], dp[i][j-1]+cur);
		}
	}
	return dp[n-1][m-1];
}

void solve() {
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> a[i][j];
	ll ans=INF;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			ans=min(ans, check(a[i][j]-i-j));
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}