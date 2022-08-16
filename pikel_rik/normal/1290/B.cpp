#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	int n = s.length();

	vector<array<int, 26>> pref(n);
	pref[0][s[0] - 'a'] = 1;

	for (int i = 1; i < n; i++) {
		pref[i] = pref[i - 1];
		pref[i][s[i] - 'a'] += 1;
	}

	auto sum = [&](int l, int r, int c) -> int {
		return pref[r][c] - (l == 0 ? 0 : pref[l - 1][c]);
	};

	int q;
	cin >> q;

	while (q--) {
		int l, r;
		cin >> l >> r, --l, --r;

		if (l == r || s[l] != s[r]) {
			cout << "Yes\n";
		} else {
			int distinct = 0;
			for (int k = 0; k < 26; k++) {
				distinct += sum(l, r, k) > 0;
			}
			cout << (distinct <= 2 ? "No" : "Yes") << '\n';
		}
	}
	return 0;
}