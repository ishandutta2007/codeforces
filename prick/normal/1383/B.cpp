#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define sz(x) ((int) (x).size())

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	int all = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		all ^= a[i];
	}
	if (all == 0) {
		cout << "DRAW\n";
		return;
	}
	int bit = 1 << 30;
	while (!(all & bit)) {
		bit >>= 1;
	}
	int ones = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] & bit) {
			++ones;
		}
	}
	bool A = (ones % 4 == 1);
	bool B = (n - ones) % 2 == 1;
	if (A || B) {
		cout << "WIN\n";
	} else {
		cout << "LOSE\n";
	}
}

signed main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}
}