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

		long long sum = accumulate(a.begin(), a.end(), 0ll);
		long long m = sum % n;
		cout << m * (n - m) << '\n';
	}
	return 0;
}