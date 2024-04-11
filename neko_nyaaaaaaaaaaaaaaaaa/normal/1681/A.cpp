#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int &i: a) cin >> i;

	int m; cin >> m;
	vector<int> b(m);
	for (int &i: b) cin >> i;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	if (a.back() == b.back()) {
		cout << "Alice\nBob\n";
	} else if (a.back() > b.back()) {
		cout << "Alice\nAlice\n";
	} else {
		cout << "Bob\nBob\n";
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}