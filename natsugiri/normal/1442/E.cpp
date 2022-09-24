#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

int N;
VI G[200011];
int A[200011];

int par[200001];
VI que;
int dpB[200011];
int dpW[200011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) G[i].clear();
    REP (i, N) scanf("%d", A+i);

    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    que.clear();
    que.push_back(0);
    REP (i, N) {
	int v = que[i];
	EACH (e, G[v]) if (*e != par[v]) {
	    par[*e] = v;
	    que.push_back(*e);
	}
    }

    int ans = 0;
    REP (i, N) {
	int v = que[N-1-i];

	int bb[3] = {0, 0, 0};
	int ww[3] = {0, 0, 0};

	EACH (e, G[v]) if (*e != par[v]) {
	    bb[0] = dpB[*e];
	    ww[0] = dpW[*e];
	    sort(bb, bb+3);
	    sort(ww, ww+3);
	}

	amax(ans, ww[2] + bb[2]);

	if (A[v] == 0) {
	    amax(ans, bb[1] - 1 + bb[2]);
	    amax(ans, ww[1] - 1 + ww[2]);
	    dpW[v] = ww[2];
	    dpB[v] = bb[2];
	}

	if (A[v] == 1) {
	    amax(ans, bb[1] + 1 + bb[2]);
	    amax(ans, ww[1] - 1 + ww[2]);

	    dpW[v] = max(ww[2], 1 + bb[2]);
	    dpB[v] = 0;
	}

	if (A[v] == 2) {
	    amax(ans, ww[1] + 1 + ww[2]);
	    amax(ans, bb[1] - 1 + bb[2]);

	    dpW[v] = 0;
	    dpB[v] = max(bb[2], 1 + ww[2]);
	}
    }

    ans = (ans + 2) / 2;
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}