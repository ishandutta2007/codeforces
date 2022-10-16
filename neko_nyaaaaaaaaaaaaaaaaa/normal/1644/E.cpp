#include <bits/stdc++.h>
using namespace std;

#define int long long

bool special_case(int n, string s) {
	set<char> st;
	for (char c: s) st.insert(c);
	if (st.size() == 1) {
		cout << n << '\n';
		return 1;
	} else {
		return 0;
	}
}

void solve() {
	int n; string s; cin >> n >> s;
	if (special_case(n, s)) return;
	
	int ans = n*n;
	int m = n;
	char cc = s[0];
	reverse(s.begin(), s.end());
	while (s.back() == cc) {
		s.pop_back(); m--;
		ans -= n-1;
	}
	
	int x = 1, y = 1;
	for (char c: s) {
		if (c == 'R') x++;
		else y++;
	}
	
	ans -= (x*y) - (s.size()+1);
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}