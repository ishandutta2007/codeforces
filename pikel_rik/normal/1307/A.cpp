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
		int n, d;
		cin >> n >> d;

		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		int ans = a[0];
		for (int i = 1; i < n; i++) {
			if (i * a[i] <= d) {
				ans += a[i];
				d -= i * a[i];
			} else {
				ans += (d / i);
				break;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}