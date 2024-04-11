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

	int n;
	cin >> n;

	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	vector<int> diff(n);
	for (int i = 0; i < n; i++) {
		diff[i] = a[i] - b[i];
	}

	sort(diff.begin(), diff.end());

	ll ans = 0;

	for (int i = 0; i < n; i++) {
		int idx = upper_bound(diff.begin(), diff.end(), -diff[i]) - diff.begin();
		if (idx <= i) {
			ans += n - idx - 1;
		} else {
			ans += n - idx;
		}
	}
	cout << ans / 2 << '\n';
	return 0;
}