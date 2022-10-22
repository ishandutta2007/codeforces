#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

struct BIT {
	int n;
	vector<int> bit;
	BIT() {
		n = 100000;
		bit.resize(n + 1);
		for (int i = 0; i < n; ++i)
			upd(i, 1);
	}
	void upd(int i, int inc) {
		for (++i; i <= n; i += i & -i)
			bit[i] += inc;
	}
	int qry(int i) {
		int res = 0;
		for (++i; i > 0; i -= i & -i)
			res += bit[i];
		return res;
	}
	int qry(int l, int r) {
		return qry(r) - qry(l - 1);
	}
} b;

int n, a[100000];
set<int> oc[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i], --a[i];
		oc[a[i]].insert(i);
	}
	ll ans = 0;
	int last = -1;
	int cur = 0;
	for (int rep = 0; rep < n; ++rep) {
		while(oc[cur].empty()) ++cur;
		auto it = oc[cur].lower_bound(last);
		if (it != oc[cur].end()) {
			ans += b.qry(last + 1, *it);
			b.upd(*it, -1);
			last = *it;
			oc[cur].erase(it);
		}
		else {
			it = oc[cur].begin();
			ans += b.qry(last + 1, n - 1) + b.qry(0, *it);
			b.upd(*it, -1);
			last = *it;
			oc[cur].erase(it);
		}
	}
	cout << ans;
	return 0;
}