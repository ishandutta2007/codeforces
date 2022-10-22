#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int M=1e9+7;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		ll ans=n, l=1;
		for (int i=1; l<=n; ++i) {
			l=l*i/__gcd(l, (ll)i);
			ans=(ans+n/l)%M;
		}
		cout << ans << "\n";
	}
	return 0;
}