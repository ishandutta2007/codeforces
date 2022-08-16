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

		int zeroes = count(a.begin(), a.end(), 0);
		int ones = count(a.begin(), a.end(), 1);

		cout << ones * (1ll << zeroes) << '\n';
	}
	return 0;
}