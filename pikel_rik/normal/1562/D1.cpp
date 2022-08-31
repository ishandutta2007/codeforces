#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, q;
		cin >> n >> q;

		string s;
		cin >> s;

		for (int i = 1; i < n; i += 2) {
			s[i] = '+' ^ '-' ^ s[i];
		}

		vector<int> pref(n);
		for (int i = 0; i < n; i++) {
			pref[i] = (s[i] == '+' ? 1 : -1);
		}

		partial_sum(pref.begin(), pref.end(), pref.begin());

		while (q--) {
			int l, r;
			cin >> l >> r, --l, --r;

			int sum = abs(pref[r] - (l == 0 ? 0 : pref[l - 1]));
			if (sum == 0) {
				cout << 0 << '\n';
			} else if (sum % 2 != 0) {
				cout << 1 << '\n';
			} else {
				cout << 2 << '\n';
			}
		}
	}
	return 0;
}