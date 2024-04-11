#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n = 2, L, R;
vector<ar<int, 3>> ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> L >> R;
	while((1 << (n - 2)) < R - L + 1) ++n;
	if (__builtin_popcount(R - L + 1) == 1) {
		for (int i = 1; i <= n - 1; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				ans.push_back({i, j, max(1, (1 << i) >> 2)});
			}
		}
	}
	else {
		for (int i = 1; i <= n - 2; ++i) {
			for (int j = i + 1; j <= n - 1; ++j) {
				ans.push_back({i, j, max(1, (1 << i) >> 2)});
			}
		}
		ans.push_back({1, n, 1});
		int cur = 1;
		for (int i = n - 1; i > 1; --i) {
			if (cur + (1 << (i - 2)) <= R - L + 1) {
				ans.push_back({i, n, cur});
				cur += 1 << (i - 2);
			}
		}
	}
	if (L > 1) {
		++n;
		ans.push_back({n - 1, n, L - 1});
	}
	cout << "YES\n";
	cout << n << " " << ans.size() << "\n";
	for (ar<int, 3> a : ans) {
		cout << a[0] << " " << a[1] << " " << a[2] << "\n";
	}
	return 0;
}