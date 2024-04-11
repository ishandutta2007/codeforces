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


const int MAGIC = 334;
int N, M, K;
VI G[100111], R[100111];;
int Q;

struct Query {
    int l, r, id;
    bool operator<(const Query &y) const {
	return l / MAGIC != y.l / MAGIC ? l < y.l :
	    r < y.r;
    }
} query[100111];

int ans[100111];

struct UnionFind {
    int n, cc, *u;
    UnionFind() : n(0), cc(0), u(NULL) {}
    UnionFind(int n_) : n(n_), cc(n_) {
	u = new int[n_];
	memset(u, -1, sizeof (int) * n);
    }
    UnionFind(const UnionFind &y) : n(y.n), cc(y.cc) {
	u = new int[y.n];
	memcpy(u, y.u, sizeof (int) * n);
    }
    ~UnionFind() {
	delete[] u; u = NULL;
	n = cc = 0;
    }
    friend void swap(UnionFind &x, UnionFind &y) {
	swap(x.n, y.n); swap(x.cc, y.cc); swap(x.u, y.u);
    }
    UnionFind& operator=(UnionFind y) { 
	swap(*this, y);
	return *this;
    }
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
	u[x] += u[y]; u[y] = x; cc--;
	return true;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -u[root(x)]; }
    int count() { return cc; }
};

void naive(int l, int r, int i) {
    UnionFind U(r - l);
    for (int j=l; j<r; j++) {
	EACH (e, G[j]) if (*e < r) U.link(j - l, *e - l);
    }

    ans[i] = U.count();
}

int main() {
    scanf("%d%d%d", &N, &K, &M);
    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	if (y < x) swap(x, y);
	G[x].push_back(y);
	R[y].push_back(x);
    }

    scanf("%d", &Q);
    int cur = 0;
    REP (i, Q) {
	int l, r;
	scanf("%d%d", &l, &r);
	l--;
	if (r - l < 2 * MAGIC) {
	    naive(l, r, i);
	} else {
	    query[cur].l = l;
	    query[cur].r = r;
	    query[cur].id = i;
	    cur++;
	}
    }


    sort(query, query + cur);
    for (int i=0; i<cur; ) {
	int j = i;
	int sep = (query[i].l / MAGIC + 1) * MAGIC;
	int pos = sep;
	UnionFindTimestamp U(N);
	while (j < cur && query[j].l < sep) {
	    int bak = query[j].r - 1;
	    // right
	    while (pos < query[j].r) {
		EACH (e, R[pos]) if (sep <= *e) U.link(*e, pos);
		pos++;
	    }

	    int cnt = 0;
	    for (int top=sep-1; top >= query[j].l; top--) {
		EACH (e, G[top]) if (*e <= bak) {
		    cnt++;
		    U.link(top, *e);
		}
	    }

	    ans[query[j].id] = U.count(U.count_link) - query[j].l - (N - query[j].r);
	    REP (t, cnt) U.rollback();
	    j++;
	}

	i = j;
    }

    REP (i, Q) printf("%d\n", ans[i]);

    return 0;
}