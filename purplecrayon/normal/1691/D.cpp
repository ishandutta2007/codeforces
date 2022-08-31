#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;
const ll INF = 1e18+10;

struct MaxTree {
	typedef ll T;
	static constexpr T unit = -INF;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	MaxTree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void upd(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T qry(int b, int e) { // query [b, e)
        e++;
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};
struct MinTree {
	typedef ll T;
	static constexpr T unit = INF;
	T f(T a, T b) { return min(a, b); } // (any associative fn)
	vector<T> s; int n;
	MinTree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void upd(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T qry(int b, int e) { // query [b, e)
        e++;
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
    vector<int> a(n); for (auto& x : a) cin >> x;
    vector<int> nxt(n, n), prv(n, -1);
    vector<int> st;
    for (int i = 0; i < n; i++) {
        while (sz(st) && a[st.back()] <= a[i]) st.pop_back();
        if (sz(st)) prv[i] = st.back();
        st.push_back(i);
    }

    st.clear();
    for (int i = n-1; i >= 0; i--) {
        while (sz(st) && a[st.back()] < a[i]) st.pop_back();
        if (sz(st)) nxt[i] = st.back();
        st.push_back(i);
    }

    vector<ll> pre(n);
    for (int i = 0; i < n; i++) {
        pre[i] = a[i];
        if (i) pre[i] += pre[i-1];
    }
    MaxTree maxtree(n);
    MinTree mintree(n + 1);
    for (int i = 0; i < n; i++) maxtree.upd(i, pre[i]);
    for (int i = 0; i < n; i++) mintree.upd(i + 1, pre[i]);
    mintree.upd(0, 0);
    for (int i = 0; i < n; i++) {
        int L = prv[i] + 1, R = nxt[i] - 1;
        if (maxtree.qry(i, R) - (i ? pre[i-1] : 0) > a[i]) {
            cout << "NO\n";
            return;
        }
        if (pre[i] - mintree.qry(L, i) > a[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}