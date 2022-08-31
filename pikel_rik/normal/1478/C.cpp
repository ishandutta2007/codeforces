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

		vector<long long> d(2 * n);
		for (auto &x : d) cin >> x;

		sort(d.begin(), d.end());

		bool ok = true;
		for (int i = 1; i < 2 * n; i += 2) {
			ok &= d[i] == d[i - 1];
			if (i + 1 < 2 * n) ok &= d[i] != d[i + 1];
		}

		if (!ok) {
			cout << "NO\n";
			continue;
		}

		vector<long long> a(n);

		int left = n + 1, right = n - 1;
		for (int i = 2 ; i < 2 * n; i += 2) {
			if ((d[i] - d[i - 1]) % (left - right) == 0) {
				a[i / 2] = (d[i] - d[i - 1]) / (left - right);
			} else {
				ok = false;
				break;
			}
			left += 1, right -= 1;
		}

		long long first = 0, sum = 0;
		for (int i = 0; i < n; i++) {
			sum += 2 * a[i];
			first += sum;
		}

		if (d[0] > first && (d[0] - first) % (2 * n) == 0) {

		} else {
			ok = false;
		}

		cout << (ok ? "YES" : "NO") << '\n';
	}
	return 0;
}