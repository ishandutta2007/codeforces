/**
 * Niyaz Nigmatullin
 */

#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = s[i] - '0';
	}
	bool found = false;
	for (int d = 1; d < 9; d++) {
		vector<int> g(n);
		int last = -1;
		int lastgot = -1;
		bool bad = false;
		for (int i = 0; i < n; i++) {
			if (a[i] < d) {
				if (a[i] < last) {
					bad = true;
					break;
				}
				last = a[i];
				g[i] = 1;
				lastgot = i;
			}
		}
		if (bad) continue;
		for (int i = lastgot + 1; i < n; i++) {
			if (a[i] == d) {
				g[i] = 1;
			}
		}
		last = -1;
		for (int i = 0; i < n; i++) {
			if (g[i] == 0) {
				if (a[i] < last) {
					bad = true;
					break;
				}
				last = a[i];
				g[i] = 2;
			}
		}
		if (bad) continue;
		found = true;
		for (int i = 0; i < n; i++) cout << g[i];
		cout << '\n';
		break;
	}
	if (!found) {
		cout << "-\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();	
}