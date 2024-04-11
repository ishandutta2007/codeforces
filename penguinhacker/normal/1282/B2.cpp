#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n,p,k, a[200000];
ll dp[200001], pref[200001];

void solve() {
	cin >> n >> p >> k;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	sort(a, a+n);

	dp[0]=0;
	for (int i=1; i<k; ++i)
		dp[i]=dp[i-1]+a[i-1];

	for (int i=k; i<=n; ++i) {
		dp[i] = dp[i-k]+a[i-1];
	}

	for (int i=n; i>=0; --i) {
		if (dp[i]<=p) {
			cout << i << '\n';
			return;
		}
	}
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