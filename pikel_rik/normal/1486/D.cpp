#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	auto f = [&](int x) -> bool {
		vector<int> mn(n + 1);
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += (a[i - 1] < x ? -1 : 1);
			if (i >= k && mn[i - k] < sum) {
				return true;
			}
			mn[i] = min(sum, mn[i - 1]);
		}
		return false;
	};

	int lo = 1, hi = n;
	while (lo < hi) {
		int mid = lo + (hi - lo + 1) / 2;
		if (f(mid))
			lo = mid;
		else hi = mid - 1;
	}
	cout << lo << '\n';
	return 0;
}