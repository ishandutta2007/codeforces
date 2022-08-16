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

		vector<array<bool, 5>> okay(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> okay[i][j];
			}
		}

		bool possible = false;
		for (int day1 = 0; day1 < 5; day1++) {
			for (int day2 = day1 + 1; day2 < 5; day2++) {
				int c1 = 0, c2 = 0, c12 = 0;
				for (int i = 0; i < n; i++) {
					if (okay[i][day1] && okay[i][day2]) {
						c12 += 1;
					} else if (okay[i][day1]) {
						c1 += 1;
					} else if (okay[i][day2]) {
						c2 += 1;
					} else {
						c1 = -1, c2 = -1, c12 = -1;
						break;
					}
				}
				possible |= c1 + c12 >= n / 2 && c2 + c12 >= n / 2;
			}
		}
		cout << (possible ? "YES" : "NO") << '\n';
	}
	return 0;
}