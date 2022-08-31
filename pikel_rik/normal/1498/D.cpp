#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	auto ceil = [&](long long x) -> long long {
		int rem = x % 100000;
		if (rem == 0)
			return x;
		return x + 100000 - rem;
	};

	int n, m;
	cin >> n >> m;

	vector<int> t(n), y(n);
	vector<long long> xx(n);

	for (int i = 0; i < n; i++) {
		cin >> t[i] >> xx[i] >> y[i];
	}

	vector<int> lvl(m + 1, -1);
	lvl[0] = 0;

	for (int i = 0; i < n; i++) {
		auto transform = [&](long long x) -> long long {
			if (t[i] == 1) {
				return ceil(x + xx[i]);
			} else {
				return ceil(x / 100000 * xx[i]);
			}
		};
		for (int j = m; j >= 0; j--) {
			if (lvl[j] == -1) {
				continue;
			}
			long long k = transform(100000ll * j);
			for (int iter = 0; iter < y[i] && k / 100000 <= m && lvl[k / 100000] == -1; iter++) {
				lvl[k / 100000] = i + 1;
				k = transform(k);
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		cout << lvl[i] << ' ';
	}
	cout << '\n';
	return 0;
}