#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<int> a, b;
	int prv = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		a.push_back(x - prv); prv = x;
	}
	prv = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		b.push_back(x - prv); prv = x;
	}
	sort(a.begin()+1, a.end());
	sort(b.begin()+1, b.end());
	cout << (a == b ? "Yes\n" : "No\n");

	return 0;
}