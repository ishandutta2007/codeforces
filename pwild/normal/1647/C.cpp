#include <bits/stdc++.h>
using namespace std;

void solve() {
	int m, n;
	cin >> m >> n;
	vector<string> a(m);
	for (string &s: a) cin >> s;

	if (a[0][0] == '1') {
		cout << -1 << '\n';
		return;
	}

	cout << m*n-1 << '\n';
	for (int i = m-1; i >= 0; i--) {
		for (int j = n-1; j >= 0; j--) {
			if (i == 0 && j == 0) break;
			if (a[i][j] == '0') {
				cout << i+1 << ' ' << j+1 << ' ' << i+1 << ' ' << j+1 << '\n';
			} else if (i > 0) {
				cout << i << ' ' << j+1 << ' ' << i+1 << ' ' << j+1 << '\n';
			} else if (j > 0) {
				cout << i+1 << ' ' << j << ' ' << i+1 << ' ' << j+1 << '\n';
			} else {
				assert(0);
			}
		}
	}

}

int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}