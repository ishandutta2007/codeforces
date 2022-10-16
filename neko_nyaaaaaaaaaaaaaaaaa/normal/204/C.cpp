#pragma GCC optimize ("trapv")

#include <bits/stdc++.h>
using namespace std;

long double solve(vector<int> a, vector<int> b, long long q) {
	int n = a.size();
	long double ans = 0;
	long long cntb = 0;
	long long rdist = 0, ldist = 0;
	for (int i = 0; i < n; i++) {
		if (b[i]) {
			cntb++;
			rdist += i;
		}
	}

	long long rcnt = cntb, lcnt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i]) {
			long long l = i+1, r = n-i;
			long long res = 1LL*l*r*cntb;

			res -= rdist*l;
			res -= ldist*r;

			ans += 1.0*res/q;
		} 

		if (b[i]) {
			rcnt--;
			lcnt++;
		}
		rdist -= rcnt;
		ldist += lcnt;
	}

	return ans;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	string a, b; cin >> a >> b;
	for (int i = 0; i < n; i++) {
		a.push_back('A');
		b.push_back('A');
	}
	long long q = 0;
	for (int i = 1, j = n; i <= n; i++, j--) {
		q += 1LL*j*j;
	}
	long double ans = 0;
	for (char c = 'A'; c <= 'Z'; c++) {
		vector<int> x(n), y(n);
		for (int i = 0; i < n; i++) {
			x[i] = (a[i] == c);
			y[i] = (b[i] == c);
		}
		ans += solve(x, y, q);
	}
	cout << fixed << setprecision(12) << ans << '\n';

	return 0;
}