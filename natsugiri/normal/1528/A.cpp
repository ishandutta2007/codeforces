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
VI G[100011];

int L[100011];
int R[100011];

int par[100011];
VI que;

LL hi[100011];
LL lo[100011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) G[i].clear();

    REP (i, N) scanf("%d%d", L+i, R+i);

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

    REP (i, N) {
	int v = que[N-1-i];
	hi[v] = lo[v] = 0;
	EACH (e, G[v]) if (*e != par[v]) {
	    LL tmp = max(
		    abs(R[v] - R[*e]) + hi[*e],
		    abs(R[v] - L[*e]) + lo[*e]);
	    hi[v] += tmp;

	    tmp = max(
		    abs(L[v] - R[*e]) + hi[*e],
		    abs(L[v] - L[*e]) + lo[*e]);
	    lo[v] += tmp;
	}
    }

    LL ans = max(hi[0], lo[0]);
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}