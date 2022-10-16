#include <bits/stdc++.h>
using namespace std;

#define int long long

int solve(int n, int h, vector<int> a) {
	sort(a.begin(), a.end());
	int need = 0;
	for (int i = n-1; i >= 0; i -= 2) {
		need += a[i];
	}
	if (need > h) return 0;
	return 1;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, h; cin >> n >> h;
	vector<int> a;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		a.push_back(x);
		if (solve(i, h, a)) {
			ans = max(ans, i);
		} else {
			break;
		}
	}
	cout << ans;

	return 0;
}