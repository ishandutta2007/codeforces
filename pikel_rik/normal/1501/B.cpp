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

		vector<int> pref(n);
		for (int i = 0, x; i < n; i++) {
			cin >> x;
			if (x > 0) {
				pref[i] += 1;
				if (i - x >= 0) {
					pref[i - x] -= 1;
				}
			}
		}

		partial_sum(pref.rbegin(), pref.rend(), pref.rbegin());
		for (int i = 0; i < n; i++) {
			cout << !!pref[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}