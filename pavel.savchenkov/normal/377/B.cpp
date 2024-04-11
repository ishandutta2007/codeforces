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

using namespace std;

#define pb push_back
#define f first
#define s second
#define mp make_pair 
#define sz(A) ((int)(A).size())
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; i--)
#define foran(i, a, n) for (int i = (int) a; i < (int) n; i++)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgk
#define right yytrwtretywretwreytwreytwr
#define all(A) A.begin(), A.end()

template <typename T>
inline T sqr( T x ) {
	return x * x;
}

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;

const double EPS = 1e-9;
const int MAXN = int(1e5) + 10;
const int INF = int(2e9);

struct segm_tree {
	vector <pii> t;
	int sz;

	segm_tree() {}

	segm_tree( int n ) {
		sz = 1;
		while (sz < n) sz *= 2;

		t.assign(sz * 2 + 10, mp(INF, 0));
	}

	void upd( int v, int tl, int tr, int pos, int val ) {
//		printf("%d %d %d\n", v, tl, tr);

		if  (tl == tr) {
			t[v] = mp(val, pos);
			return;	
		}

		int tm = (tl + tr) / 2;

		if  (pos <= tm)
			upd(v * 2, tl, tm, pos, val);
		else
			upd(v * 2 + 1, tm + 1, tr, pos, val);

		t[v] = min(t[v * 2], t[v * 2 + 1]);
	}

	void upd( int pos, int val ) { 
		upd(1, 0, sz - 1, pos, val);
	}

	pii get_min( int v, int tl, int tr, int l, int r ) {
//		printf("%d %d %d\n", v, tl, tr);

		l = max(l, tl);
		r = min(r, tr);

		if  (l > r)
			return mp(INF, 0);

		if  (tl == l && tr == r) {
			return t[v];
		}

		int tm = (tl + tr) / 2;

		return min(get_min(v * 2, tl, tm, l, r), get_min(v * 2 + 1, tm + 1, tr, l, r));
	}

	pii get_min( int l, int r ) {      
		return get_min(1, 0, sz - 1, l, r);
	}
};

struct stud {
	int b, c, id;

	stud() { }

	stud( int b, int c, int id ) : b(b), c(c), id(id) {}

	void output() {
		printf("%d %d %d\n", b, c, id);
	}
};

bool operator <( stud x, stud y ) {
	return x.b < y.b;
};

struct work {
	int a, id;

	work() {}

	work( int a, int id ) : a(a), id(id) {}
};

bool operator <( work x, work y ) {
	return x.a < y.a;
}

stud studs[MAXN];
work works[MAXN];
int b[MAXN];
int c[MAXN];
int n, m, s;
int ans[MAXN];
segm_tree t;

int get_min_pos( int A ) {
	int L = 0;
	int R = n;
	while (L != R - 1) {
		int M = (L + R) / 2;

		if  (studs[M].b >= A) {
			R = M;
		} else {
			L = M;
		}
	}

	if  (studs[0].b >= A)
		return 0;

	if  (studs[R].b >= A)
		return R;

	return -1;
}

ll minS( int days ) { 
	if  (days == 0)
		return INF;

//	forn(i, n)
//		studs[i].output();

	forn(i, n)
		t.upd(i, studs[i].c);

	ll S = 0;

	int i = m - 1;
	while (i >= 0) {
		int pos = get_min_pos(works[i].a);
		if  (pos == -1) {
			return INF;
		}
	
		pii p = t.get_min(pos, n - 1);
		pos = p.second;
		if  (p.first == INF) {
			return INF;
		}

		t.upd(pos, INF);

		S += studs[pos].c;

		i -= days;	
	}

	return S;	
};

void restore( int days ) {
	forn(i, n)
		t.upd(i, studs[i].c);

	int S = 0;
	int i = m - 1;
	while (i >= 0) {
		int pos = get_min_pos(works[i].a);
		assert(pos != -1);

		pii p = t.get_min(pos, n - 1);
		pos = p.second;
		assert(p.first < INF);

		S += studs[pos].c;

		t.upd(pos, INF);
		for (int j = i; j > i - days && j >= 0; j--)
			ans[works[j].id] = studs[pos].id;

		i -= days;	
	}

	assert(S <= s);
}

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	
	scanf("%d%d%d", &n, &m, &s);

	forn(i, m) {
		scanf("%d", &works[i].a);
		works[i].id = i;
	}
	sort(works, works + m);

	forn(i, n)
		scanf("%d", &b[i]);

	forn(i, n)
		scanf("%d", &c[i]);

	forn(i, n)
		studs[i] = stud(b[i], c[i], i);
	sort(studs, studs + n);

	t = segm_tree(n);

//	printf("f(2) = %d\n", minS(2));
//	return 0;

//	forn(i, 10)
//		printf("%d: %d\n", i, minS(i));

	int L = 0;
	int R = n + 10;
	while (L != R - 1) {
//		printf("[%d, %d]\n", L, R);

		int M = (L + R) / 2;

		if  (minS(M) > ll(s)) {
			L = M;
		} else {
			R = M;
		}
	}
//	printf("[%d, %d]\n", L, R);

	if  (minS(R) > ll(s)) {
		puts("NO");
		return 0;
	}

	puts("YES");
	restore(R);

	forn(i, m)
		printf("%d ", ans[i] + 1);

	return 0;
}