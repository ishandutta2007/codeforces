#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> mask(n);
	for (int i = 0, j = 0; i < n && j < (1 << 13); j++) {
		if (__builtin_popcount(j) == 6) {
			mask[i++] = j;
		}
	}

	vector<long long> query(13);
	for (int i = 0; i < 13; i++) {
		vector<int> indices;
		for (int j = 0; j < n; j++) {
			if (mask[j] >> i & 1) {
				indices.push_back(j);
			}
		}
		if (!indices.empty()) {
			cout << "? " << (int) indices.size() << ' ';
			for (int j : indices) cout << j + 1 << ' ';
			cout << endl;

			cin >> query[i];
		}
	}

	cout << "! ";
	for (int i = 0; i < n; i++) {
		long long ans = 0;
		for (int j = 0; j < 13; j++) {
			if (!(mask[i] >> j & 1)) {
				ans |= query[j];
			}
		}
		cout << ans << ' ';
	}
	cout << endl;
	return 0;
}