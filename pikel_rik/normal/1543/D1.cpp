#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				cout << 0 << endl;
			} else {
				cout << ((i - 1) ^ i) << endl;
			}
			int r;
			cin >> r;
			if (r == 1) {
				break;
			}
		}
	}
	return 0;
}