#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> a(n), b(m);
	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;

	partial_sum(a.begin(), a.end(), a.begin());
	partial_sum(b.begin(), b.end(), b.begin());

	vector<int> divisors;
	for (int i = 1; i * i <= k; i++) {
		if (k % i == 0) {
			divisors.push_back(i);
			if (i * i != k) {
				divisors.push_back(k / i);
			}
		}
	}

	vector<int> cnt_a(divisors.size()), cnt_b(divisors.size());
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < int(divisors.size()); j++) {
			int d = divisors[j];
			if (i + 1 >= d && a[i] - (i + 1 == d ? 0 : a[i - d]) == d) {
				cnt_a[j] += 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < int(divisors.size()); j++) {
			int d = divisors[j];
			if (i + 1 >= d && b[i] - (i + 1 == d ? 0 : b[i - d]) == d) {
				cnt_b[j] += 1;
			}
		}
	}

	long long ans = 0;
	for (int i = 0; i < int(divisors.size()); i++) {
		int d = divisors[i];
		if (d * d < k) {
			ans += (long long)cnt_a[i] * cnt_b[i + 1];
		} else if (d * d == k) {
			ans += (long long)cnt_a[i] * cnt_b[i];
		} else {
			ans += (long long)cnt_a[i] * cnt_b[i - 1];
		}
	}
	cout << ans << '\n';
	return 0;
}