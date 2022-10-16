#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Tree {
	typedef int T;
	static constexpr T unit = INT_MIN;
	T f(T a, T b) { return max(a, b); }
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) {
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

void solve() {
	int n; cin >> n;
	vector<pair<int, int>> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i].first;
		p[i].second = i+1;
	}
	sort(p.begin(), p.end());

	Tree t(n+2);
	set<int> unused;
	for (int i = 1; i <= n; i++) {
		t.update(i, 0);
		unused.insert(i);
	}

	for (auto [val, id]: p) {
		unused.erase(id);
		int ans = 1;

		auto it = unused.lower_bound(id);
		if (it != unused.begin()) {
			it--;
			ans = max(ans, 2);
			ans = max(ans, t.query(1, *it) + 2);
		}

		ans = max(ans, t.query(1, id) + 1);
		t.update(id, ans);
	}
	cout << t.query(1, n+1) << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}