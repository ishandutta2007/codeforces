#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int s, n, k; cin >> s >> n >> k;
	if (s < k) {
		cout << "NO\n";
		return;
	}
	if (s == k) {
		cout << "YES\n";
		return;
	}
	
	if (n < k) {
		cout << "NO\n";
		return;
	}

	int full_slot = max(1LL, n/k);
	int one_slot = n - full_slot;

	if (s >= full_slot*(k+1) + one_slot) {
		cout << "NO\n";
		return;
	}

	cout << "YES\n";
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve(); 
	}

	return 0;
}