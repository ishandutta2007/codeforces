#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define ull unsigned long long 
using namespace std;
const int N = 1 << 20;

struct node {
	int L, R, all, mid, mx, rmx, mxc, at1, at2; // real tag (max/notmax) ; 
	ll sum; 
	node * ls, * rs;
	void update () {
		sum = ls -> sum + rs -> sum;
		all = ls -> all + rs -> all;
		if(ls -> mx == rs -> mx) mx = ls -> mx, mxc = ls -> mxc + rs -> mxc, rmx = max (ls -> rmx, rs -> rmx);
		else if(ls -> mx > rs -> mx) mx = ls -> mx, mxc = ls -> mxc, rmx = max (ls -> rmx, rs -> mx);
		else mx = rs -> mx, mxc = rs -> mxc, rmx = max (ls -> mx, rs -> rmx);
	}
	node (int _L = 0, int _R = 0) {
		L = _L, R = _R, mid = (L + R) >> 1, at1 = at2 = 0;
		if(L != R) ls = new node (L, mid), rs = new node (mid + 1, R), update ();
		else mx = rmx = -1e9, mxc = 0, sum = 0, all = 0;
	}
	void make (int a1, int a2) {
		sum += (ll) a1 * mxc + (ll) a2 * (all - mxc);
		mx += a1, at1 += a1, at2 += a2;
		if (rmx != -1e9) rmx += a2;
	}
	void push () {
		if (ls -> mx + at1 == mx) ls -> make (at1, at2); 
		else ls -> make (at2, at2);
		if (rs -> mx + at1 == mx) rs -> make (at1, at2);
		else rs -> make (at2, at2);
		at1 = at2 = 0;
	}
	void mark (int p, int k) {
		if (L == R) return all = 1, mx = k, sum = k, mxc = 1, rmx = -1e9, void ();
		push ();
		if (p <= mid) ls -> mark (p, k);
		else rs -> mark (p, k);
		update ();
	}
	void add (int l, int r, int k) {
		if (l <= L && R <= r) return make (k, k), void ();
		push ();
		if (l <= mid) ls -> add (l, r, k);
		if (r > mid) rs -> add (l, r, k);
		update ();
	}
	void mkmin (int l, int r, int k) {
		if (mx <= k) return ;
		if (l <= L && R <= r && rmx < k) return make (k - mx, 0);
		if (L == R) assert (0);
		push ();
		if (l <= mid) ls -> mkmin (l, r, k);
		if (r > mid) rs -> mkmin (l, r, k);
		update ();
	}
} ;

template < int N > struct fenwt {
	using F = long long ;
	F a[N + 1];
	void add (int x, F w) {
		for (; x <= N; x += x & -x) a[x] += w;
	}
	F query (int x) {
		F ret = 0;
		for (; x; x -= x & -x) ret += a[x];
		return ret;
	}
	F get (int l, int r) {
		if(l > r) return 0;
		return query (r) - query (l - 1);
	}
} ;

int n;
struct hehe {
	int p[N], mp[N], w[N];
	node * fw;
	void Init () {
		L(i, 1, n) mp[p[i]] = i;
		fw = new node (1, n);
	}
	fenwt < N > s;
	ll insert (int x) {
		int pos = mp[x], cnt = 0;
		s.add (pos, 1), cnt = s.query(pos);
		fw -> mark (pos, x + 1);
		if(pos > 1) fw -> mkmin (1, pos - 1, cnt);
		if(pos < n) fw -> add (pos + 1, n, 1);
		return fw -> sum;
	}
} a, b;

int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> n ;
	L(i, 1, n) cin >> a.p[i], b.p[n - i + 1] = a.p[i];
	a.Init (), b.Init();
	L(i, 1, n) cout << a.insert (i) + b.insert(i) - (ll) i * (i + 2) << '\n';
	return 0;
}