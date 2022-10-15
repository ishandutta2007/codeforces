#include <bits/stdc++.h>

/**
 * Author: Niyaz Nigmatullin
 */

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &e : a) {
		cin >> e;
	}
	if (a[0] + a[1] > a[n - 1]) {
		cout << "-1\n";
	} else {
		cout << "1 2 " << n << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) solve();
}