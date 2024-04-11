#include <bits/stdc++.h>
using namespace std;

bool try_solve(int n, vector<string> s, int x, int o, int cnt) {
	int flip = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i+j) % 3 == x && s[i][j] == 'O') {
				s[i][j] = 'X'; flip++;
			} 
			if ((i+j) % 3 == o && s[i][j] == 'X') {
				s[i][j] = 'O'; flip++;
			} 
		}
	}
	if (flip <= cnt/3) {
		for (string str: s) cout << str << '\n';
		return 1;
	}
	return 0;
}

void solve() {
	int n, cnt = 0; cin >> n;
	vector<string> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (char c: s[i]) {
			cnt += (c != '.');
		}
	}

	for (int x = 0; x < 3; x++) {
		for (int o = 0; o < 3; o++) {
			if (x != o && try_solve(n, s, x, o, cnt)) return;
		}
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}