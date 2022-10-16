#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll INF = 1e16;

struct TreeMn {
	typedef ll T;
	static constexpr T unit = INF;
	T f(T a, T b) { return min(a, b); } // (any associative fn)
	vector<T> s; int n;
	TreeMn(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

struct TreeMx {
	typedef ll T;
	static constexpr T unit = -INF;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	TreeMx(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

#define int long long

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, q; cin >> n >> q;
	vector<int> a(n+1), b(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= n; i++) {
		a[i] = b[i] - a[i];
	}

	// process
	vector<int> pref(n+1);
	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i-1] + a[i];
	}

	TreeMn mn(n+3);
	TreeMx mx(n+3);
	for (int i = 1; i <= n; i++) {
		mn.update(i, pref[i]);
		mx.update(i, pref[i]);
	}

	while (q--) {
		int l, r; cin >> l >> r;
		if ((pref[r] - pref[l-1]) != 0) {
			cout << "-1\n";
			continue;
		}
		if ((mn.query(l, r+1) - pref[l-1]) < 0) {
			cout << "-1\n";
			continue;
		}

		cout << mx.query(l, r+1) - pref[l-1] << '\n';
	}

	return 0;
}