#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; long long k, x;
	cin >> n >> k >> x;

	vector<long long> a(n);
	for (auto &y : a) cin >> y;

	sort(a.begin(), a.end());

	int ans = 1;
	vector<long long> diffs;

	for (int i = 1; i < n; i++) {
		if (a[i] - a[i - 1] > x) {
			diffs.push_back((a[i] - a[i - 1] - 1) / x);
			ans += 1;
		}
	}

	sort(diffs.begin(), diffs.end());

	for (auto &diff : diffs) {
		if (diff <= k) {
			ans -= 1;
			k -= diff;
		}
	}
	cout << ans << '\n';
	return 0;
}