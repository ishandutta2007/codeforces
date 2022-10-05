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
	vector<ll> t;
	fenwick() {}
	fenwick(int sz) {
		n = sz;
		t.resize(n + 1, 0);
		for (int i = 1; i <= n; i++)
			add(i, i);
	}
	void add(int x, ll v) {
		for (; x <= n; x += (x & -x)) t[x] += v;
	}
	ll query(int x) {
		ll rtn = 0;
		for (; x; x -= (x & -x)) rtn += t[x];
		return rtn;
	}
};

int n;
vector<ll> a;
vector<int> ans;
fenwick F;

int find(ll x) {
	int lo = 0, hi = n, mid;
	while (lo < hi) {
		mid = (lo + hi + 1) / 2;
		ll res = F.query(mid);
		if (res > x) hi = mid - 1;
		else lo = mid;
	}
	return lo;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	F = fenwick(n);
	a.resize(n);
	ans.resize(n);
	for (auto &i : a) cin >> i;
	reverse(a.begin(), a.end());
	int nxt = n - 1;
	for (auto &i : a) {
		int val = find(i);
		val++;
		ans[nxt--] = val;
		F.add(val, -val);
	}
	for (const auto &i : ans) cout << i << " "; cout << '\n';
}