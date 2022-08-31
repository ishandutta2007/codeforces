#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;

	string s;
	cin >> s;

	vector<array<int, 26>> pref(n);
	for (int i = 0; i < n; i++) {
		if (i != 0) {
			pref[i] = pref[i - 1];
		}
		pref[i][s[i] - 'a'] += 1;
	}
	while (q--) {
		int l, r;
		cin >> l >> r;

		--l, --r;
		int ans = 0;
		for (int i = 0; i < 26; i++) {
			ans += (i + 1) * (pref[r][i] - (l != 0 ? pref[l - 1][i] : 0));
		}
		cout << ans << '\n';
	}
	return 0;
}