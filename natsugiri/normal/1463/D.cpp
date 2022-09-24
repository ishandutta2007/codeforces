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
int B[200011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", B+i);
    sort(B, B+N);

    int v = 2*N;
    int pool = 0, cost = 0;
    for (int i=N; i--;) {
	while (B[i] < v) {
	    if (pool) pool--;
	    else cost++;
	    v--;
	}

	pool++;
	v--;
    }

    int minX = cost;

    v = 1;
    pool = 0, cost = 0;
    REP (i, N) {
	while (v < B[i]) {
	    if (pool) pool--;
	    else cost++;
	    v++;
	}
	pool++;
	v++;
    }
    int maxX = N - cost;

    printf("%d\n", maxX-minX+1);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}