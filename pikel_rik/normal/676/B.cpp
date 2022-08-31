#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, t;
	cin >> n >> t;

	vector<vector<int>> v(n, vector<int>(n));

	for (int iter = 0; iter < t; iter++) {
		v[0][0] += (1 << 20);
		for (int i = 0; i + 1 < n; i++) {
			for (int j = 0; j <= i; j++) {
				if (v[i][j] > (1 << 20)) {
					int remaining = v[i][j] - (1 << 20);
					v[i][j] = (1 << 20);
					v[i + 1][j] += remaining / 2;
					v[i + 1][j + 1] += remaining / 2;
				}
			}
		}
		for (int j = 0; j < n; j++) {
			if (v[n - 1][j] > (1 << 20)) {
				v[n - 1][j] = (1 << 20);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			ans += v[i][j] == (1 << 20);
		}
	}
	cout << ans << '\n';
	return 0;
}