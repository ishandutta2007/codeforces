#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	int lo = 1e9+10, hi = 0;
	int clo = 0, chi = 0, cboth = 0;
	while (n--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a < lo) lo = a, clo = cboth = 2e9;
		if (b > hi) hi = b, chi = cboth = 2e9;
		if (lo == a) clo = min(clo, c);
		if (hi == b) chi = min(chi, c);
		if (lo == a && hi == b) cboth = min(cboth, c);
		cout << min(cboth, clo+chi) << '\n';
	}
}

int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}