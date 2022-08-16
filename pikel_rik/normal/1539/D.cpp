#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<long long> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

	vector<int> ind(n);
	iota(ind.begin(), ind.end(), 0);
	sort(ind.begin(), ind.end(), [&](int i, int j) {
		return b[i] < b[j];
	});

	long long sum = accumulate(a.begin(), a.end(), 0ll);

	long long lo = 0, hi = sum;

	while (lo < hi) {
		long long mid = lo + (hi - lo) / 2;

		long long cur_sum = sum, before_sum = 0;
		bool ok = true;

		for (int i = 0; i < n; i++) {
			cur_sum -= a[ind[i]];
			if (cur_sum >= mid && mid + before_sum >= b[ind[i]]) {
				before_sum += a[ind[i]];
			} else {
				if (mid < cur_sum + a[ind[i]]) {
					ok &= mid + before_sum >= b[ind[i]];
				}
				break;
			}
		}

		if (ok) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}

	cout << lo + sum << '\n';
	return 0;
}