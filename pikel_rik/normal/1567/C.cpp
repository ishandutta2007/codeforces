#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	array<array<array<int, 10>, 10>, 10> a;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				a[i][j][k] = 0;
			}
		}
	}
	for (int d1 = 0; d1 < 10; d1++) {
		for (int d2 = 0; d2 < 10; d2++) {
			for (int carry = 0; carry < 10; carry++) {
				int first = (d1 + d2 + carry) % 10;
				int second = (d1 + d2 + carry) / 10;
				a[first][second][carry] += 1;
			}
		}
	}

	while (t--) {
		int n;
		cin >> n;

		string s = to_string(n);
		reverse(s.begin(), s.end());
		s.push_back('0'), s.push_back('0');

		vector<int> carry(s.size());

		long long ans = 0, prod = 1;
		auto recurse = [&](int i, const auto &self) -> void {
			if (i == s.size()) {
				ans += prod;
			} else {
				for (int j = 0; j < 3; j++) {
					int ways = a[s[i] - '0'][j][carry[i]];
					if (ways > 0) {
						if (j > 0) {
							if (i + 2 < s.size()) {
								carry[i + 2] += j;
							} else {
								continue;
							}
						}
						prod *= ways;
						self(i + 1, self);
						prod /= ways;
						if (j > 0) {
							carry[i + 2] -= j;
						}
					}
				}
			}
		};

		recurse(0, recurse);
		cout << ans - 2 << '\n';
	}
	return 0;
}