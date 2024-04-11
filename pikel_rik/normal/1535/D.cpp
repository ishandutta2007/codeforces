#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int k;
	cin >> k;

	string s;
	cin >> s;

	int n = (1 << k) - 1;

	reverse(s.begin(), s.end());
	for (auto &ch : s) {
		if (ch == '0') ch = '1';
		else if (ch == '1') ch = '0';
	}

	vector<int> t(4 * n);

	auto build = [&](int i, int l, int r, const auto &self) -> void {
		if (l == r) {
			t[i] = 1;
		} else {
			int mid = (l + r) >> 1;
			self((i << 1) + 1, l, mid, self);
			self((i << 1) + 2, mid + 1, r, self);
			if (s[i] == '0') {
				t[i] = t[(i << 1) + 1];
			} else if (s[i] == '1') {
				t[i] = t[(i << 1) + 2];
			} else {
				t[i] = t[(i << 1) + 1] + t[(i << 1) + 2];
			}
		}
	};

	build(0, 0, (1 << k) - 1, build);

	auto update = [&](int i, char c) -> void {
		s[i] = c;
		while (true) {
			if (s[i] == '0') {
				t[i] = t[(i << 1) + 1];
			} else if (s[i] == '1') {
				t[i] = t[(i << 1) + 2];
			} else {
				t[i] = t[(i << 1) + 1] + t[(i << 1) + 2];
			}
			if (i == 0) {
				break;
			}
			i = (i - 1) / 2;
		}
	};

	int q;
	cin >> q;

	while (q--) {
		int p; char c;
		cin >> p >> c, --p;

		p = n - 1 - p;
		if (c == '0') c = '1';
		else if (c == '1') c = '0';

		update(p, c);
		cout << t[0] << '\n';
	}
	return 0;
}