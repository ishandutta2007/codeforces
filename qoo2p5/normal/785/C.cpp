#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9 + 123;

#define sz(x) (int) (x).size()

void run();

signed main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#endif
	run();
	return 0;
}

ll n, m;

void run() {
	cin >> n >> m;
	ll ans = n;
	if (m < n) {
		ll left = -1;
		ll right = (ll) 2e9 + 123;
		
		while (right - left > 1) {
			ll mid = (left + right) / 2;
			if (n - (mid - 1) * mid / 2 - (mid + m) <= 0) {
				right = mid;
			} else {
				left = mid;
			}
		}
		
		ans = min(ans, m + right);
	}
	
	cout << ans << endl;
}