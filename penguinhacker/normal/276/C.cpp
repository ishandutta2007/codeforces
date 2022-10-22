#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>

ll n, q, a[200000], dp[200005]={0};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
	}
	sort(a, a+n, greater<ll> ());
	for (int i=0, l, r; i<q; ++i) {
		cin >> l >> r;
		dp[l]++;
		dp[r+1]--;
	}
	for (int i=1; i<=200001; ++i)
		dp[i] += dp[i-1];
	sort(dp, dp+200001, greater<ll> ());

	ll ans = 0;
	for (int i=0; i<n; ++i)
		ans += dp[i]*a[i];
	cout << ans;
	return 0;
}