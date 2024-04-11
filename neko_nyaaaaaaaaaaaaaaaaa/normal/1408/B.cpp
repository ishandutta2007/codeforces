#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		int prv = -1;
		vector<int> a;
		while (n--) {
			int x; cin >> x;
			if (x != prv) {
				prv = x;
				a.push_back(x);
			}
		}

		if (k == 1) {
			if (a.size() > 1) {
				cout << "-1\n";
			} else {
				cout << "1\n";
			}
		} else {
			a.erase(a.begin());
			
			k--;
			int s = a.size();

			cout << max(1, (s + k - 1)/k) << '\n';
		}
	}

	return 0;
}