#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 1e9 + 7, N = 1e5 + 2;


signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector <int> a(n);
	for (auto& x : a) cin >> x;

	int ans = 0;

	for (int i = 0; i < n; i += 2) {
		int cur = 0, mn = -1;
		for (int j = i + 1; j < n; j += 2) {
			int l = -mn, r = min(a[i], a[j] - cur);
			ans += max(0ll, r - l + 1);
			cur -= a[j];
			mn = min(mn, cur);
			if (j + 1 < n) cur += a[j + 1];
		}
	}

	cout << ans << '\n';

	return 0;
}