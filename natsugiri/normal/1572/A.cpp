#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
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
VI R[200011];
int deg[200011];
int D[200011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	G[i].clear();
	R[i].clear();
    }

    memset(deg, 0, sizeof (int) * N);

    REP (i, N) {
	int len;
	scanf("%d", &len);
	deg[i] = len;
	REP (j, len) {
	    int x;
	    scanf("%d", &x);
	    x--;
	    G[x].push_back(i);
	    R[i].push_back(x);
	}
    }

    memset(D, 0x3f, sizeof (int) * N);
    VI que;
    REP (i, N) if (deg[i] == 0) {
	D[i] = 1;
	que.push_back(i);
    }

    for (int i=0; i<(int)que.size(); i++) {
	int v = que[i];
	D[v] = 1;
	EACH (e, R[v]) {
	    if (*e < v) amax(D[v], D[*e]);
	    else amax(D[v], D[*e]+1);
	}

	EACH (e, G[v]) {
	    deg[*e]--;
	    if (deg[*e] == 0) {
		que.push_back(*e);
	    }
	}
    }

    int ans = *max_element(D, D+N);
    if (ans == 0x3f3f3f3f) {
	puts("-1");
    } else {
	printf("%d\n", ans);
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}