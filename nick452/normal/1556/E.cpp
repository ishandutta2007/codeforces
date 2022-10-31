#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Data
{
	ll s = 0;
	ll min_s = 0;
	ll max_s = 0;
};

int n;
vector<ll> vals;
vector<Data> tree;

Data f(Data a, Data b) {
	Data c;
	c.s = a.s + b.s;
	c.min_s = min(a.min_s, a.s + b.min_s);
	c.max_s = max(a.max_s, a.s + b.max_s);
	return c;
}
void init(int id, int s, int t) {
	if (s == t) {
		tree[id].s = vals[s];
		tree[id].min_s = min(0LL, vals[s]);
		tree[id].max_s = max(0LL, vals[s]);
		return;
	}
	int m = (s + t) / 2;
	init(id * 2 + 1, s, m);
	init(id * 2 + 2, m + 1, t);
	tree[id] = f(tree[id * 2 + 1], tree[id * 2 + 2]);
}

void up(int id, int s, int t, int l, int r, Data& d) {
	if (s >= l && t <= r) {
		d = f(d, tree[id]);
		return;
	}
	if (s > r || t < l) {
		return;
	}
	int m = (s + t) / 2;
	up(id * 2 + 1, s, m, l, r, d);
	up(id * 2 + 2, m + 1, t, l, r, d);
}


int main()
{
#ifdef _MSC_VER
	freopen("e.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int m;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	vals = vector<ll>(n);
	for (int i = 0; i < n; ++i) {
		vals[i] = b[i] - a[i];
	}
	tree = vector<Data>(n * 4);
	init(0, 0, n - 1);
	for (int i = 0; i < m; ++i) {
		int l, r;
		cin >> l >> r;
		--l;
		--r;
		Data d;
		up(0, 0, n - 1, l, r, d);
		ll ret = ((d.s == 0 && d.min_s >= 0) ? d.max_s : -1);
		printf("%lld\n", ret);
	}
	return 0;
}