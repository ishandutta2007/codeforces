#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<long long> a(n), b(n);
	for (long long &i: a) cin >> i;
	for (long long &i: b) cin >> i;

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	long long suma = 0, sumb = 0;
	for (long long &i: a) suma += i;
	for (long long &i: b) sumb += i;
	if (suma > sumb) {
		cout << "NO\n"; return;
	}

	vector<long long> pref(1);
	long long cur = 0;
	for (int ii = 0; ii < 2*n; ii++) {
		int i = ii % n;
		cur += b[i] - a[i];
		pref.push_back(cur);
	}

	multiset<long long> mf;
	for (int i = 0; i < n; i++) {
		mf.insert(pref[i]);
	}

	for (int i = n, j = 0; i < 2*n; i++, j++) {
		mf.erase(mf.begin());

		long long es = pref[i] - *mf.rbegin() + b[j];
		if (es < 0) {
			cout << "NO\n"; return;
		}

		mf.insert(pref[i]);
	}

	cout << "YES\n";
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
 
	int t; cin >> t;
	while (t--) solve();
 
	return 0;
}