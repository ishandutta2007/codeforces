#include <bits/stdc++.h>
using namespace std;

#define int long long

int ask(int i) {
	cout << "? " << i << endl;
	int qi; cin >> qi;
	if (qi == 0) exit(1);
	return qi;
}

void answer(vector<int> p) {
	cout << "!";
	for (int i = 1; i < p.size(); i++) {
		cout << ' ' << p[i];
	}
	cout << endl;
}

void solve() {
	int n; cin >> n;
	vector<int> p(n+1, -1);

	for (int i = 1; i <= n; i++) {
		if (p[i] != -1) continue;

		int cur = ask(i);
		vector<int> cf(1, cur);
		while (1) {
			cur = ask(i);
			cf.push_back(cur);
			if (cur == cf[0]) break;
		}

		for (int j = 1; j < cf.size(); j++) {
			p[cf[j-1]] = cf[j];
		}
	}
	answer(p);
}

signed main() {
	//ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}