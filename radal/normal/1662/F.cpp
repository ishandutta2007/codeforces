//In the name of Allah :)
#include <bits/stdc++.h>
using namespace std;
string to_string(char c) { return string(1,c); }
string to_string(bool b) { return b ? "true" : "false"; }
string to_string(const char* s) { return (string)s; }
string to_string(string s) { return s; }
string to_string(vector<bool> v) { 
	string res = "{"; for(int i = 0; i < (int)v.size(); i++) res += char('0'+v[i]);
	res += "}"; return res; }
template<size_t SZ> string to_string(bitset<SZ> b) {
	string res = ""; for(size_t i = 0; i < SZ; i++) res += char('0'+b[i]);
	return res; }
template<class A, class B> string to_string(pair<A,B> p);
template<class T> string to_string(T v) { // containers with begin(), end()
	bool fst = 1; string res = "{";
	for (const auto& x: v) {
		if (!fst) res += ", ";
		fst = 0; res += to_string(x);
	}
	res += "}"; return res;
}
template<class A, class B> string to_string(pair<A,B> p) {
	return "("+to_string(p.first)+", "+to_string(p.second)+")"; }
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
	cerr << to_string(h); if (sizeof...(t)) cerr << ", ";
	DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL
#define wis(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "] : [", DBG(__VA_ARGS__)
#else
#define wis(...) 0
#endif
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int INF = 1e9;

struct SegTree {
	int n;
	vector<pair<int, int>> seg;
	vector<int> a;
	pair<int, int> base;
	bool type;

	SegTree (const vector<int>& _a, bool _type) {
		a = _a;
		type = _type;
		n = a.size();
		seg.resize(a.size() << 2);
		build();
		base = type ? make_pair(INF, INF) : make_pair(-1, -1);
	}

	inline pair<int, int> f (pair<int, int> x, pair<int, int> y) {
		return type ? min(x, y) : max(x, y);
	}

	void build (int nd, int cl, int cr) {
		if (cr - cl == 1) {
			seg[nd] = {a[cl], cl};
			return;
		}
		int L = nd << 1, R = L | 1, mid = (cl + cr) >> 1;
		build(L, cl, mid), build(R, mid, cr);
		seg[nd] = f(seg[L], seg[R]);
	}
	inline void build () {
		build(1, 0, n);
	}

	pair<int, int> get (int nd, int cl, int cr, int l, int r) {
		if (cl == l && cr == r) {
			return seg[nd];
		}
		int L = nd << 1, R = L | 1, mid = (cl + cr) >> 1;
		pair<int, int> ret = base;
		if (l < mid) {
			ret = f(ret, get(L, cl, mid, l, min(r, mid)));
		}
		if (r > mid) {
			ret = f(ret, get(R, mid, cr, max(l, mid), r));
		}
		return ret;
	}
	inline int get (int l, int r) {
		return get(1, 0, n, l, r).second;
	}

	void remove(int nd, int cl, int cr, int ind) {
		if (cr - cl == 1) {
			seg[nd] = base;
			return;
		}
		int L = nd << 1, R = L | 1, mid = (cl + cr) >> 1;
		if (ind < mid) {
			remove(L, cl, mid, ind);
		}
		else {
			remove(R, mid, cr, ind);
		}
		seg[nd] = f(seg[L], seg[R]);
	}
	inline void remove (int ind) {
		remove(1, 0, n, ind);
	}

};


inline void test_case() {
	int n, a, b;
	cin >> n >> a >> b;
	a--, b--;
	vector<int> p(n), L(n), R(n), d(n, INF);
	vector<bool> mark(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		L[i] = max(0, i - p[i]);
		R[i] = min(n - 1, i + p[i]);
	}
	wis(L);
	wis(R);

	SegTree segj(R, 0), segp(L, 1);

	auto remove = [&](int v) {
		segj.remove(v), segp.remove(v);
	};
	
	d[a] = 0;
	mark[a] = 1;
	queue<int> q;
	q.push(a);
	remove(a);
	while (q.size()) {
		int f = q.front();
		wis(f);
		q.pop();
		int v;
		while ((v = segj.get(L[f], f)) != -1 && R[v] >= f) {
			d[v] = d[f] + 1;
			q.push(v);
			remove(v);
		}
		while ((v = segp.get(f, R[f] + 1)) != INF && L[v] <= f) {
			d[v] = d[f] + 1;
			q.push(v);
			remove(v);
		}
	}
	wis(d);
	cout << d[b] << '\n';
}

int main() {
	ios::sync_with_stdio(0);
#ifndef LOCAL
	cin.tie(0);
#endif
	int tt;
	cin >> tt;
	while(tt--){
		test_case();
	}
}