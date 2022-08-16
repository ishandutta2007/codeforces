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

		if (n == 2) {
			cout << "-1\n";
		} else {
			int next = 1;
			vector<vector<int>> a(n, vector<int>(n));
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if ((i + j) % 2 == 0) {
						a[i][j] = next++;
					}
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if ((i + j) % 2 != 0) {
						a[i][j] = next++;
					}
					cout << a[i][j] << ' ';
				}
				cout << '\n';
			}
		}
	}
	return 0;
}