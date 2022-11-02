#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int res = (int)sqrt(n) + (int)cbrt(n);
		int l = -1, r = cbrt(n)+1;
		while (r - l > 1) {
			int mid = (l + r) / 2;
			if (mid * mid * mid * mid * mid * mid <= n) l = mid;
			else r = mid;
		}
		cout << res - l << endl;
	}
}