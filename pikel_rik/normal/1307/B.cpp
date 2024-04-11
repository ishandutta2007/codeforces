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
		int n, x;
		cin >> n >> x;

		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		sort(a.begin(), a.end());

		int ans;
		if (x % a[n - 1] == 0) {
			ans = x / a[n - 1];
		} else {
			ans = max(2, x / a[n - 1] + 1);
		}
		for (int i = 0; i < n; i++) {
			if (a[i] == x) {
				ans = 1;
				break;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}