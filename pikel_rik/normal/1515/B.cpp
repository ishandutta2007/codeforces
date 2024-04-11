#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	auto is_square = [&](int x) -> bool {
		int sq = round(sqrt(x));
		return sq * sq == x;
	};

	while (t--) {
		int n;
		cin >> n;

		bool possible = false;
		for (int x = 2; x <= n && n % x == 0; x *= 2) {
			possible |= is_square(n / x);
		}
		cout << (possible ? "YES" : "NO") << '\n';
	}
	return 0;
}