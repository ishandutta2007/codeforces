#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long
#define ld long double

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int n, m; cin >> n >> m;
	int p = 1e6 + 3, mod = 1e7 + 7;
	cout << p << ' ' << p << '\n';
	for (int i = 1; i <= n - 2; ++i) {
		cout << i << ' ' << i + 1 << " 1\n";
	}
	cout << n - 1 << ' ' << n << ' ' << p - n + 2 << '\n';
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (cnt == m - n + 1) break;
		for (int j = i + 2; j <= n; ++j) {
			cout << i << ' ' << j << ' ' << mod << '\n';
			cnt++;
			if (cnt == m - n + 1) break;
		}
	}
	return 0;
}