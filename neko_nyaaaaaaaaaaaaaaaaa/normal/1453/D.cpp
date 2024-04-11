#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;

void solve() {
	int k; cin >> k;
	if (k % 2) {
		cout << "-1\n"; return;
	}

	vector<int> pw;
	int n = 1;
	while (1) {
		int p = 2, q = (1LL << n) - 1;
		int f = p*q;

		if (f > INF) break;
		pw.push_back(f);
		n++;
	}

	vector<int> ans;
	k -= 2;

	int petr = pw.size() - 1;
	while (k) {
		while (k < pw[petr]) petr--;
		k -= pw[petr];
		ans.push_back(petr); 
	}

	vector<int> op(1, 1);
	for (int i: ans) {
		while (i--) op.push_back(0);
		op.push_back(1);
	}
	cout << op.size() << '\n';
	for (int i: op) cout << i << ' '; cout << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}