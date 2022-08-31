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

		vector<array<int, 5>> r(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> r[i][j];
			}
		}

		int ans = 0;
		for (int i = 1; i < n; i++) {
			int less_than = 0;
			for (int j = 0; j < 5; j++) {
				less_than += r[ans][j] < r[i][j];
			}
			if (less_than < 3) {
				ans = i;
			}
		}

		bool possible = true;
		for (int i = 0; i < n; i++) {
			int less_than = 0;
			for (int j = 0; j < 5; j++) {
				less_than += ans == i || r[ans][j] < r[i][j];
			}
			possible &= less_than >= 3;
		}

		cout << (!possible ? -1 : ans + 1) << '\n';
	}
	return 0;
}