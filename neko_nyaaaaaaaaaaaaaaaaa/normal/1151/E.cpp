#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	long long n; cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	long long ans = a[n-1]*(n - a[n-1] + 1);

	for (int i = 0; i < n-1; i++) {
		if (a[i] == a[i+1]) continue;

		if (a[i] > a[i+1]) {
			ans += (a[i] - a[i+1])*(n - a[i] + 1);
		} else if (a[i] < a[i+1]) {
			ans += a[i]*(a[i+1] - a[i]);
		}
	}
	cout << ans;

	return 0;
}