#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, a[100000], cnt[100000];

void solve() {
	cin >> n >> m;
	memset(cnt, 0, 4 * m);
	for (int i = 0; i < n; ++i)
		cin >> a[i], ++cnt[a[i] % m];
	int ans = cnt[0] > 0;
	if (m % 2 == 0) ans += cnt[m / 2] > 0;
	for (int i = 1; i < m - i; ++i) {
		int x = cnt[i], y = cnt[m - i];
		if (x == 0 && y == 0)
			continue;
		if (x > y)
			swap(x, y);
		if (y <= 2 * x)
			ans += max(1, y - x);
		else
			ans += y - x;
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}