#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;
		sort(s.begin(), s.end());
		cout << s << '\n';
	}

	return 0;
}