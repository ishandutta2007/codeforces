#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long
const int mod = 1e9;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q, k; cin >> n >> q >> k;
	vector <int> a(n);
	for (auto& x : a) cin >> x;
	vector <int> p1(n + 1), p2(n + 1);
	for (int i = 0; i < n; ++i) {
		if (i)
			p1[i + 1] = p1[i] + a[i] - a[i - 1] - 1;
		if (i != n - 1)
			p2[i + 1] = p2[i] + a[i + 1] - a[i] - 1;
	}
	while (q --> 0) {
		int l, r; cin >> l >> r;
		int ans = 0;
		ans += p1[r] - p1[l];
		ans += p2[r - 1] - p2[l - 1];
		ans += (k - a[r - 1]) + a[l - 1] - 1;
		cout << ans << '\n';
	}
	return 0;
}