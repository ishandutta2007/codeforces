#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

struct fenwick {
	int n;
	vector<int> t, a;
	fenwick() {}
	fenwick(int sz) {
		n = sz;
		t.resize(n + 1, 0);
		a.resize(n + 1, 0);
	}
	void set(int x) {
		if (a[x]) return;
		a[x] = 1;
		for (x++; x <= n; x += (x & -x)) t[x]++;
	}
	int query(int x) {
		int rtn = 0;
		for (x++; x; x -= (x & -x)) rtn += t[x];
		return rtn;
	}
	int query(int l, int r) {
		if (l > r) return 0;
		return query(r) - query(l - 1);
	}
};

int n;
vector<pair<int, int>> a;
fenwick F;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i.first >> i.second;
	vector<int> comp;
	
	comp.clear();
	for (auto &i : a) comp.push_back(i.first);
	sort(comp.begin(), comp.end());
	comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
	for (auto &i : a) i.first = lower_bound(comp.begin(), comp.end(), i.first) - comp.begin();
	comp.clear();
	for (auto &i : a) comp.push_back(i.second);
	sort(comp.begin(), comp.end());
	comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
	for (auto &i : a) i.second = lower_bound(comp.begin(), comp.end(), i.second) - comp.begin();
	
	
	sort(a.begin(), a.end(), [](pair<int, int> aa, pair<int, int> bb) {
		if (aa.second != bb.second) return aa.second > bb.second;
		return aa.first > bb.first;
	});
	
	ll ans = 0;
	F = fenwick(n);
	for (int i = 0; i < n; i++) {
		int l, r = n - 1;
		if (i == n - 1 || a[i].second != a[i + 1].second) l = 0;
		else {
			l = 1 + a[i + 1].first;
		}
		F.set(a[i].first);
		ll s1 = F.query(l, a[i].first);
		ll s2 = F.query(a[i].first, r);
		ans += s1 * s2;
	}
	finish(ans);
}