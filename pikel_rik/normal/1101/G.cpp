#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	partial_sum(a.begin(), a.end(), a.begin(), bit_xor<>());

	if (a.back() == 0) {
		return cout << "-1\n", 0;
	}

	vector<int> basis(30);

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < 30; j++) {
			if (a[i] >> j & 1) {
				if (basis[j]) {
					a[i] ^= basis[j];
				} else {
					basis[j] = a[i];
					break;
				}
			}
		}
	}
	cout << 30 - count(basis.begin(), basis.end(), 0) << '\n';
	return 0;
}