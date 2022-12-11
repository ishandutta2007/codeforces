#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
	int n;
	cin >> n;
	set<int> d;
	bool ok = true;
	for (int r = 0; r < n; ++r) {
		int x;
		cin >> x;
		int val = (r + x) % n;
		if (val < 0) val += n;
		
		if (d.count(val)) {
			ok = false;
		}
		d.insert(val);
	}
	if (ok) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		solve();
	}
}