#include <bits/stdc++.h>
using namespace std;
#define int long long

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	string s, t;
	for (cin >> tc; tc--; ) {
		cin >> s >> t;
		vector<int> pos[26];
		bool inv = 0;
		int cur = 0, op = 0;
		for (int i = 0; i < s.size(); i++) pos[s[i] - 'a'].push_back(i);
		for (int i = 0; i < t.size(); i++) {
			if (pos[t[i] - 'a'].size() == 0) {
				inv = 1;
				break;
			}
			bool c = 1;
			if (i) {
				// extend t[i - 1] to t[i]
				auto it = upper_bound(pos[t[i] - 'a'].begin(), pos[t[i] - 'a'].end(), cur);
				//cout << "TRY EXTEND\n";
				if (it != pos[t[i] - 'a'].end()) {
					//cout << "FIND\n";
					c = 0;
					cur = *it;
				}
			}
			if (c) {
				cur = pos[t[i] - 'a'][0];
				op++;
			}
		}
		cout << (inv ? -1 : op) << '\n';
	}
}