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
const int INF = int(1e9);

struct segm_tree {
	vi a0;
	int d;
	int sz;

	segm_tree() {}

	segm_tree( int n, int d = 0 ) : d(d) {
		sz = 1;
		while (sz < n) sz <<= 1;

	   	a0.assign(2 * sz, INF);
	}

	void push( int v, int tl, int tr ) {
		if  (tl == tr) {
			return;
		}

		int na0 = a0[v] + d * ((tr - tl + 1) / 2);
		a0[v * 2] = min(a0[v * 2], a0[v]);
		a0[v * 2 + 1] = min(a0[v * 2 + 1], na0);
	}

	void put( int v, int tl, int tr, int l, int r, int A0 ) {
		push(v, tl, tr);

		if  (tl == l && tr == r) {
			a0[v] = min(a0[v], A0);
			return;
		}

		int tm = (tl + tr) >> 1;

		if  (r <= tm) {
			put(v * 2, tl, tm, l, r, A0);
		} else if  (tm < l) {
			put(v * 2 + 1, tm + 1, tr, l, r, A0);
		} else {
			put(v * 2, tl, tm, l, tm, A0);
			put(v * 2 + 1, tm + 1, tr, tm + 1, r, A0 + d * (tm - l + 1));
		}
	}

	void put( int l, int r, int A0 ) {
		if  (l > r)
			return;
		put(1, 0, sz - 1, l, r, A0);
	}

	int get( int v, int tl, int tr, int pos ) {
		push(v, tl, tr);

		if  (tl == tr && tr == pos) {
			return a0[v];
		}

		int tm = (tl + tr) >> 1;

		if  (pos <= tm)
			return get(v * 2, tl, tm, pos);
		else
			return get(v * 2 + 1, tm + 1, tr, pos);
	}

	int get( int pos ) {
		return get(1, 0, sz - 1, pos);
	}
};

segm_tree t_pos;
segm_tree t_neg;
int posa[MAXN];
int posb[MAXN];
int n;

int main() {
	scanf("%d", &n);

	forn(i, n) {
		int a;
		scanf("%d", &a);
		a--;
		posa[a] = n - i - 1;
	}

	forn(i, n) {
		int b;
		scanf("%d", &b);
		b--;
		posb[b] = n - i - 1;
	}

	t_pos = segm_tree(n, 1);
	t_neg = segm_tree(n, -1);

	forn(i, n) {
		if  (posa[i] < posb[i]) {
			int l = 0;
			int cnt = n - posb[i];
			t_pos.put(l, l + cnt - 1, posb[i] - posa[i]);

			l += cnt;
			cnt = posa[i] + 1;
			t_neg.put(l, l + cnt - 1, posa[i]);

			l += cnt;
			cnt = posb[i] - posa[i] - 1;
			t_pos.put(l, l + cnt - 1, 1);
		} else if  (posa[i] > posb[i]) {
			int l = 0;
			int cnt = posa[i] - posb[i] + 1;
			t_neg.put(l, l + cnt - 1, posa[i] - posb[i]);

			l += cnt;
			cnt = n - posa[i] - 1;
			t_pos.put(l, l + cnt - 1, 1);

			l += cnt;
			cnt = posb[i];
			t_neg.put(l, l + cnt - 1, posa[i]);
		} else {
			assert(posa[i] == posb[i]);

			int l = 0;
			int cnt = n - posa[i];
			t_pos.put(l, l + cnt - 1, 0);

			l += cnt;
			cnt = posa[i];
			t_neg.put(l, l + cnt - 1, posa[i]);
		}	
	}

	forn(i, n)
		printf("%d\n", min(t_pos.get(i), t_neg.get(i)));
	return 0;
}