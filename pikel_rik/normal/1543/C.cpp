#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed << setprecision(12);

	int t;
	cin >> t;

	while (t--) {
		long double C, M, P, v;
		cin >> C >> M >> P >> v;

		long double ans = 0;

		auto recurse = [&](long double c, long double m, long double p, int moves, long double prob, const auto &self) -> void {
			ans += (moves + 1) * prob * p;
			for (int rot = 0; rot < 2; rot++) {
				if (c > 1e-9) {
					if (c - v > 1e-9) {
						if (m > 1e-9) {
							self(c - v, m + v / 2, p + v / 2, moves + 1, prob * c, self);
						} else {
							self(c - v, m, p + v, moves + 1, prob * c, self);
						}
					} else {
						if (m > 1e-9) {
							self(0, m + c / 2, p + c / 2, moves + 1, prob * c, self);
						} else {
							self(0, m, p + c, moves + 1, prob * c, self);
						}
					}
				}
				swap(c, m);
			}
		};

		recurse(C, M, P, 0, 1, recurse);
		cout << ans << '\n';
	}
	return 0;
}