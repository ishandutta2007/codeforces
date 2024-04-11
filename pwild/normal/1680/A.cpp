#include <bits/stdc++.h>
using namespace std;

void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	if (max(a,c) <= min(b,d)) {
		cout << max(a,c) << '\n';
	} else {
		cout << a+c << '\n';
	}
}

int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}