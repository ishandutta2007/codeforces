#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> c(n);
		for (auto& item : c) cin >> item;

		int ans = INT_MAX;
		for (int col = 1; col <= 100; col++) {
			int cur = 0;
			for (int i = 0; i < n; i++) {
				if (c[i] != col) {
					cur++;
					i += k - 1;
				}
			}
			ans = min(ans, cur);
		}
		cout << ans << '\n';
	}
	return 0;
}