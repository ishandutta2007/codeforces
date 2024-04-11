#include <bits/stdc++.h>
using namespace std;

#define int long long 

void solve() {
	int n; cin >> n;
	int lo = 2, hi = 177013;
	while (lo < hi) {
		int mid = (lo + hi)/2;

		bool ok = 0;
		{
			// allocate double kekw
			int f1 = mid/2, f2 = mid-f1;
			if ((f1*f2)*2 >= n) ok = 1;
		}
		{
			// allocate triple
			int f1 = mid/3, f2 = f1, f3 = f1;
			if (mid % 3 == 1) f1++;
			if (mid % 3 == 2) f1++, f2++;

			if (((f1*f2) + (f2*f3) + (f3*f1))*2 >= n) ok = 1;
		}
		{
			// allocate triple ver 2 kekw
			int f1 = mid/3, f2 = f1, f3 = f1;
			if (mid % 3 == 1) f1++;
			if (mid % 3 == 2) f1 += 2;

			if (((f1*f2) + (f2*f3) + (f3*f1))*2 >= n) ok = 1;
		}

		if (ok) {
			hi = mid;
		} else {
			lo = mid+1;
		}
	}
	cout << lo << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}