#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int)((x).size())
#define forn(i,n) for(int i = 0; i < (n); i++)
#define fornr(i,n) for(int i = (n) - 1; i >= 0; --i)
#define forab(i,a,b) for(int i = (a); i < (b); i++)
#define all(c) (c).begin(), (c).end()

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;
using dbl = long double;

const dbl eps = 1e-6;

bool ls(dbl a, dbl b) {
	return a < b - eps;
}

bool eq(dbl a, dbl b) {
	return abs(a - b) <= eps;
}

struct C {
	dbl w, xw, yw;
};

struct Comp {
	bool operator() (const pair<dbl, dbl> &a, const pair<dbl, dbl> &b) const {
		return ls(a.fst, b.fst) || (eq(a.fst, b.fst) && ls(a.snd, b.snd));
	}
};

int mask = 0;
vector<pair<C, pii>> got;
C curC;

void update1(dbl x, dbl y, dbl w) {
	curC.xw = (x * w + curC.w * curC.xw) / (w + curC.w);
	curC.yw = (y * w + curC.w * curC.yw) / (w + curC.w);
	curC.w += w;
}

void update(int x, int h1, int h2) {
	if (h1 > h2) {
		dbl xx = x  + 1. / 3.;
		dbl yy = h2 + 1. / 3.;		
		update1(xx, yy, 1./2.);
		h1 = h2;
	} else {
		dbl xx = x  + 2. / 3;
		dbl yy = h1 + 1. / 3.;	
		update1(xx, yy, 1./2.);
	}
	update1(x + 1./2., h1 / 2., h1);
}

void go(int i, int n, int bal) {
	if (n == 0) {
		got.pb({curC, {mask, bal}});
		return;
	}
	forn(j, 2) {
		int d = -1 + 2 * j;
		if (bal + d < 0) continue;
		if (j) {
			mask ^= (1 << i);
		}
		C old = curC;
		
		update(i, bal, bal + d);
		go(i + 1, n - 1, bal + d);
		
		curC = old;
		if (j) {
			mask ^= (1 << i);
		}
	}
}

const int N = 22;

map<pair<dbl, dbl>, int, Comp> gotMask[N];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	dbl x, y;
	cin >> n >> x >> y;
	int n2 = n / 2;
	go(0, n2, 0);
	
	forn(i, sz(got)) {
		int bal = got[i].snd.snd;
		int mask1 = got[i].snd.fst;
		C c = got[i].fst;
		dbl xx = n - c.xw;
		dbl yy = c.yw;
		gotMask[bal][mp((xx - x) * c.w, (yy - y) * c.w)] = mask1;
	}
	forn(i, sz(got)) {
		int bal = got[i].snd.snd;
		int mask1 = got[i].snd.fst;
		C c = got[i].fst;
		dbl xx = c.xw;
		dbl yy = c.yw;
		pair<dbl, dbl> toFind = mp((x - xx) * c.w, (y - yy) * c.w);
		if (gotMask[bal].count(toFind)) {
			int mask2 = gotMask[bal][toFind];
			forn(k, n2) {
				if ((mask1 >> k) & 1) {
					cout << '(';
				} else {
					cout << ')';
				}
			}
			fornr(k, n2) {
				if ((mask2 >> k) & 1) {
					cout << ')';
				} else {
					cout << '(';
				}
			}
			cout << '\n';
			return 0;
		}
	}
	assert(0);
	return 0;
}