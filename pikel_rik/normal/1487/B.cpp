#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k, --k;

		if (n % 2 == 0) {
			cout << 1 + k % n << '\n';
		} else {
			cout << 1 + (k + k / (n / 2)) % n << '\n';
		}
	}
	return 0;
}