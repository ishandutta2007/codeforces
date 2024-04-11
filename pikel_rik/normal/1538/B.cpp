#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		int sum = accumulate(a.begin(), a.end(), 0);
		if (sum % n != 0) {
			cout << "-1\n";
			continue;
		}

		int target = sum / n;
		int ans = 0;

		for (auto &x : a) {
			ans += x > target;
		}
		cout << ans << '\n';
	}
	return 0;
}