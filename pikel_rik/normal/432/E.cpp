#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<string> a(n + 1, string(m + 1, 0));

	a[0] = string(m + 1, 0);
	for (int i = 0; i < n; i++) {
		a[i][0] = 0;
	}

	vector<tuple<char, char, char>> moves;
	for (char c1 = 'A'; c1 <= 'Z'; c1++) {
		moves.emplace_back(c1, 0, c1);
		for (char c2 = c1 + 1; c2 <= 'Z'; c2++) {
			for (char c3 = c2 + 1; c3 <= 'Z'; c3++) {
				vector<char> p = {c1, c2, c3};
				do {
					moves.emplace_back(p[0], p[1], p[2]);
				} while (next_permutation(p.begin(), p.end()));
			}
		}
	}

	sort(moves.begin(), moves.end(), [&](const auto &x, const auto &y) {
		if (get<0>(x) != get<0>(y))
			return get<0>(x) < get<0>(y);
		if (get<2>(x) != get<2>(y))
			return get<2>(x) < get<2>(y);
		return get<1>(x) < get<1>(y);
	});

	auto check_full = [&](int i, int j, int side, char c) -> bool {
		bool ok = true;
		for (int ii = 0; ii < side; ii++) {
			ok &= a[i + ii][j - 1] != c;
			ok &= a[i - 1][j + ii] != c;
		}
		return ok;
	};

	auto fill_full = [&](int i, int j, int side, char c) -> void {
		for (int ii = i; ii < i + side; ii++) {
			for (int jj = j; jj < j + side; jj++) {
				a[ii][jj] = c;
			}
		}
	};

	auto check_half = [&](int i, int j, int side, char c1, char c2, char c3) -> bool {
		bool ok = a[i - 1][j] != c1;
		for (int ii = 0; ii < side; ii++) {
			ok &= a[i + ii][j - 1] != (ii % 2 == 0 ? c1 : c2);
			ok &= a[i - 1][j + 1 + ii] != c3;
		}
		return ok;
	};

	auto fill_half = [&](int i, int j, int side, char c1, char c2, char c3) {
		for (int ii = 0; ii < side; ii++) {
			a[i + ii][j] = (ii % 2 == 0 ? c1 : c2);
		}
		for (int ii = i; ii < i + side; ii++) {
			for (int jj = j + 1; jj < j + 1 + side; jj++) {
				a[ii][jj] = c3;
			}
		}
	};

	auto recurse = [&](int i, int j, const auto &self) -> void {
		int side = min(n - i + 1, m - j + 1);

		if (side == 1) {
			for (char c = 'A'; c <= 'C'; c++) {
				if (a[i - 1][j] != c && a[i][j - 1] != c) {
					a[i][j] = c;
					break;
				}
			}
			if (n - i + 1 < m - j + 1)
				self(i, j + side, self);
			else if (m - j + 1 < n - i + 1)
				self(i + side, j, self);
		} else {
			for (auto &[c1, c2, c3] : moves) {
				if (c2 == 0 && check_full(i, j, side, c1)) {
					fill_full(i, j, side, c1);
					if (n - i + 1 < m - j + 1)
						self(i, j + side, self);
					else if (m - j + 1 < n - i + 1)
						self(i + side, j, self);
					break;
				} else if (c2 != 0) {
					if (n - i + 1 < m - j + 1 && check_half(i, j, side, c1, c2, c3)) {
						fill_half(i, j, side, c1, c2, c3);
						if (j + 1 + side <= m)
							self(i, j + 1 + side, self);
						break;
					} else if (n - i + 1 >= m - j + 1 && check_half(i, j, side - 1, c1, c2, c3)) {
						fill_half(i, j, side - 1, c1, c2, c3);
						if (i + side - 1 <= n)
							self(i + side - 1, j, self);
						break;
					}
				}
			}
		}
	};

	recurse(1, 1, recurse);
	for (int i = 1; i <= n; i++) {
		a[i].erase(a[i].begin());
		cout << a[i] << '\n';
	}
	return 0;
}