#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	using ll = long long;

	int t;
	cin >> t;

	while (t--) {
		ll a, b, c;
		cin >> a >> b >> c;

		if ((a + b + c) % 9 == 0 && (a + b + c) / 9 <= min({a, b, c})) {
			cout << "YES\n";
		} else cout << "NO\n";
	}
	return 0;
}