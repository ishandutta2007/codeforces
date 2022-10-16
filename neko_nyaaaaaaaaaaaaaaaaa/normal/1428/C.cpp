#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s; cin >> s;
	stack<char> st;
	for (char c: s) {
		if (c == 'A') {
			st.push(c);
		} else {
			if (st.empty()) st.push(c);
			else st.pop();
		}
	}
	cout << st.size() << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}