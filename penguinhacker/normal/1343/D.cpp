#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k, a[200000];

void solve() {
	cin >> n >> k;
	vector<int> dp(2*k+1, 0);
	vector<int> cnt(2*k+1, 0);
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=0; i<n/2; ++i) {
		int x=min(a[i], a[n-i-1]), y=max(a[i], a[n-i-1]);
		dp[x+1]++;
		dp[y+k+1]--;
		cnt[x+y]++;
	}
	for (int i=3; i<=2*k; ++i)
		dp[i]+=dp[i-1];
	int ans=1e9;
	for (int i=2; i<=2*k; ++i)
		ans=min(ans, n-cnt[i]-dp[i]);
	cout << ans << '\n';
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