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

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		auto check = [&](void) -> bool {
			array<long long, 2> sum = {0};
			bool possible = true;
			for (int i = 0; i < n; i++) {
				sum[i & 1] += a[i];
				possible &= sum[i & 1] >= sum[(i + 1) & 1];
			}
			possible &= sum[0] == sum[1];
			return possible;
		};

		array<long long, 2> sum = {0};
		vector<long long> arr(n);
		for (int i = 0; i < n; i++) {
			sum[i & 1] += a[i];
			arr[i] = sum[i & 1];
		}

		vector<long long> diff(n); diff[0] = arr[0];
		for (int i = 1; i < n; i++) {
			diff[i] = arr[i] - arr[i - 1];
		}

		if (sum[0] == sum[1]) {
			cout << (check() ? "YES" : "NO") << '\n';
		} else {
			bool possible = false;
			swap(a[0], a[1]);
			possible |= check();
			swap(a[0], a[1]);
			swap(a[n - 2], a[n - 1]);
			possible |= check();
			swap(a[n - 2], a[n - 1]);

			vector<long long> suf(n);
			suf[n - 1] = diff[n - 1], suf[n - 2] = diff[n - 2];
			for (int i = n - 3; i >= 0; i--) {
				suf[i] = min(diff[i], suf[i + 2]);
			}

			bool f = true;
			for (int i = 2; i < n - 1; i++) {
				f &= diff[i - 2] >= 0;
				int d = a[i] - a[i - 1];
				if (sum[i & 1] - d == sum[(i + 1) & 1] + d) {
					possible |= f && suf[i] - 2 * d >= 0 && suf[i + 1] + 2 * d >= 0 && diff[i - 1] + d >= 0;
				}
			}

			cout << (possible ? "YES" : "NO") << '\n';
		}
	}
	return 0;
}