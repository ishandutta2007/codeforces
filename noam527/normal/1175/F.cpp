#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

struct segtree {
	int n;
	vector<pair<int, int>> t;
	vector<int> tag;
	segtree() {}
	segtree(int sz) {
		n = max(2, sz);
		while (n != (n & -n)) n += (n & -n);
		t.resize(2 * n);
		tag.resize(2 * n, 0);
		for (int i = 0; i < n; i++)
			t[i + n - 1] = { i, 1 };
		for (int i = n - 2; i >= 0; i--)
			fix(i);
	}
	void push(int x) {
		if (!tag[x]) return;
		t[x].first += tag[x];
		if (x < n - 1) {
			tag[x + x + 1] += tag[x];
			tag[x + x + 2] += tag[x];
		}
		tag[x] = 0;
	}
	void fix(int x) {
		push(x + x + 1);
		push(x + x + 2);
		if (t[x + x + 1].first < t[x + x + 2].first)
			t[x] = t[x + x + 1];
		else if (t[x + x + 1].first > t[x + x + 2].first)
			t[x] = t[x + x + 2];
		else {
			t[x] = t[x + x + 1];
			t[x].second += t[x + x + 2].second;
		}
	}
	void add(int l, int r, int v) {
		add(l, r, v, 0, 0, n - 1);
	}
	void add(int l, int r, int v, int node, int nl, int nr) {
		if (r < nl || nr < l) return;
		if (l <= nl && nr <= r) {
			tag[node] += v;
			return;
		}
		push(node);
		int mid = (nl + nr) / 2;
		add(l, r, v, 2 * node + 1, nl, mid);
		add(l, r, v, 2 * node + 2, mid + 1, nr);
		fix(node);
	}
	pair<int, int> query(int l, int r) {
		return query(l, r, 0, 0, n - 1);
	}
	pair<int, int> query(int l, int r, int node, int nl, int nr) {
		if (r < nl || nr < l) return{ md, md };
		push(node);
		if (l <= nl && nr <= r) {
			return t[node];
		}
		int mid = (nl + nr) / 2;
		pair<int, int> a = query(l, r, 2 * node + 1, nl, mid);
		pair<int, int> b = query(l, r, 2 * node + 2, mid + 1, nr);
		if (a.first < b.first) return a;
		if (a.first > b.first) return b;
		return{ a.first, a.second + b.second };
	}
};

int n;
vector<int> a;
segtree T;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i;

	T = segtree(n);
	set<int> have;
	int l = 0;
	vector<pair<int, int>> st;
	st.emplace_back(md, -1);
	ll ans = 0;
	for (int r = 0; r < n; r++) {
		int lst = 0;
		while (st.back().first <= a[r]) {
			T.add(st.back().second + 1, r, st.back().first - lst);
			lst = st.back().first;
			st.pop_back();
		}
		T.add(st.back().second + 1, r, a[r] - lst);
		st.emplace_back(a[r], r);

		if (have.count(a[r])) {
			while (a[l] != a[r])
				have.erase(a[l++]);
			l++;
		}
		else have.insert(a[r]);
		pair<int, int> res = T.query(l, r);
		if (res.first - 1 == r)
			ans += res.second;
	}
	cout << ans << '\n';
}