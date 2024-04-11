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
		ll x, y, k;
		cin >> x >> y >> k; //1 + (x - 1) * T >= k * (1 + y)
		ll ans = k;
		if (x == 2) ans += k * (y + 1) - 1;
		else ans += (k * (y + 1) - 1 + x - 2) / (x - 1);
		cout << ans << "\n";
	}

	return 0;
}