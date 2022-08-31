#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		long long p, a, b, c;
		cin >> p >> a >> b >> c;

		long long ans = min({
			(a - p % a) % a,
			(b - p % b) % b,
			(c - p % c) % c
		});
		cout << ans << '\n';
	}
	return 0;
}