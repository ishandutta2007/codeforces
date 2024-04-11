#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, k, a[mxN];
ll p[mxN+1];

ll C2(ll x) {
	return x*(x-1)/2;
}

void solve() {
	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		p[i+1]=p[i]+a[i];
	}
	ll ans=0;
	if (k<=n) {
		for (int i=0; i+k-1<n; ++i)
			ans=max(ans, p[i+k]-p[i]);
		cout << ans+C2(k) << "\n";
	} else {
		cout << p[n]+(ll)k*n-C2(n+1) << "\n";
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