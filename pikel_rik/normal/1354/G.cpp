#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		bool rock = true;
		for (int rep = 0; rep < 30; rep++) {
			int j = 2 + rng() % (n - 1);

			cout << "? " << 1 << ' ' << 1 << endl;
			cout << 1 << endl << j << endl;

			string answer;
			cin >> answer;
			if (answer == "SECOND") {
				rock = false;
				break;
			}
		}

		if (!rock) {
			cout << "! " << 1 << endl;
			continue;
		}

		int critical_len = -1;
		for (int len = 1; 2 * len <= n; len *= 2) {
			cout << "? " << len << ' ' << len << endl;
			for (int i = 1; i <= len; i++) {
				cout << i << ' ';
			}
			cout << endl;
			for (int i = len + 1; i <= 2 * len; i++) {
				cout << i << ' ';
			}
			cout << endl;

			string answer;
			cin >> answer;
			if (answer != "EQUAL") {
				critical_len = len;
				break;
			}
		}

		int lo, hi;
		if (critical_len == -1) {
			lo = (1 << __lg(n)) + 1;
			hi = n;
		} else {
			lo = critical_len + 1;
			hi = 2 * critical_len;
		}

		while (lo < hi) {
			int mid = lo + (hi - lo) / 2;

			int len = mid - lo + 1;
			cout << "? " << len << ' ' << len << endl;
			for (int i = 1; i <= len; i++) {
				cout << i << ' ';
			}
			cout << endl;
			for (int i = 1; i <= len; i++) {
				cout << lo + i - 1 << ' ';
			}
			cout << endl;

			string answer;
			cin >> answer;
			if (answer == "EQUAL") {
				lo = mid + 1;
			} else {
				hi = mid;
			}
		}

		cout << "! " << lo << endl;
	}
	return 0;
}