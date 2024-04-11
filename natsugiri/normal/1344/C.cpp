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

int N, M;
VI G[200011];
int deg[200011];
char ans[200011];
int dp1[200011];
int dp2[200011];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	deg[y]++;
    }

    VI ord;
    ord.reserve(N);
    REP (i, N) if (deg[i] == 0) ord.push_back(i);
    for (int i=0; i<(int)ord.size(); i++) {
	int v = ord[i];
	EACH (e, G[v]) {
	    deg[*e]--;
	    if (deg[*e] == 0) ord.push_back(*e);
	}
    }

    if ((int)ord.size() != N) {
	puts("-1");
    } else {
	// ----->
	REP (i, N) dp1[i] = i;
	REP (i, N) {
	    int v = ord[i];
	    EACH (e, G[v]) amin(dp1[*e], dp1[v]);
	}
	// <-----
	REP (i, N) dp2[i] = i;
	REP (i, N) {
	    int v = ord[N-1-i];
	    EACH (e, G[v]) amin(dp2[v], dp2[*e]);
	}

	REP (i, N) {
	    if (dp1[i] == i && dp2[i] == i) ans[i] = 'A';
	    else ans[i] = 'E';
	}
	printf("%d\n", (int)count(ans, ans+N, 'A'));
	puts(ans);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}