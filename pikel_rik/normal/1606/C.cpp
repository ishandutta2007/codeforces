#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	vector<int> ten(10); ten[0] = 1;
	for (int i = 1; i < 10; i++) {
		ten[i] = 10 * ten[i - 1];
	}

	while (t--) {
		int n, k;
		cin >> n >> k, k += 1;

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		long long number = 0, taken = 0;
		for (int i = 1; i < n; i++) {
			long long taken_add = (ten[a[i]] - ten[a[i - 1]]) / ten[a[i - 1]];
			if (taken + taken_add > k) {
				taken_add = k - taken;
			}
			number += ten[a[i - 1]] * taken_add;
			taken += taken_add;
		}

		if (taken < k) {
			number += (k - taken) * ten[a.back()];
		}
		cout << number << '\n';
	}
	return 0;
}