#include <bits/stdc++.h>

using namespace std;

bool solve() {
	long long n, m, k;
	cin >> n >> m >> k;
	vector<long long> a(k);
	long long sum = 0;
	for (int i = 0; i < k; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a.begin(), a.end(), greater<int>());
	if (sum < n * m) return false;
	auto check = [&](long long n, long long m) {
		long long full = n;
		bool shift = false;
		for (int i = 0; i < k; ++i) if (a[i] / m > 1) {
			if (a[i] / m > 2) {
				shift = true;
			}
			if (full >= 2) {
				full -= min(full, a[i] / m);
			}
			else if (full == 1) {
				if (!shift) return false;
				full -= min(full, a[i] / m);
			}
		}
		return full == 0;
	};
	return check(n, m) || check(m, n);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		cout << (solve() ? "Yes" : "No") << '\n';
	}
}