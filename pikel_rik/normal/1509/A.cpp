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

		for (auto &x : a) if (x % 2 == 0) cout << x << ' ';
		for (auto &x : a) if (x % 2 != 0) cout << x << ' ';
		cout << '\n';
	}
	return 0;
}