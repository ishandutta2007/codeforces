#include <bits/stdc++.h>
using namespace std;

void solve() {
	int a, b;
	cin >> a >> b;

	int res = b-a;
	for (int k = 0; k < res; k++) {
		// a += k, then a |= b, then b += ?
		res = min(res, k + 1 + ((a+k)|b)-b);
		// b += k, then a |= b, then b += ?
		res = min(res, k + 1 + (a|(b+k))-b-k);
	}
	cout << res << '\n';
}

int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}