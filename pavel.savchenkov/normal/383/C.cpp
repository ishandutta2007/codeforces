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
const int MAXN = 2 * int(1e5) + 10;

struct segm_tree {
	vi add;
	int sz;

	segm_tree() {}

	segm_tree( int n ) {
		sz = 1;
		while (sz < n) sz *= 2;

		add.assign(sz * 2, 0);
	}

	void push( int v ) {
		add[v * 2] += add[v];
		add[v * 2 + 1] += add[v];
		add[v] = 0;
	}

	void put( int v, int tl, int tr, int l, int r, int val ) {
		l = max(l, tl);
		r = min(r, tr);

		if  (l > r)
			return;

		if  (l == tl && r == tr) {
			add[v] += val;
			return;
		}

		push(v);

		int tm = (tl + tr) / 2;
		put(v * 2, tl, tm, l, r, val);
		put(v * 2 + 1, tm + 1, tr, l, r, val);
	}

	void put( int l, int r, int val ) {
		put(1, 0, sz - 1, l, r, val);
	}

	int get( int v, int tl, int tr, int pos ) {
		if  (tl == tr) {
			return add[v];
		}

		int tm = (tl + tr) / 2;

		if  (pos <= tm)
			return get(v * 2, tl, tm, pos) + add[v];
		else
			return get(v * 2 + 1, tm + 1, tr, pos) + add[v];
	}

	int get( int pos ) {
		return get(1, 0, sz - 1, pos);
	}
};

vi g[MAXN];
int tin[MAXN];
int tout[MAXN];
int depth[MAXN];
int n, m;
int timer = 0;
int a[MAXN];
segm_tree tree_odd;
segm_tree tree_even;

void dfs( int v, int p ) {
	if  (p == -1)
		depth[v] = 0;
	else
		depth[v] = depth[p] + 1;

	tin[v] = timer++;

	forn(i, sz(g[v])) {
		int to = g[v][i];

		if  (to != p) {
			dfs(to, v);
		}
	}

	tout[v] = timer;
}

int main() {
	scanf("%d%d", &n, &m);

	forn(i, n)
		scanf("%d", &a[i]);

	forn(i, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		g[a].pb(b);
		g[b].pb(a);
	}

	depth[0] = 0;
	dfs(0, -1);

	tree_odd = segm_tree(n + 10);
	tree_even = segm_tree(n + 10);

	forn(i, n)
		if  (depth[i] & 1) {
			tree_odd.put(tin[i], tin[i], a[i]);
		} else {
			tree_even.put(tin[i], tin[i], a[i]);
		}

	while (m --> 0) {
		int type;
		scanf("%d", &type);

		if  (type == 1) {
			int v, add;
			scanf("%d%d", &v, &add);
			v--;

			int l = tin[v];
			int r = tout[v] - 1;

			if  (depth[v] & 1) {
				tree_odd.put(l, r, add);
				tree_even.put(l, r, -add);
			} else {
				tree_odd.put(l, r, -add);
				tree_even.put(l, r, add);
			}
		} else {
			int v, res;
			scanf("%d", &v);
			v--;

			if  (depth[v] & 1)
				res = tree_odd.get(tin[v]);
			else
				res = tree_even.get(tin[v]);

			printf("%d\n", res);
		}
	}

	return 0;
}