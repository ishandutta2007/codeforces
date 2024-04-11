#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<ar<int, 2>> ans;
	ans.reserve(500000);
	int n;
	cin >> n;
	int big = 31 - __builtin_clz(n);
	//cout << big << "\n";
	auto solve = [&](int l, int r) {
		assert(__builtin_popcount(r - l + 1) == 1); //power of 2
		assert(31 - __builtin_clz(r - l + 1) == big);
		for (int bit = 0; bit < big; ++bit) {
			for (int start = l; start < r; start += 1 << (bit + 1)) {
				for (int i = 0; i < (1 << bit); ++i) {
					int x = start + i;
					int y = start + i + (1 << bit);
					assert(y <= r);
					ans.push_back({x, y});
				}
			}
		}
	};
	solve(1, 1 << big);
	solve(n - (1 << big) + 1, n);
	cout << ans.size() << "\n";
	for (ar<int, 2> a : ans) {
		cout << a[0] << " " << a[1] << "\n";
	}
	return 0;
}