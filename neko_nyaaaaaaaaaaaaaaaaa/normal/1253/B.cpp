#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
 
	int n; cin >> n;
	vector<int> par;
	set<int> entered;
	set<int> inside;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x; cnt++;
		if (x < 0) {
			x *= -1;
			if (inside.find(x) == inside.end()) {
				cout << -1; exit(0);
			}
			inside.erase(inside.find(x));
			entered.insert(x);
		} else {
			if (entered.find(x) != entered.end()) {
				cout << -1; exit(0);
			}
			if (inside.find(x) != inside.end()) {
				cout << -1; exit(0);
			}
			inside.insert(x);
		}
		if (inside.empty()) {
			entered.clear();
			par.push_back(cnt);
			cnt = 0;
		}
	}
	if (cnt != 0) {
		cout << -1; exit(0);
	}
	cout << par.size() << '\n';
	for (int i: par) cout << i << ' ';
 
	return 0;
}