#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 1 << 20, mx = 1e5;
template < int N > struct fenwt {
	using F = ll ;
	F a[N];
	void add(int x, F w) {
		for(; x < N; x += x & -x) a[x] += w;
	}
	F query(int x) {
		F ret = 0;
		for (; x; x -= x & -x) ret += a[x];
		return ret;
	}
};
fenwt < N > A, B; 
int n, m, a[N]; 
map < int, int > mp;
set < int > st[mx + 7];
int f[N];
//void inx(int v, int p) {
//	auto lp = --st[v].lower_bound(p), rp = lp;
//	++rp;
//	f[*rp - *lp] -= 1;
//	f[p - *lp] += 1;
//	f[*rp - p] += 1;
//	st[v].insert(p);
//}
//void dex(int v, int p) {
//	st[v].erase(p);
//	auto lp = --st[v].lower_bound(p), rp = lp;
//	++rp;
//	f[*rp - *lp] += 1;
//	f[p - *lp] -= 1;
//	f[*rp - p] -= 1;
//}
void mark(int x, int w) {
	A.add(x, w);
	B.add(x, w * x);
}
void ins(int v, int l, int r) {
	mark(1, r - l);
	auto lp = --st[v].lower_bound(l), rp = lp;
	++rp;
	mark(*rp - *lp, -1);
	mark(l - *lp, 1);
	mark(*rp - r, 1);
	st[v].insert(l);
	if(l != r) st[v].insert(r);
}
void del(int v, int l, int r) {
	mark(1, -(r - l));
	st[v].erase(l);
	if(l != r) st[v].erase(r);
	auto lp = --st[v].lower_bound(l), rp = lp;
	++rp;
	mark(*rp - *lp, 1);
	mark(l - *lp, -1);
	mark(*rp - r, -1);
}

int main () {
//	system("fc sequence.out ex_sequence7.out");
//	return 0;
//	freopen("sequence.in", "r", stdin);
//	freopen("sequence.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	L(i, 1, mx) st[i].insert(0), st[i].insert(n + 1);
	L(i, 1, n) cin >> a[i], mp[i] = a[i], ins(a[i], i, i); 
	mp[n + 1] = -1;
	while(m--) {
		int op, l, r, v;
		cin >> op;
		if(op == 1) {
			cin >> l >> r >> v;
			++r;
			auto xl = --mp.upper_bound(l), xr = --mp.upper_bound(r);
			int wl = xl -> second, wr = xr -> second;
			if(xl -> first != l) 
				mp[l] = wl, st[wl].insert(l - 1), st[wl].insert(l), xl = --mp.upper_bound(l);
			if(xr -> first != r)  
				mp[r] = wr, st[wr].insert(r - 1), st[wr].insert(r), xr = --mp.upper_bound(r);
			while(xl != xr) {
				int v = xl -> first, w = xl -> second;
				mp.erase(xl++);
				del(w, v, xl -> first - 1);
			}
			mp[l] = v;
			ins(v, l, r - 1);
		} else {
			int k ;
			cin >> k;
			ll ns = (ll) n * k;
			ns -= (ll) k * A.query(k);
			ns += B.query(k);
//			L(i, 1, k) 
//				ns -= (ll) f[i] * (k - i);
			cout << ns << '\n';
		}
	} 
	return 0;
}