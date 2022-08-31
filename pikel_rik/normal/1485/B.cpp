#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q, k;
	cin >> n >> q >> k;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	while (q--) {
		int l, r;
		cin >> l >> r;
		--l, --r;

		int gap = 2 * (k - (r - l + 1));
		gap -= k - a[r];
		gap -= a[l] - 1;
		cout << gap << '\n';
	}
	return 0;
}