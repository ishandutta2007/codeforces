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

int N, M;
char F[55][55];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%s", F[i]);

    UnionFind U(N*M);


    REP (i, N) {
	int pos = -1;
	REP (j, M) if (F[i][j] == '#') {
	    pos = j;
	    break;
	}
	REP (j, M) if (F[i][j] == '#') {
	    U.link(i*M+pos, i*M+j);
	}
    }
    REP (j, M) {
	int pos = -1;
	REP (i, N) if (F[i][j] == '#') {
	    pos = i;
	    break;
	}
	REP (i, N) if (F[i][j] == '#') {
	    U.link(pos*M+j, i*M+j);
	}
    }

    bool yes = true;
    REP (i, N) REP (j, M) if (F[i][j] == '#') {
	int key = i*M+j;
	REP (a, N) REP (b, M) if (F[a][b] == '#') {
	    int key2 = a*M+b;
	    if (U.same(key, key2)) {
		if (F[i][b] != '#') yes = false;
		if (F[a][j] != '#') yes = false;
	    }
	}
    }

    puts(yes? "Yes": "No");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}