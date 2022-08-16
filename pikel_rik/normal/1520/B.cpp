#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	vector<int> ordinary;
	for (int d = 1; d < 10; d++) {
		for (long long x = d; x <= 1000 * 1000 * 1000; x = 10 * x + d) {
			ordinary.push_back(x);
		}
	}

	while (t--) {
		int n;
		cin >> n;

		int c = 0;
		for (auto &x : ordinary) {
			c += x <= n;
		}
		cout << c << '\n';
	}
	return 0;
}