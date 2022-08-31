#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n, n += 2;

		vector<int> b(n);
		for (auto &x : b) cin >> x;

		sort(b.begin(), b.end());

		bool ok = false;
		for (int i : {n - 2, n - 1}) {
			long long sum = accumulate(b.begin(), b.end(), 0ll) - b[i];
			int k = -1;
			for (int j = 0; j < n; j++) {
				if (j != i && b[j] == sum - b[i]) {
					k = j;
					break;
				}
			}
			if (k != -1) {
				ok = true;
				for (int j = 0; j < n; j++) {
					if (j != k && j != i) {
						cout << b[j] << ' ';
					}
				}
				cout << '\n';
				break;
			}
		}

		if (!ok) {
			cout << "-1\n";
		}
	}
	return 0;
}