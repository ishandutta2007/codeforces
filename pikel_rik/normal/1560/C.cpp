#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	auto f = [&](int x) -> int {
		return x * x;
	};

	int t;
	cin >> t;

	while (t--) {
		int k;
		cin >> k;

		int distance = 1;
		while (k > f(distance)) {
			distance += 1;
		}

		int last = f(distance - 1);
		if (last + 1 <= k && k <= last + distance) {
			cout << k - last << ' ' << distance << '\n';
		} else {
			cout << distance << ' ' << f(distance) - k + 1 << '\n';
		}
	}
	return 0;
}