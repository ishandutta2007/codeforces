#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		vector<int> ind(n);
		iota(ind.begin(), ind.end(), 0);
		sort(ind.begin(), ind.end(), [&](int i, int j) {
			return a[i] < a[j];
		});

		vector<long long> pref(n);
		for (int i = 0; i < n; i++) pref[i] = a[ind[i]];
		partial_sum(pref.begin(), pref.end(), pref.begin());

		vector<int> winners;

		for (int i = 0; i < n; i++) {
			bool not_winner = false;
			for (int j = i + 1; j < n;) {
				int lo = j, hi = n - 1;
				while (lo < hi) {
					int mid = lo + (hi - lo + 1) / 2;
					if (pref[mid] - pref[j - 1] <= pref[j - 1])
						lo = mid;
					else hi = mid - 1;
				}
				if (pref[lo] - pref[j - 1] > pref[j - 1]) {
					not_winner = true;
					break;
				}
				j = lo + 1;
			}
			if (!not_winner) {
				winners.push_back(ind[i]);
			}
		}

		sort(winners.begin(), winners.end());
		cout << winners.size() << '\n';
		for (auto winner : winners) cout << winner + 1 << ' '; cout << '\n';
	}
	return 0;
}