#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<int> a(n+1), xr(n+1);
    for (int i = 1; i <= n; i++) {
		cin >> a[i];
		xr[i] = xr[i-1] ^ a[i];
    }
    map<int, int> o, e;
    for (int i = 0; i <= n; i++) {
		if (i % 2) o[xr[i]]++;
		else e[xr[i]]++;
    }

    int ans = 0;
    for (auto u: o) {
		int k = u.second;
		ans += (k*(k-1))/2;
    }
    for (auto u: e) {
		int k = u.second;
		ans += (k*(k-1))/2;
    }
    cout << ans;

 	return 0;
}