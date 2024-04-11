#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> a, int lval, int rval) {
	// lower all to <= rval
	for (int i = 1; i < a.size(); i++) {
		if (a[i] < a[i-1]) {
			lval -= abs(a[i] - a[i-1]);
			if (lval < 0) return 0;
		}
	}
	lval -= abs(rval - a.back());
	if (lval < 0) return 0;
	return 1;
}

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int l = -1, r = -1;
	int lval, rval;

	int prv = 1000000;
	for (int i = n-1; i >= 0; i--) {
		if (a[i] <= prv) {
			prv = a[i];
			a[i] = 0;
		} else {
			r = i;
			rval = prv;
			break;
		}
	}

	prv = 1000000;
	for (int i = 0; i < n; i++) {
		if (a[i] <= prv) {
			prv = a[i];
			a[i] = 0;
		} else {
			l = i;
			lval = prv;
			break;
		}
	}

	if (l == -1 || r == -1) {
		cout << "YES\n"; return;
	}

	// check if section l, r is monotonic, and everything <= lval + rval
	int lim = lval + rval;
	vector<int> s;
	for (int i = l; i <= r; i++) {
		s.push_back(a[i]);
		if (a[i] > lim) {
			cout << "NO\n"; return;
		}
	}

	// if it's a hill
	if (check(s, lval, rval)) cout << "YES\n";
	else cout << "NO\n";
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}