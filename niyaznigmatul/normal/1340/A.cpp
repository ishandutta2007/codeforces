/**
 * Niyaz Nigmatullin
 */

#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		--p[i];
	}
	vector<int> r(n);
	for (int i = 0; i < n; i++) {
		r[p[i]] = i;
	}
	int right = n;
	for (int val = 0; val < n; ) {
		int pos = r[val];
		int nright = pos;
		while (pos < right) {
			if (p[pos] != val) {
				cout << "No\n";
				return;
			}
			pos++;
			val++;
		}
		right = nright;
	}
	cout << "Yes\n";
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}	
}