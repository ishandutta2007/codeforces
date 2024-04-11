#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i] >> b[i];
		}

		long long sum_a = accumulate(a.begin(), a.end(), 0ll);
		long long sum_b = accumulate(b.begin(), b.end(), 0ll);

		long long target = sum_a - sum_b + (long long)n * m;

		vector<int> l(n), r(n);
		for (int i = 0; i < n; i++) {
			l[i] = max(0, m - b[i]);
			r[i] = m - max(0, m - a[i]);
			target -= 2 * l[i];
		}

		for (int i = 0; i < n; i++) {
			if (target > 0) {
				int take = min(target / 2, (long long)r[i] - l[i]);
				target -= 2 * take;
				l[i] += take;
			}
		}

		cout << abs(target) << '\n';
		for (int i = 0; i < n; i++) {
			cout << l[i] << ' ' << m - l[i] << '\n';
		}
	}
	return 0;
}