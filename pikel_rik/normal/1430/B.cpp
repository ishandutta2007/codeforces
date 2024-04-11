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

		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		sort(a.rbegin(), a.rend());
		ll sum = 0;
		for (int i = 0; i < min(n, k + 1); i++) {
			sum += a[i];
		}
		cout << sum << '\n';
	}
	return 0;
}