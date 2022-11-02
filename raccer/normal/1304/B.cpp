#include <bits/stdc++.h>
using namespace std;

map <string, int> all;

int main () {
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		all[s]++;
	}
	string mid = "", ans = "";
	for (auto it : all) {
		string s = it.first, t = s; reverse(t.begin(), t.end());
		if (s > t) continue;
		if (s == t) {
			while (it.second >= 2) it.second -= 2, ans += s;
			if (it.second) mid = s;
		} else {
			int tmp = min(all[s], all[t]);
			while (tmp--) ans += s;
		}
	}
	cout << ans.size() * 2 + mid.size() << endl;
	cout << ans << mid; reverse(ans.begin(), ans.end()); cout << ans << endl;
	return 0;
}