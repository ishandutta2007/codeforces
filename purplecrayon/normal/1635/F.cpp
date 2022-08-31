#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

struct Tree {
	typedef ll T;
	static constexpr T unit = LLONG_MAX;
	T f(T a, T b) { return min(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
        s[pos + n] = f(s[pos + n], val);
		for (pos += n; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
        e++;
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};


struct pt {
    ll x, y;
    int i;
};
int orientation(pt a, pt b, pt c) {
    ll v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}
bool cw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
bool ccw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o > 0 || (include_collinear && o == 0);
}

// find lower convex hull of points, only consider adjacent pairs
// adding ap oint

void solve() {
    int n, q; cin >> n >> q;
    vector<pt> a(n); for (auto& x : a) cin >> x.x >> x.y;
    for (int i = 0; i < n; i++) a[i].i = i;

    auto get = [&](int x, int y) {
        return abs(a[x].x - a[y].x) * (a[x].y + a[y].y);
    };

    vector<vector<pair<int, int>>> qr(n);
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r, --l, --r;
        qr[r].emplace_back(l, i);
    }
    vector<ll> ans(q, LLONG_MAX);

    vector<pt> st;
    Tree seg(n);
    for (int r = 0; r < n; r++) {
        while (sz(st) && st.back().y >= a[r].y) {
            seg.update(st.back().i, get(st.back().i, r));
            st.pop_back();
        }
        if (sz(st)) seg.update(st.back().i, get(st.back().i, r));
        st.push_back(a[r]);
        for (auto& [l, i] : qr[r]) {
            ans[i] = min(ans[i], seg.query(l, r));
        }
    }
    for (auto& x : ans) cout << x << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}