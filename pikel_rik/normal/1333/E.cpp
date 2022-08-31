#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	if (n <= 2) {
		return cout << "-1\n", 0;
	}

	vector<vector<int>> grid(n, vector<int>(n));

	int next = 1;
	for (int lvl = n - 1; lvl > 2; lvl--) {
		if (lvl % 2 != 0) {
			for (int i = 0; i < n; i++) {
				for (int j = n - 1; j >= 0; j--) {
					if (max(i, j) == lvl) {
						grid[i][j] = next++;
					}
				}
			}
		} else {
			for (int i = n - 1; i >= 0; i--) {
				for (int j = 0; j < n; j++) {
					if (max(i, j) == lvl) {
						grid[i][j] = next++;
					}
				}
			}
		}
	}

	grid[0][0] = next++;
	grid[1][0] = next++;
	grid[1][2] = next++;
	grid[0][2] = next++;
	grid[2][0] = next++;
	grid[1][1] = next++;
	grid[2][1] = next++;
	grid[2][2] = next++;
	grid[0][1] = next++;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << grid[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}