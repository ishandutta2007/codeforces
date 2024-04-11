#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

ll l, r;

void solve() {
	cin >> l >> r;
	ll ans = 0;
	for (int i=62; i>=0; --i) {
		ll x = l&(1ll<<i);
		ll y = r&(1ll<<i);
		if (x==y)
			ans += x;
		else {
			if (ans+(1ll<<(i+1))-1 <= r)
				ans += (1ll<<(i+1))-1;
			else ans += (1ll<<i)-1;
			break;
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}