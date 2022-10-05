#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

/*
the struct 'element' must have:
* neutral element (as default constructor)
* operator *, to combine with a right operand and return the result
*/
template<typename element>
struct segtree {
	int n;
	vector<element> t;
	segtree() {}
	segtree(int sz) {
		n = max(2, sz);
		t.resize(2 * n, element());
	}
	segtree(const vector<element> &a) {
		n = max(2, (int)a.size());
		t.resize(2 * n);
		for (int i = 0; i < a.size(); i++)
			t[i + n - 1] = a[i];
		for (int i = n - 2; i >= 0; i--)
			t[i] = t[2 * i + 1] * t[2 * i + 2];
	}
	void update(int pos, element val) {
		pos += n - 1;
		if (t[pos].x >= val.x) return;
		t[pos] = val;
		while (pos) {
			pos = (pos - 1) / 2;
			t[pos] = t[2 * pos + 1] * t[2 * pos + 2];
		}
	}
	// iterative, without assuming commutativity.
	element iquery(int l, int r) {
		if (l > r) return element();
		element L = element(), R = element();
		for (l += n - 1, r += n - 1; l < r; l = (l - 1) / 2, r = (r - 1) / 2) {
			if (!(l & 1)) L = L * t[l++];
			if (r & 1) R = t[r--] * R;
		}
		if (l == r) L = L * t[l];
		return L * R;
	}
};

struct ele {
	int x;
	ele(int xx = -md) : x(xx) {}
	ele operator * (const ele &a) const {
		return ele(max(x, a.x));
	}
};

int n;
vector<ll> a;
vector<int> dp;

void solve() {
	cin >> n;
	a.resize(n);
	dp.resize(n + 1);
	for (auto &i : a) cin >> i;
	a.insert(a.begin(), 0LL);
	for (int i = 1; i <= n; i++)
		a[i] += a[i - 1];
	dp[0] = 0;

	map<ll, int> tmp;
	for (auto &i : a)
		tmp[i] = 0;
	int tmp2 = 0;
	for (auto &i : tmp)
		i.second = tmp2++;
	for (auto &i : a)
		i = tmp[i];

	map<int, int> lst;
	lst[a[0]] = 0;

	segtree<ele> low(n + 3), high(n + 3);
	low.update(a[0], ele(0));
	high.update(a[0], ele(0));
	for (int i = 1; i <= n; i++) {
		dp[i] = -md;
		if (lst.count(a[i])) {
			dp[i] = max(dp[i], dp[lst[a[i]]]);
		}
		lst[a[i]] = i;

		dp[i] = max(dp[i], low.iquery(0, a[i] - 1).x + i);
		dp[i] = max(dp[i], high.iquery(a[i] + 1, n + 2).x - i);

		low.update(a[i], ele(dp[i] - i));
		high.update(a[i], ele(dp[i] + i));
	}
	cout << dp[n] << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}