#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	string s; cin >> s;

	int sum = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			ans = max(ans + a[i], sum);
		}
		sum += a[i];
	}
	cout << ans << '\n';

	return 0;
}