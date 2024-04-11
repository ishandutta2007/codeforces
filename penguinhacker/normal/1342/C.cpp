#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

ll q, a, b, n, dp[40000];
ll l, r;

void solve() {
	cin >> a >> b >> q;
	n=a*b;
	dp[0]=0;
	for (int i=1; i<n; ++i) {
		dp[i]=dp[i-1]+(i%a%b!=i%b%a);
	}

	while(q--) {
		cin >> l >> r;
		ll k=(r-l+1)/n;
		ll ans=k*dp[n-1];
		r-=k*n;
		if (r<l) {
			cout << ans << ' ';
			continue;
		}
		l%=n;
		r%=n;
		ans+=dp[r];
		if (l) ans-=dp[l-1];
		if(r<l) ans+=dp[n-1];
		cout << ans << ' ';
	}
	cout << '\n';
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