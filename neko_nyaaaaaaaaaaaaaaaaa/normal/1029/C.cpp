#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	vector<int> l(n), r(n);
	multiset<int> a, b;
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
		a.insert(l[i]); b.insert(r[i]);
	}
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		a.erase(a.find(l[i]));
		b.erase(b.find(r[i]));
		ans = max(ans, *b.begin() - *a.rbegin());
		a.insert(l[i]); b.insert(r[i]);
	}
	cout << ans;
	
	return 0;
}