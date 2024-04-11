#include <bits/stdc++.h>
using namespace std;

bool solve() {
	int m, n;
	cin >> m >> n;
	vector<string> a(m);
	for (string &s: a) cin >> s;

	for (int i = 0; i+1 < m; i++) {
		for (int j = 0; j+1 < n; j++) {
			int count = (a[i][j]-'0') + (a[i][j+1]-'0') + (a[i+1][j]-'0') + (a[i+1][j+1]-'0');
			if (count == 3) return false;
		}
	}
	return true;
}

int main() {
	int tc; cin >> tc;
	while (tc--) {
		cout << (solve() ? "YES" : "NO") << '\n';
	}
}