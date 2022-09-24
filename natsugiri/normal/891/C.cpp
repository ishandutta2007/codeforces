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
const int MAXN = 500111;

int u[MAXN];
int root(int x) {
    int y = x, t;
    while (u[y] >= 0) y = u[y];
    while (x != y) { t = u[x]; u[x] = y; x = t; }
    return y;
}
bool link(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return false;
    if (u[y] < u[x]) swap(x, y);
    u[x] += u[y]; u[y] = x;
    return true;
}
bool same(int x, int y) { return root(x) == root(y); }


int N, M;
struct Edge {
    int x, y, w;
    bool possible;
} E[MAXN];

VI B[MAXN];
int A[MAXN];
int Z[MAXN];

UnionFindTimestamp U;

struct ByCost {
    bool operator()(int a, int b) const {
	return E[a].w < E[b].w;
    }
} byCost;

void query() {
    int K;
    scanf("%d", &K);
    REP (i, K) scanf("%d", A+i), A[i]--;

    bool yes = true;
    REP (i, K) {
	Edge &a = E[A[i]];
	if (!a.possible) {
	    yes = false;
	    break;
	}
    }
    if (yes) {
	sort(A, A+K, byCost);
	for (int i=0; yes && i<K; ) {
	    int j = i;
	    while (j < K && E[A[i]].w == E[A[j]].w) j++;

	    // [i, j);
	    for (int t=i; t<j; t++) {
		Edge a = E[A[t]];
		int rt;
		rt = U.root(a.x, Z[a.w]);
		u[a.x] = rt;
		u[rt] = -1;

		rt = U.root(a.y, Z[a.w]);
		u[a.y] = rt;
		u[rt] = -1;
	    }

	    for (int t=i; t<j; t++) {
		Edge a = E[A[t]];
		if (same(a.x, a.y)) {
		    yes = false;
		    break;
		}
		link(a.x, a.y);
	    }

	    i = j;
	}
    }

    puts(yes? "YES": "NO");
}

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, M) {
	int x, y, w;
	scanf("%d%d%d", &x, &y, &w);
	x--; y--;
	E[i].x = x;
	E[i].y = y;
	E[i].w = w;
	E[i].possible = false;

	B[w].push_back(i);
    }

    U = UnionFindTimestamp(N);

    REP (w, MAXN) {
	Z[w] = U.count_link;
	EACH (e, B[w]) {
	    Edge &a = E[*e];
	    if (!U.same(a.x, a.y, Z[w])) {
		a.possible = true;
	    }
	}
	EACH (e, B[w]) {
	    Edge &a = E[*e];
	    U.link(a.x, a.y);
	}
    }

    int Q;
    scanf("%d", &Q);
    REP ($, Q) query();
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}