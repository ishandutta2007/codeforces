#include <bits/stdc++.h>
using namespace std;

void solve() {
	int r, c, k; cin >> r >> c >> k;
	vector<string> s(r);
	for (int i = 0; i < r; i++) {
		cin >> s[i];
	}

	int rice = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			rice += (s[i][j] == 'R');
		}
	}

	vector<int> gets;
	for (int i = 0; i < k; i++) {
		gets.push_back(rice/k);
	}
	for (int i = 0; i < k; i++) {
		rice -= gets[i];
	}
	for (int i = 0; i < k; i++) {
		if (rice > 0) {
			rice--;
			gets[i]++;
		}
	}

	vector<vector<int>> ans(r+1, vector<int>(c+1));
	int petr = 1;
	for (int i = 0; i < r; i++) {
		if (i % 2) {
			for (int j = 0; j < c; j++) {
				ans[i][j] = petr;
				if (s[i][j] == 'R') {
					gets.back()--;
				} 
				if (gets.back() == 0) {
					gets.pop_back();
					petr++;
				}
				if (petr > k) petr = k;
			}
		} else {
			for (int j = c-1; j >= 0; j--) {
				ans[i][j] = petr;
				if (s[i][j] == 'R') {
					gets.back()--;
				} 
				if (gets.back() == 0) {
					gets.pop_back();
					petr++;
				}
				if (petr > k) petr = k;
			}
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (ans[i][j] <= 10) {
				cout << (char)(ans[i][j] - 1 + '0');
			} else if (ans[i][j] > 10 && ans[i][j] <= 36) {
				cout << (char)(ans[i][j] - 11 + 'a');
			} else {
				cout << (char)(ans[i][j] - 37 + 'A'); 
			}
		}
		cout << '\n';
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