#include <bits/stdc++.h>
using namespace std;

bool try_solve(int n, vector<string> s, vector<int> p, int cnt) {
	int ans = 0;
	for (int i = 0, k = 0; i < n; i++, k = (k+1) % 3) {
		for (int j = 0; j < n; j++) {
			if ((j % 3) != p[k]) continue;
			if (s[i][j] == '.') continue;

			bool change = 0;
			if (i >= 2) {
				if (s[i-1][j] == 'X' && s[i-2][j] == 'X') {
					change = 1;
				}
			}
			if (i-1 >= 0 && i+1 < n) {
				if (s[i-1][j] == 'X' && s[i+1][j] == 'X') {
					change = 1;
				}
			}
			if (i+2 < n) {
				if (s[i+1][j] == 'X' && s[i+2][j] == 'X') {
					change = 1;
				}
			}
			if (j+2 < n) {
				if (s[i][j+1] == 'X' && s[i][j+2] == 'X') {
					change = 1;
				}
			}
			if (j-1 >= 0 && j+1 < n) {
				if (s[i][j-1] == 'X' && s[i][j+1] == 'X') {
					change = 1;
				}
			}
			if (j-2 >= 0) {
				if (s[i][j-1] == 'X' && s[i][j-2] == 'X') {
					change = 1;
				}
			}
			if (change) {
				ans++;
				s[i][j] = 'O';
			}
		}
	}

	if (ans <= cnt/3) {
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
		for (char c: s[i]) cnt += (c == 'X');
	}

	vector<int> p = {0, 1, 2};
	do {
		if (try_solve(n, s, p, cnt)) break;
	} while (next_permutation(p.begin(), p.end()));
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}