#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	set<int> st;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (st.find(x) == st.end()) st.insert(x);
		else st.insert(-x);
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