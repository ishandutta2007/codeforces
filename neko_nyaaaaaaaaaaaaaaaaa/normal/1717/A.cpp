#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int ans = n;
		ans += (n/2)*2;
		ans += (n/3)*2;
		cout << ans << '\n';
	}

	return 0;
}