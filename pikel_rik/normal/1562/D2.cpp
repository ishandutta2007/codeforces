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

		vector<vector<int>> pos(2 * n + 1);
		for (int i = 0; i < n; i++) {
			pos[n + pref[i]].push_back(i);
		}

		while (q--) {
			int l, r;
			cin >> l >> r, --l, --r;

			int sum = pref[r] - (l == 0 ? 0 : pref[l - 1]);
			if (sum == 0) {
				cout << 0 << '\n';
			} else if (sum % 2 != 0) {
				cout << 1 << '\n';
			} else {
				cout << 2 << '\n';
			}

			if (sum % 2 != 0) {
				//want to find an i such that [l, i] has sum = ceil(sum / 2), [i, r] has sum = ceil(sum / 2)
				//pref[i] - pref[l] == ceil(sum / 2)
				//pref[i] = pref[l] + ceil(sum / 2);
				int target = (sum < 0 ? (sum - 1) / 2 : (sum + 1) / 2) + (l == 0 ? 0 : pref[l - 1]);
				auto it = lower_bound(pos[n + target].begin(), pos[n + target].end(), l);
				cout << *it + 1 << '\n';
			} else if (sum != 0) {
				//want to find an i such that [l, i] has sum = sum / 2, [i + 1, r] has sum = sum / 2
				int target = sum / 2 + (l == 0 ? 0 : pref[l - 1]);
				auto it1 = lower_bound(pos[n +  target].begin(), pos[n + target].end(), l);
				target = sum + (l == 0 ? 0 : pref[l - 1]);
				auto it2 = lower_bound(pos[n + target].begin(), pos[n + target].end(), l);
				cout << *it1 + 1 << ' ' << *it2 + 1 << '\n';
			}
		}
	}
	return 0;
}