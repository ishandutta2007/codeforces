#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
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

int N;
VI G[200011];
LL A[200011];
int B[200011];
int C[200011];

int par[200011];
int nxt[200011];

int D[200011][2];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld%d%d", A+i, B+i, C+i);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    if (count(B, B+N, 1) != count(C, C+N, 1)) {
	puts("-1");
	return;
    }

    par[0] = -1;
    nxt[0] = -1;

    VI que;
    que.reserve(N);
    que.push_back(0);
    REP (i_, N) {
	int v = que[i_];
	EACH (e, G[v]) if (*e != par[v]) {
	    par[*e] = v;
	    que.push_back(*e);

	    if (v == 0) nxt[*e] = v;
	    else nxt[*e] = (A[nxt[v]] <= A[v]? nxt[v]: v);
	}
    }

    LL ans = 0;
    REP (i_, N) {
	int v = que[N-1-i_];
	if (B[v] != C[v]) {
	    D[v][B[v]]++;
	}
	int g = min(D[v][0], D[v][1]);
	ans += A[v] * g * 2;
	D[v][0] -= g;
	D[v][1] -= g;
	if (D[v][0] || D[v][1]) {
	    D[nxt[v]][0] += D[v][0];
	    D[nxt[v]][1] += D[v][1];
	}
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}