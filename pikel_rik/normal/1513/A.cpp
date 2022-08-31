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

		vector<int> ans(n);
		iota(ans.begin(), ans.end(), 1);

		if (2 * k >= n) {
			cout << "-1\n";
		} else {
			for (int i = n - 2; i > 0 && k > 0; i -= 2) {
				swap(ans[i], ans[i + 1]);
				k -= 1;
			}
			for (auto &x : ans) cout << x << ' ';
			cout << '\n';
		}
	}
	return 0;
}