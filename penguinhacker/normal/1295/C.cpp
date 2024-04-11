#include <bits/stdc++.h>
using namespace std;

string s, t;

void solve() {
	cin >> s >> t;
	bool has[26] = {0};
	set<int> occ[26];
	for (int i=0; i<s.size(); ++i) {
		has[s[i]-'a'] = 1;
		occ[s[i]-'a'].insert(i);
	}
	for (char c:t) {
		if (!has[c-'a']) {
			cout << -1 << '\n';
			return;
		}
	}
	int ans = 1, curr=0;
	for (int i=0; i<t.size(); ++i) {
		auto it = occ[t[i]-'a'].lower_bound(curr);
		if (it == occ[t[i]-'a'].end()) {
			curr = *occ[t[i]-'a'].lower_bound(0)+1;
			ans++;
		}
		else {
			curr = *it+1;
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while(T--)
		solve();
	return 0;
}