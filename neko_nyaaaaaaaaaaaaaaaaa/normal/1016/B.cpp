#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, m, q;
	string s, t;
	cin >> n >> m >> q >> s >> t;
	
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		bool flag = 1;
		for (int j = 0; j < m; j++) {
			if (t[j] != s[j+i]) {flag = 0; break;}
		}
		
		if (flag) {ans.push_back(i+1);}
	}
	
	while (q--) {
		int l, r;
		cin >> l >> r;
		r = (r - m + 1);
		
		if (r < l) {cout << 0 << '\n';}
		else
		cout << (upper_bound(ans.begin(), ans.end(), r) - lower_bound(ans.begin(), ans.end(), l)) << '\n';
	}
	
	return 0;
}