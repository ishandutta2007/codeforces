#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> ans;
		for (int i = 1; i <= n; i++) {
			if (i != k && 2 * i >= k) {
				ans.push_back(i);
			}
		}
		cout << ans.size() << '\n';
		for (int i : ans) cout << i << ' '; cout << '\n';
	}
	return 0;
}