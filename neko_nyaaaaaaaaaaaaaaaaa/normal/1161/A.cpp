#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, k; cin >> n >> k;
	int ans = 3*n - 2;

	vector<int> a(n+3);
	vector<int> v(k+3);
	vector<int> fi(n+3), la(n+3);
	for (int i = 1; i <= k; i++) {
		cin >> v[i];
		a[v[i]]++;
		if (fi[v[i]] == 0) {
			fi[v[i]] = i;
		}
		la[v[i]] = i;
	}

	for (int i = 1; i <= n; i++) {
		if (a[i]) {
			ans--;
			if (a[i-1] != 0 && fi[i-1] < la[i]) ans--;
			if (a[i+1] != 0 && fi[i+1] < la[i]) ans--;
		}
	}
	cout << ans;
	
	return 0;
}