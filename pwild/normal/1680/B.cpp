#include <bits/stdc++.h>
using namespace std;

void solve() {
	int m, n;
	cin >> m >> n;
	vector<string> a(m);
	for (string &s: a) cin >> s;

	int imin = m, jmin = n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 'R') {
				imin = min(imin, i);
				jmin = min(jmin, j);
			}
		}
	}

	cout << (a[imin][jmin] == 'R' ? "YES" : "NO") << '\n';
}

int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}