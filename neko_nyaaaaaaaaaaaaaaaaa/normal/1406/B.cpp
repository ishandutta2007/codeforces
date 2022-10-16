#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		int C; cin >> C;
		vector<long long> pos, neg;

		long long ans = -1e18;
		while (C--) {
			int x; cin >> x;
			if (x < 0) neg.push_back(x);
			else if (x > 0) pos.push_back(x);
			else ans = 0;
		}

		sort(pos.begin(), pos.end());
		sort(neg.begin(), neg.end(), greater<long long>());

		if (pos.size() + neg.size() < 5) {
			cout << ans << '\n'; continue;
		}

		for (int pc = 0; pc <= 5; pc++) {
			int nc = 5 - pc;

			if (pc > pos.size() || nc > neg.size()) continue;

			if (nc % 2) {
				// negative, take smallest abs
				long long prod = 1;
				for (int i = 0; i < pc; i++) {
					prod *= pos[i];
				}
				for (int i = 0; i < nc; i++) {
					prod *= neg[i];
				}
				ans = max(ans, prod);
			} else {
				// positive, take biggest abs
				reverse(pos.begin(), pos.end());
				reverse(neg.begin(), neg.end());

				long long prod = 1;
				for (int i = 0; i < pc; i++) {
					prod *= pos[i];
				}
				for (int i = 0; i < nc; i++) {
					prod *= neg[i];
				}
				ans = max(ans, prod);

				reverse(pos.begin(), pos.end());
				reverse(neg.begin(), neg.end());
			}
		}

		cout << ans << '\n';
	}

	return 0;
}