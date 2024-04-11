#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> p(n + 1);
	for (int i = 1; i < n; i++) {
		cout << "? ";
		for (int j = 1; j <= n; j++) {
			if (j == n) {
				cout << n - i + 1 << endl;
			} else {
				cout << 1 << ' ';
			}
		}

		int k;
		cin >> k;
		if (k > 0) {
			p[n] = i;
			break;
		}
	}

	if (p[n] == 0) {
		p[n] = n;
	}

	for (int i = 1; i <= n; i++) {
		if (i == p[n]) {
			continue;
		}
		cout << "? ";
		for (int j = 1; j <= n; j++) {
			if (j == n) {
				cout << n - p[n] + 1 << endl;
			} else {
				cout << n - i + 1 << endl;
			}
		}
		cout << endl;

		int k;
		cin >> k;
		p[k] = i;
	}

	cout << "! ";
	for (int i = 1; i <= n; i++) {
		cout << p[i] << ' ';
	}
	cout << endl;
	return 0;
}