#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
using namespace std;


// maximum cht = type(1), minimum cht = type(-1)
struct cht {
	typedef long long ll;
	struct line {
		ll m, b, i, q;
		double nxt = 9e18;
		line(ll mm, ll bb, ll ii, ll qq = 0) : m(mm), b(bb), i(ii), q(qq) {};
		bool operator < (const line &x) const {
			if (!q && !x.q) return m < x.m;
			if (q) return m < x.nxt;
			return nxt < x.m;
		}
	};
	double cut(const line &x, const line &y) {
		return double(x.b - y.b) / (y.m - x.m);
	}
	int sign, nxtind = 0;
	cht(int type) {
		sign = type;
	}
	typedef set<line> s;
	s h;
	void upd(s::iterator &it) {
		if (next(it) != h.end()) {
			double n = cut(*it, *next(it));
			line l = *it;
			h.erase(it);
			l.nxt = n;
			it = h.insert(l).first;
		}
	}
	bool ok(s::iterator it) {
		if (it == h.begin() || next(it) == h.end() || cut(*prev(it), *it) < cut(*it, *next(it))) return true;
		return h.erase(it), false;
	}
	void insert(ll slope, ll constant) {
		line add(sign * slope, sign * constant, nxtind++);
		s::iterator it = h.insert(add).first;
		if (!ok(it)) return;
		while (it != h.begin() && !ok(prev(it)));
		while (next(it) != h.end() && !ok(next(it)));
		upd(it);
		if (it != h.begin()) upd(--it);
	}
	ll query(ll x) {
		line l = *h.lower_bound(line(x, 0, 0, 1));
		return sign * (x * l.m + l.b);
	}
	// returns the index of the best slope (indexed by the amount of lines tried to insert prior to it)
	ll iquery(ll x) {
		return h.lower_bound(line(x, 0, 0, 1))->i;
	}
};

int n;
vector<int> a, b;

void solve() {
	cin >> n;
	a.resize(n);
	b.resize(n);
	for (auto &i : a) cin >> i;
	for (auto &i : b) cin >> i;
	if (n == 1) {
		cout << "0\n";
		return;
	}
	cht T(-1);
	T.insert(b[0], 0);
	for (int i = 1; i < n - 1; i++) {
		ll mn = T.query(a[i]);
		T.insert(b[i], mn);
	}
	cout << T.query(a[n - 1]) << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	//cin >> tst;
	while (tst--) solve();
}