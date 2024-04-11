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

		if (a.front() != n && a.back() != n) {
			cout << "-1\n";
			continue;
		}

		reverse(a.begin(), a.end());
		for (auto &x : a) {
			cout << x << ' ';
		}
		cout << '\n';
	}
	return 0;
}