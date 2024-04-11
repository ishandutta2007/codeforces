#include<stack>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

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
char F[1011][1011];

int deg[2011];
VI G[2011];

int ans[2011];
int ansA[2011];
int ansB[2011];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%s", F[i]);

    UnionFind U(N+M);

    REP (i, N) REP (j, M) if (F[i][j] == '=') {
	U.link(i, j+N);
    }
    REP (i, N) G[U.root(i)].push_back(i);
    REP (j, M) G[U.root(j+N)].push_back(j+N);

    REP (i, N) REP (j, M) {
	if (F[i][j] == '<') {
	    deg[U.root(j+N)]++;
	}
	if (F[i][j] == '>') {
	    deg[U.root(i)]++;
	}
    }

    stack<int> st;
    REP (i, N+M) if (U.root(i) == i && deg[i] == 0) {
	ans[i] = 1;
	st.push(i);
    }

    while (!st.empty()) {
	int x = st.top(); st.pop();
	EACH (e, G[x]) {
	    int w = *e;
	    if (w < N) {
		REP (j, M) if (F[w][j] == '<') {
		    int g = U.root(j+N);
		    amax(ans[g], ans[x] + 1);
		    deg[g]--;
		    if (deg[g] == 0) {
			st.push(g);
		    }
		}
	    } else {
		w -= N;
		REP (i, N) if (F[i][w] == '>') {
		    int g = U.root(i);
		    amax(ans[g], ans[x] + 1);
		    deg[g]--;
		    if (deg[g] == 0) {
			st.push(g);
		    }
		}
	    }
	}
    }


    REP (i, N) ansA[i] = ans[U.root(i)];
    REP (j, M) ansB[j] = ans[U.root(j+N)];

    bool yes = true;
    if (*min_element(ansA, ansA+N) == 0) yes = false;
    if (*min_element(ansB, ansB+M) == 0) yes = false;

    REP (i, N) REP (j, M) {
	if ((F[i][j] == '<' && ansA[i] < ansB[j])
		|| (F[i][j] == '>' && ansA[i] > ansB[j])
		|| (F[i][j] == '=' && ansA[i] == ansB[j])) {
	    // nothing;
	} else {
	    yes = false;
	}
    }

    if (yes) {
	puts("Yes");
	rprintf("%d", ansA, ansA+N);
	rprintf("%d", ansB, ansB+M);
    } else {
	puts("No");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}