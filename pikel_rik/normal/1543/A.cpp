#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		long long a, b;
		cin >> a >> b;

		long long diff = abs(a - b);
		if (diff == 0) {
			cout << 0 << ' ' << 0 << '\n';
		} else {
			cout << diff << ' ';
			long long moves = (diff - a % diff) % diff;
			if (a - a % diff >= 0 && b - a % diff >= 0) {
				moves = min(moves, a % diff);
			}
			cout << moves << '\n';
		}
	}
	return 0;
}