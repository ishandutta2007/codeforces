#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		bool zero = 0;
		vector<int> a, b;
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			if (x == 0) {
				zero = 1;
			}
			else if (x > 0) {
				a.push_back(x);
			}
			else {
				assert(x < 0);
				b.push_back(-x);
			}
		}
		sort(a.rbegin(), a.rend());
		sort(b.rbegin(), b.rend());
		ll best = -2e18;
		for (int i = 5; i > 0; i -= 2) {
			if (a.size() < i || b.size() < 5 - i) {
				continue;
			}
			ll cur = 1;
			for (int j = 0; j < i; ++j) {
				cur *= a[j];
			}
			for (int j = 0; j < 5 - i; ++j) {
				cur *= b[j];
			}
			best = max(best, cur);
		}
		if (best < 0) {
			if (zero) {
				best = 0;
			}
			/*else {
				assert(b.size() >= 5);
				sort(b.begin(), b.end());
				best = 1;
				for (int i = 0; i < 5; ++i) {
					best *= -b[i];
				}
			}*/
			vector<int> c(n);
			merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
			sort(c.begin(), c.end());
			best = 1;
			for (int i = 0; i < 5; ++i) {
				best *= -c[i];
			}
		}
		cout << best << "\n";
	}
	return 0;
}