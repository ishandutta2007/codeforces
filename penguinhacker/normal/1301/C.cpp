#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		ll n, m;
		cin >> n >> m;
		ll ans = n * (n + 1) / 2;
		ll z = n - m;
		ll x = z / (m + 1);
		ans -= x * (x + 1) / 2 * (m + 1) + (x + 1) * (z % (m + 1));
		cout << ans << "\n";
	}
	return 0;
}