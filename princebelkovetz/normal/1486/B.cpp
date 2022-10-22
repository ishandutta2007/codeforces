#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <cassert>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long
const int mod = 1e9 + 7;
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	while (tt --> 0) {
		int n; cin >> n;
		vector <int> xs(n), ys(n);
		for (int i = 0; i < n; ++i)
			cin >> xs[i] >> ys[i];
		sort(xs.begin(), xs.end());
		sort(ys.begin(), ys.end());
		cout << (n & 1 == 1 ? 1 : (xs[n / 2] - xs[n / 2 - 1] + 1) * (ys[n / 2] - ys[n / 2 - 1] + 1)) << '\n';
	}
	return 0;
}