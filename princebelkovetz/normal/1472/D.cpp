#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <iomanip>
#include <cassert>
#include <queue>
using namespace std;
#define int long long
#define debug(x) cout << #x << " is " << x << '\n';
const int mod = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		vector <int> a(n);
		for (auto& x : a) cin >> x;
		sort(a.rbegin(), a.rend());
		int s1 = 0, s2 = 0;
		for (int i = 0; i < n; ++i) {
			if (i & 1) s2 += a[i] * (a[i] & 1);
			else s1 += a[i] * (1 - (a[i] & 1));
		}
		cout << (s1 > s2 ? "Alice\n" : (s1 < s2 ? "Bob\n" : "Tie\n"));
	}
	return 0;
}