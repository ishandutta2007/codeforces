#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
	ll n, q;
	cin >> n >> q;
	while (q--) {
		ll x, y;
		cin >> x >> y;
		
		ll ans1 = 0;
		if ((x+y) % 2) {
			ans1 += (n*n+1)/2;
		}
		
		ll col = (x+1)/2 - 1;
		
		ll ans2 = 0;
		if (x % 2) {
			if ((x+y) % 2 == 0) {
				ans2 = n*col + (y+1)/2;
			} else {
				ans2 = n*col + (y/2);
			}
		} else {
			if ((x+y) % 2 == 0) {
				ans2 = n*col + (n+1)/2 + y/2;
			} else {
				ans2 = n*col + (n/2) + (y+1)/2;
			}
		}
		
		cout << ans1 + ans2 << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	while (t--) {
		solve();
	}
	
	return 0;
}