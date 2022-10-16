#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, k; cin >> n >> k;
	vector<int> ab, a, b;
	for (int i = 0; i < n; i++) {
		int x, y, z; cin >> x >> y >> z;
		if (y && z) ab.push_back(x);
		else if (y) a.push_back(x);
		else if (z) b.push_back(x);
	}

	sort(ab.begin(), ab.end());
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int ans = 1e18;

	int absum = 0;
	int asum = accumulate(a.begin(), a.end(), 0LL);
	int bsum = accumulate(b.begin(), b.end(), 0LL);

	int need = k;
	while (a.size() > need) {
		asum -= a.back(); a.pop_back();
	}
	while (b.size() > need) {
		bsum -= b.back(); b.pop_back();
	}
	if (a.size() == need && b.size() == need) {
		ans = min(ans, asum+bsum);
	}

	for (int i = 0; i < min((int)ab.size(), k); i++) {
		need--;
		absum += ab[i];
		while (a.size() > need) {
			asum -= a.back(); a.pop_back();
		}
		while (b.size() > need) {
			bsum -= b.back(); b.pop_back();
		}

		if (a.size() == need && b.size() == need) {
			ans = min(ans, absum+asum+bsum);
		}
	}

	if (ans == 1e18) {
		cout << "-1\n";
	} else {
		cout << ans << '\n';
	}

	return 0;
}