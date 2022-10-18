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

using namespace std;

#define pb push_back
#define f first
#define s second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define foran(i, a, n) for (int i = (int) a; i < (int) n; ++i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define all(C) (C).begin(), (C).end()

template <typename T>
inline T sqr( T x ) {
	return x * x;
}

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;

const double EPS = 1e-9;

class SegmentTree {
private:
	vll add;
	vi toPut;
	vll sum;
	int sz;

public:
	SegmentTree() {}

	SegmentTree( int n ) {
		sz = 1;
		while (sz < n) sz <<= 1;

		add.assign(sz << 1, 0);
		toPut.assign(sz << 1, -1);
		sum.assign(sz << 1, 0);

		for (int i = sz; i < sz + n; ++i) {
			toPut[i] = (i - sz) + 1;
		}
	}

private:
	void push( int v, int len ) {
		if  (add[v]) {
			sum[v] += add[v] * len;
			add[v * 2] += add[v];
			add[v * 2 + 1] += add[v];
			add[v] = 0;
		}

		if  (toPut[v] != -1) {
			toPut[v * 2] = toPut[v];
			toPut[v * 2 + 1] = toPut[v];
		}
	}

	void recalc( int v, int len ) {
		sum[v] = sum[v * 2] + add[v * 2] * (len >> 1) + sum[v * 2 + 1] + add[v * 2 + 1] * (len >> 1);
		
		if  (toPut[v * 2] == -1 || toPut[v * 2 + 1] == -1 || toPut[v * 2] != toPut[v * 2 + 1]) {
			toPut[v] = -1;
		} else {
			toPut[v] = toPut[v * 2];
		}
   	}
    
	void put( int v, int tl, int tr, int l, int r, int x ) {
		l = max(l, tl);
		r = min(r, tr);

		if  (l > r) {
			return;
		}

		if  (l == tl && r == tr && (toPut[v] != -1 || tl == tr)) {
			add[v] += abs(toPut[v] - x);
			toPut[v] = x;
			return;			
		}

		push(v, tr - tl + 1);

		int tm = (tl + tr) >> 1;

		put(v * 2, tl, tm, l, r, x);
		put(v * 2 + 1, tm + 1, tr, l, r, x);

		recalc(v, tr - tl + 1);
	}

public:
	void Put( int l, int r, int x ) {
		put(1, 0, sz - 1, l, r, x);
	}

private:
	ll getSum( int v, int tl, int tr, int l, int r ) {
		l = max(l, tl);
		r = min(r, tr);

		if  (l > r) {
			return 0;
		}

		if  (l == tl && r == tr) {
			int len = tr - tl + 1;
			return sum[v] + add[v] * len;
		}

		push(v, tr - tl + 1);

		int tm = (tl + tr) >> 1;
		return getSum(v * 2, tl, tm, l, r) + getSum(v * 2 + 1, tm + 1, tr, l, r);
	}

public:
	ll GetSum( int l, int r ) {
		return getSum(1, 0, sz - 1, l, r);
	}
};

int n, m;
SegmentTree T;

int main() {
	scanf("%d%d", &n, &m);

	T = SegmentTree(n);

	while (m --> 0) {
		int t;
		scanf("%d", &t);

		if  (t == 1) {
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			--l;
			--r;

			T.Put(l, r, x);
		} else {
			assert(t == 2);

			int l, r;
			scanf("%d%d", &l, &r);
			--l;
			--r;

			printf("%I64d\n", T.GetSum(l, r));
		}
	}

	return 0;
}