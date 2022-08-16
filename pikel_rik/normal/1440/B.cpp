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
		int n, k;
		cin >> n >> k;

		vector<int> a(n * k);
		for (auto& item : a) cin >> item;

		int left = (n - 1) / 2, right = n - left - 1;
		ll ans = 0;
		for (int i = n * k - 1 - right, j = 0; j < k; i -= right + 1, j++) {
			ans += a[i];
		}
		cout << ans << '\n';
	}
	return 0;
}