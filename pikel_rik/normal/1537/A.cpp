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

		if (sum == n) {
			cout << "0\n";
		} else if (sum < n) {
			cout << "1\n";
		} else {
			cout << sum - n << '\n';
		}
	}
	return 0;
}