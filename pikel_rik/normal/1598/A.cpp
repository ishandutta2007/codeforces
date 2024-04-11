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

		array<string, 2> grid;
		for (auto &row : grid) cin >> row;

		bool possible = true;
		for (int i = 0; i < n; i++) {
			possible &= grid[0][i] != '1' || grid[1][i] != '1';
		}

		cout << (possible ? "YES" : "NO") << '\n';
	}
	return 0;
}