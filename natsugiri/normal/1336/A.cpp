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

int N, K;
VI G[200011];
int par[200011];
int sz[200011];
int depth[200011];
int B[200011];

void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }
    VI que;
    que.reserve(N);
    que.push_back(0);
    REP (i_, N) {
	int v = que[i_];
	EACH (e, G[v]) if (*e != par[v]) {
	    par[*e] = v;
	    depth[*e] = depth[v] + 1;
	    que.push_back(*e);
	}
    }
    REP (i_, N) {
	int v = que[N-1-i_];
	sz[v] = 1;
	EACH (e, G[v]) if (*e != par[v]) {
	    sz[v] += sz[*e];
	}
    }

    LL ans = 0;
    REP (i, N) B[i] = depth[i] - sz[i] + 1;
    sort(B, B+N);
    REP (i, K) {
	ans += B[N-1-i];
    }
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}