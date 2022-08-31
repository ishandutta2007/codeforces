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
		int n, m;
		cin >> n >> m;

		vector<vector<int>> a(n, vector<int>(m));

		int zero = 0, par = 0, sum = 0, mn = 101;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
				zero += a[i][j] == 0;
				par ^= (a[i][j] < 0);
				sum += abs(a[i][j]);
				mn = min(mn, abs(a[i][j]));
			}
		}

		if (zero || !par) {
			cout << sum << '\n';
		} else {
			cout << sum - 2 * mn << '\n';
		}
	}
	return 0;
}