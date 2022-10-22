#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[200000];

void solve() {
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	ll ans=0;
	for (int i=0; i<n; i+=2) {
		ans+=a[i];
		a[i]*=-1;
	}
	ll best=0, sum=0;
	for (int r=1; r<=2; ++r) {
		sum=0;
		for (int i=r; i<n; i+=2) {
			ll x=a[i]+a[i-1];
			sum=max(sum+x, x);
			//cout << r << ' ' << sum << '\n';
			best=max(best, sum);
		}
	}
	cout << ans+best << '\n';
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

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/