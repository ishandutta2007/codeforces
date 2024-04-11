#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int l, r;
		cin >> l >> r;

		int mod = max(l, r / 2 + 1);
		cout << r % mod << '\n';
	}
	return 0;
}