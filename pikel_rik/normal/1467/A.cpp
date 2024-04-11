#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		if (n == 1) {
			cout << "9\n";
			continue;
		}

		cout << 9 << 8;

		int cur = 8;
		for (int i = 2; i < n; i++) {
			cur = (cur + 1) % 10;
			cout << cur;
		}
		cout << '\n';
	}
	return 0;
}