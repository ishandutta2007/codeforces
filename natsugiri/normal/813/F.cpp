#include<tuple>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}
struct UnionFindTimestamp {
    typedef pair<int, int> Pair;
    int n;
    vector<vector<Pair> >U;
    int count_link;
    UnionFindTimestamp(int n_ = 0) : n(n_), U(n+2), count_link(0) {
	REP (i, n) U[i].emplace_back(0, -1);
	U[n].emplace_back(0, n);
    }

    int root(int x, int t) const {
	while (1) {
	    if (t < U[x].back().first || U[x].back().second < 0) return x;
	    x = U[x].back().second;
	}
    }

    bool link(int x, int y) {
	x = root(x, count_link);
	y = root(y, count_link);
	count_link++;
	if (x == y) return false;
	if (U[x].back().second < U[y].back().second) swap(x, y);
	U[y].emplace_back(count_link, U[x].back().second + U[y].back().second); // (time, -size);
	U[x].emplace_back(count_link, y); // (time, parent = y);
	U[n].emplace_back(count_link, U[n].back().second-1); // (time, connected components);
	U[n+1].emplace_back(y, x); // (y, x);
	return true;
    }

    bool same(int x, int y, int t) const {
	return x == y || root(x, t) == root(y, t);
    }

    int count(int t) const { // # connected components;
	int k = upper_bound(U[n].begin(), U[n].end(), Pair(t, n)) - U[n].begin() - 1;
	return U[n][k].second;
    }

    int size(int x, int t) const {
	while (1) {
	    if (t < U[x].back().first || U[x].back().second < 0) {
		int k = upper_bound(U[x].begin(), U[x].end(), Pair(t, n)) - U[x].begin() - 1;
		return -U[x][k].second;
	    }
	    x = U[x].back().second;
	}
    }

    bool rollback() {
	if (count_link == 0) return false;
	count_link--;
	if (U[n+1].empty()) return false;
	Pair p = U[n+1].back();
	if (count_link >= U[p.first].back().first) return false;
	U[p.first].pop_back(); U[p.second].pop_back(); U[n].pop_back(); U[n+1].pop_back();
	return true;
    }
};

int N, Q;
tuple<int, int, int> E[100111];

vector<pair<int, int> > D[1 << 18];

UnionFindTimestamp U;

void add(int x, int y, int ax, int ay, int k, int l, int r) {
    if (Q <= l) return;

    if (y <= l || r <= x) {
    } else if (x <= l && r <= y) {
	D[k].emplace_back(ax, ay);
    } else {
	add(x, y, ax, ay, k * 2, l, (l+r)/2);
	add(x, y, ax, ay, k * 2 + 1, (l+r)/2, r);
    }
}

void solve(bool b, int k, int l, int r) {
    if (Q <= l) return;

    bool nb = b;
    int cnt = 0;
    if (b) {
	EACH (e, D[k]) {
	    int x = e->first, y = e->second;
//	    eprintf("%d: %d %d\n", k, x+1, y+1);
	    U.link(x, y+N);
	    U.link(x+N, y);
	    cnt += 2;
	    if (U.same(x, y, U.count_link)) {
		nb = false;
		break;
	    }
	}
    }

    if (l+1 == r) {
	if (l < Q) puts(nb? "YES": "NO");
    } else {
	solve(nb, k*2, l, (l+r)/2);
	solve(nb, k*2+1, (l+r)/2, r);
    }

    REP (i, cnt) U.rollback();
}

void MAIN() {
    scanf("%d%d", &N, &Q);
    REP (i, Q) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	if (x > y) swap(x, y);
	E[i] = make_tuple(x, y, i);
    }

    U = UnionFindTimestamp(2 * N);

    sort(E, E+Q);
    for (int i=0; i<Q; ) {
	int ax, ay, ai;
	int bx, by, bi;
	tie(ax, ay, ai) = E[i];
	tie(bx, by, bi) = E[i+1];
	if (i + 1 == Q || ax != bx || ay != by) {
	    add(ai, 1 << 17, ax, ay, 1, 0, 1 << 17);
	    i++;
	} else {
	    add(ai, bi, ax, ay, 1, 0, 1 << 17);
	    i+=2;
	}
    }

    solve(true, 1, 0, 1 << 17);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}