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

		bool possible = false;
		vector<int> v;
		auto recurse = [&](int i, int sum, int f, const auto &self) -> void {
			if (i == n) {
				possible |= f && sum == 0;
			} else {
				self(i + 1, sum, f, self);
				self(i + 1, sum - a[i], 1, self);
				self(i + 1, sum + a[i], 1, self);
			}
		};

		recurse(0, 0, 0, recurse);
		cout << (possible ? "YES" : "NO") << '\n';
	}

	return 0;
}