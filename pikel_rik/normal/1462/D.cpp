#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		vector<int> pref(a.begin(), a.end());
		for (int i = 1; i < n; i++) {
			pref[i] += pref[i - 1];
		}

		int mn_ops = INT_MAX;
		for (int sum : pref) {
			int cur = 0, ops = -1;
			for (int i = 0; i < n; i++) {
				cur += a[i];
				ops += 1;
				if (cur == sum) {
					cur = 0;
					if (i + 1 != n) {
						ops -= 1;
					}
				} else if (cur > sum) {
					break;
				}
			}
			if (cur == 0) {
				mn_ops = min(mn_ops, ops);
			}
		}
		cout << mn_ops << '\n';
	}
	return 0;
}