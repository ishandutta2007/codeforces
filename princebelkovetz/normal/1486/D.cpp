#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(3);
	int n, k; cin >> n >> k;
	vector <int> a(n);
	for (auto& x : a) cin >> x;
	int l = 1, r = n + 1;
	while (l + 1 < r) {
		int m = l + r >> 1;
		vector <int> b(n);
		for (int i = 0; i < n; ++i)
			b[i] = (a[i] < m ? -1 : 1);
		vector <int> pref(n + 1), mpref(n + 1);
		int ok = 0;
		for (int i = 0; i < n; ++i) {
			pref[i + 1] = pref[i] + b[i];
			mpref[i + 1] = min(pref[i + 1], mpref[i]);
			if (i + 1 - k >= 0)
				ok = max(ok, pref[i + 1] - mpref[i + 1 - k]);
		}
		if (ok >= 1) l = m;
		else r = m;
	}
	cout << l << '\n';
	return 0;
}