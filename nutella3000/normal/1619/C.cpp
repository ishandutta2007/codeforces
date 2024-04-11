#include<bits/stdc++.h>
using namespace std;

#define int long long
#define size(a) (int)a.size()
#define pb emplace_back

void run() {
	string a, s; cin >> a >> s;
	int id = size(s)-1;
	bool bad = false;
	vector<int> b;
	for (int i = size(a) - 1; i >= 0; --i) {
		if (id < 0) { cout << -1 << endl; return; }
		if (s[id] >= a[i]) b.pb(s[id] - a[i]);
		else {
			if (id == 0 || s[id-1] != '1') {
				cout << -1 << endl; return;
			}
			b.pb(s[id]+10-a[i]); --id;
		}
		--id;
	}
	while (id >= 0) b.pb(s[id--]-'0');
	while (size(b) >= 2 && b.back() == 0) b.pop_back();
	for (int i = size(b) - 1; i >= 0; --i)
		cout << b[i];
	cout << endl;
}

signed main() {
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		run();
	}
}