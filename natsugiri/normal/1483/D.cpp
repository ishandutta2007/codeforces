#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<queue>

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
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)


int N, M, Q;
struct Edge {
    int x, y;
    LL w;
    Edge() {}
    Edge(int x_, int y_, LL w_) : x(x_), y(y_), w(w_) {}
    bool operator<(const Edge &o) const {
	return w < o.w;
    }

    int anti(int v) const {
	assert(v == x || v == y);
	return v ^ x ^ y;

    }
};
Edge E[200011];
Edge P[200011];
bool act[200011];

bool fix[611];

LL A[611][611];
LL B[611][611];

LL F[611];
LL D[611];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, M) {
	int x, y, w;
	scanf("%d%d%d", &x, &y, &w);
	x--; y--;
	E[i].x = x;
	E[i].y = y;
	E[i].w = w;
    }
    scanf("%d", &Q);
    REP (i, Q) {
	int x, y, w;
	scanf("%d%d%d", &x, &y, &w);
	x--; y--;
	P[i].x = x;
	P[i].y = y;
	P[i].w = w;
    }

#ifdef LOCAL
    {
	int len = 0;
	N = 600;
	REP (i, N) REP (j, i) {
	    E[len].x = i;
	    E[len].y = j;
	    E[len].w = rand();
	    P[len].x = i;
	    P[len].y = j;
	    P[len].w = rand();
	    len++;
	}
	M = len;
	Q = len;
	// Q = 0;
    }
#endif

    memset(A, -1, sizeof A);
    REP (i, M) {
	int x = E[i].x;
	int y = E[i].y;
	int w = E[i].w;
	A[x][y] = A[y][x] = w;
    }

    memset(B, -1, sizeof B);
    REP (i, Q) {
	int x = P[i].x;
	int y = P[i].y;
	LL w = P[i].w;
	amax(B[x][y], w);
	amax(B[y][x], w);
    }

    REP (root, N) {
	memset(F, 0xc0, sizeof F);
	REP (w, N) if (B[root][w] != -1) {
	    amax(F[w], B[root][w]);
	}

	memset(fix, 0, sizeof fix);
	while (1) {
	    int v = -1;
	    REP (i, N) if (!fix[i] && F[i] >= 0 && (v == -1 || F[v] < F[i])) {
		v = i;
	    }
	    if (v == -1) break;

	    LL cst = F[v];
	    fix[v] = true;

	    REP (w, N) if (A[v][w] != -1) {
		LL nxt = cst - A[v][w];
		amax(F[w], nxt);
	    }
	}
	

	memset(D, 0x3f, sizeof D);
	memset(fix, 0, sizeof fix);
	D[root] = 0;
	while (1) {
	    int v = -1;
	    REP (i, N) if (!fix[i] && (v == -1 || D[v] > D[i])) {
		v = i;
	    }
	    if (v == -1) break;

	    LL cst = D[v];
	    fix[v] = true;

	    REP (w, N) if (A[v][w] != -1) {
		LL nxt = cst + A[v][w];
		amin(D[w], nxt);
	    }
	}

	REP (i, M) if (!act[i]) {
	    int x = E[i].x;
	    int y = E[i].y;
	    REP (t, 2) {
		LL cst = D[x] + E[i].w;
		if (F[y] >= cst) act[i] = true;
		swap(x, y);
	    }
	}
    }

    int ans = 0;
    REP (i, M) if (act[i]) ans++;

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}