#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Tree {
	typedef long long T;
	static constexpr T unit = 1000000000000000000;
	T f(T a, T b) { return min(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
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

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int x; cin >> x;
	for (int i = 0; i < n; i++) {
		a[i] -= x;
	}

	vector<int> b(n+1);
	for (int i = 0; i < n; i++) {
		b[i+1] = b[i] + a[i];
	}

	Tree st(n+3);
	for (int i = 0; i <= n; i++) {
		st.update(i, b[i]);
	}

	vector<int> jump(n+2);
	for (int i = 0; i <= n+1; i++) {
		int lo = i+2, hi = n+1;
		while (lo < hi) {
			int mid = (lo + hi)/2;

			// from i+2 to mid
			if (st.query(i+2, mid+1) < b[i]) {
				hi = mid;
			} else {
				lo = mid+1;
			}
		}
		jump[i] = min(lo, hi);
	}

	for (int i = n; i >= 0; i--) {
		jump[i] = min(jump[i], jump[i+1]);
	}

	//for (int i: jump) cout << i << ' ';
	//	cout << '\n';

	int ans = -1, cur = 0;
	while (cur <= n) {
		ans++; cur = jump[cur];
	}
	cout << n-ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}