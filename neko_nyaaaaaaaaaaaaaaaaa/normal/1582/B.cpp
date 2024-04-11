#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n, o = 0, z = 0; cin >> n;
	while (n--) {
		int x; cin >> x;
		if (x == 1) o++;
		else if (x == 0) z++;
	}

 	cout << (1LL << z)*o << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}