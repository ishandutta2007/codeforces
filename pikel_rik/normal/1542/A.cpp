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

		vector<int> a(2 * n);
		for (auto &x : a) cin >> x;

		int c = count_if(a.begin(), a.end(), [&](int x) { return x % 2; });
		cout << (c == n ? "Yes" : "No") << '\n';
	}
	return 0;
}