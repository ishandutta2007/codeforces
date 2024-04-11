#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> x(n), y(n);
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

	array<array<int, 4>, 4> pts = {};

	for (int i = 0; i < n; i++) {
		pts[x[i] % 4][y[i] % 4] += 1;
	}

	vector<pair<int, int>> types = {{0, 0}, {0, 2}, {2, 0}, {2, 2}};

	auto no_of_pts = [&](auto i, auto j) -> int {
		if (i == j) {
			return 0;
		} else {
			return 2;
		}
	};

	long long ans = 0;
	for (auto i : types) {
		int ci = pts[i.first][i.second];
		for (auto j : types) {
			if (i > j) {
				continue;
			}
			int cj = pts[j.first][j.second];
			for (auto k : types) {
				if (j > k) {
					continue;
				}
				int ck = pts[k.first][k.second];
				int parity = (no_of_pts(i, j) + no_of_pts(j, k) + no_of_pts(i, k)) % 4;
				if (parity == 0) {
					long long now = (long long)ci * (cj - (i == j)) * (ck - (i == k) - (j == k));
					if (i == j && j == k) {
						now /= 6;
					} else if (i == j || j == k) {
						now /= 2;
					}
					ans += now;
				}
			}
		}
	}

	cout << ans << '\n';
	return 0;
}