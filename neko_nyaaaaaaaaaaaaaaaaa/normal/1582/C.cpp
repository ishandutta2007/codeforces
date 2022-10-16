#include <bits/stdc++.h>
using namespace std;

#define int long long

int try_solve(string s, char c) {
	int ans = 0;
	int i = 0, j = s.size() - 1;
	while (i < j) {
		if (s[i] == s[j]) {
			i++, j--; continue;
		} else {
			if (s[i] == c) {
				ans++; i++;
			} else if (s[j] == c) {
				ans++; j--;
			} else {
				return s.size()+1;
			}
		}
	}
	return ans;
}

void solve() {
	int n; cin >> n;
	string s; cin >> s;

	int ans = n+1;
	for (char c = 'a'; c <= 'z'; c++) {
		ans = min(ans, try_solve(s, c));
	}

	if (ans > n) {
		cout << "-1\n";
	} else {
		cout << ans << '\n';
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