#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>
#include <complex>
#include <bitset>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;

#define ws ws_____________________
#define y1 y1_____________________
#define y0 y0_____________________
#define left left_________________
#define right right_______________
#define next next_________________
#define prev prev_________________
#define hash hash_________________

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector <int> > vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME "a"

const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;

void add(int& x, int y) {
	((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
	return x * 1ll * y % MOD;
}

struct Matr {
	static const int N = 2;

	int a[N][N];

	int size() const {
		return N;
	}

	Matr() {
		forn(i, N) forn(j, N) a[i][j] = i == j;
	}

	const int* operator[](int i) const {
		return a[i];
	}

	int* operator[](int i) {
		return a[i];
	}	

	Matr& operator *= (const Matr& m) {
		static int res[N][N];
		forn(i, N) forn(j, N) {
			ll c = 0;
			forn(k, N) {
				c += a[i][k] * 1ll * m[k][j];
			}
			res[i][j] = c % MOD;
		}
		memcpy(a, res, sizeof a);
		return *this;
	}
};

struct Vect {
	static const int N = 2;

	int a[N];

	Vect() {
		memset (a, 0, sizeof a);
	}

	int size() const {
		return N;
	}

	int& operator[](int i) {
		return a[i];
	}

	const int& operator[](int i) const {
		return a[i];
	}
};

Vect operator * (const Matr& m, const Vect& v) {
	Vect res;
	forn(i, sz(m)) forn(j, sz(m)) {
		add(res[i], mul(m[i][j], v[j]));
	}
	return res;
}

Vect operator + (const Vect& v, const Vect& u) {
	Vect res;
	forn(i, sz(res)) {
		res[i] = v[i];
		add(res[i], u[i]);
	}
	return res;
}

Matr mpow(Matr a, int p) {
	Matr res;
	for (; p > 0; a *= a, p >>= 1) {
		if  (p & 1) {
			res *= a;
		}
	}
	return res;
}

Matr mpow(int p) {
	Matr t;
	t[0][0] = 0;
	t[1][1] = t[1][0] = t[0][1] = 1;
	return mpow(t, p);
}

struct SegmTree {
	Vect t[4 * MAXN];
	Matr mul[4 * MAXN];
	int sz;

	SegmTree(int n = 0) {
		sz = 1;
		while (sz < n) sz *= 2;
		forn(v, sz * 2) {
			t[v] = Vect();
			t[v][1] = 1;
			mul[v] = Matr();
		}
	}

	void upd(int v) {
		t[v] = t[v * 2] + t[v * 2 + 1];
		t[v] = mul[v] * t[v];
	}

	void go_mul(int v, int tl, int tr, int l, int r, const Matr& m) {
		l = max(l, tl);
		r = min(r, tr);

		if  (l > r) {
			return;
		}

		if  (l == tl && r == tr) {
			mul[v] *= m;
			t[v] = m * t[v];
			return;
		}

		int tm = (tl + tr) >> 1;
		go_mul(v * 2, tl, tm, l, r, m);
		go_mul(v * 2 + 1, tm + 1, tr, l, r, m);

		upd(v);
	}

	void go_mul(int l, int r, const Matr& m) {
		go_mul(1, 0, sz - 1, l, r, m);
	}

	Vect get(int v, int tl, int tr, int l, int r) {
		l = max(l, tl);
		r = min(r, tr);

		if  (l > r) {
			return Vect();
		}

		if  (l == tl && r == tr) {
			return t[v];
		}

		int tm = (tl + tr) >> 1;
		auto res = get(v * 2, tl, tm, l, r) + get(v * 2 + 1, tm + 1, tr, l, r);
		res = mul[v] * res;

		return res;
	}

	int get(int l, int r) {
		return get(1, 0, sz - 1, l, r)[1];
	}
};

int n, m;
int a[MAXN];

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return false;
	}
	forn(i, n) {
		scanf("%d", &a[i]);
	}
	return true;
}

void solve() {
	SegmTree T(n);
	forn(i, n) {
		T.go_mul(i, i, mpow(a[i] - 1));
	}

	forn(it, m) {
		int t, l, r;
		scanf("%d%d%d", &t, &l, &r);
		--l;
		--r;
		if  (t == 1) {
			int x;
			scanf("%d", &x);
			T.go_mul(l, r, mpow(x));
		} else {
			printf("%d\n", T.get(l, r));
		}
	}
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		solve();
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}