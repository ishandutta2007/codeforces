#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 1 << 20;
int n, inf, p[N]; 

struct seg {
	int tag[N];
	void init() {
		me(tag, -1);
	} 
	#define push(x) if(tag[x] != -1) tag[x << 1] = tag[x << 1 | 1] = tag[x], tag[x] = -1;
	void cov(int x, int L, int R, int l, int r, int w) {
		if(l <= L && R <= r) return tag[x] = w, void ();
		int mid = (L + R) >> 1;
		push(x);
		if(l <= mid) cov(x << 1, L, mid, l, r, w);
		if(r > mid) cov(x << 1 | 1, mid + 1, R, l, r, w);
	}
	int & get(int x, int L, int R, int p) {
		if(L == R) return tag[x];
		push(x);
		int mid = (L + R) >> 1;
		return p <= mid ? get(x << 1, L, mid, p) : get(x << 1 | 1, mid + 1, R, p);
	}
	int & operator [] (int x) {
		return get(1, 1, n, x);
	}
} f, g;

ll ns;
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n, inf = n + 1;
	L(i, 1, n) cin >> p[i]; 
	f.init(), g.init();
	L(i, 1, n) {
		if(i > 1) {
			int x = p[i - 1], cur = p[i];
			int pf = i, pg = i;
			R(o, 20, 0) if(pf > (1 << o) && cur > f[pf - (1 << o)]) pf -= 1 << o;
			R(o, 20, 0) if(pg > (1 << o) && cur < g[pg - (1 << o)]) pg -= 1 << o;
			if(x > cur) g.cov(1, 1, n, 1, i - 1, 0);
			else f.cov(1, 1, n, 1, i - 1, inf);
			int lf = pf - 1, lg = pg - 1;
			R(o, 20, 0) if(lf + (1 << o) < i && g[lf + (1 << o)] < x) lf += 1 << o;
			R(o, 20, 0) if(lg + (1 << o) < i && f[lg + (1 << o)] > x) lg += 1 << o;
			if(pf <= lf) g.cov(1, 1, n, pf, lf, x);
			if(pg <= lg) f.cov(1, 1, n, pg, lg, x);
		}
		f[i] = 0, g[i] = n + 1;
		int pos = i;
		R(o, 20, 0) if(pos > (1 << o) && (f[pos - (1 << o)] < inf || g[pos - (1 << o)] > 0)) pos -= 1 << o;
		ns += i - pos + 1;
	}
	cout << ns << '\n';
	return 0;
}