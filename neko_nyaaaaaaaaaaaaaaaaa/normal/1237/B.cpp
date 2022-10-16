#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	vector<int> exit_time(n+1);
	for (int i = 0; i < n; i++) {
		exit_time[b[i]] = i;
	}

	int ans = 0;

	int cur = -1;
	for (int i = 0; i < n; i++) {
		if (exit_time[a[i]] < cur) ans++;
		else cur = exit_time[a[i]];
	}
	cout << ans;

	return 0;
}