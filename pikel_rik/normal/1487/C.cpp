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

		int c = (n - 1) / 2;
		vector<int> win(n), lose(n);
		for (int i = 0; i < n - 1; i++) {
			bool f = n % 2 == 0 && i % 2 == 0;
			if (f) {
				cout << 0 << ' ';
			}
			for (int j = i + 1 + f; j < n; j++) {
				if (win[i] < c && lose[j] != c) {
					cout << 1 << ' ';
					win[i] += 1, lose[j] += 1;
				} else if (lose[i] < c && win[j] != c) {
					cout << -1 << ' ';
					lose[i] += 1, win[j] += 1;
				}
			}
		}
		cout << '\n';
	}
	return 0;
}