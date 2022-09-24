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
int K;
int A[10011];

int OR(int i, int j) {
    printf("or %d %d\n", i+1, j+1);
    fflush(stdout);

    int ret;
    scanf("%d", &ret);
    return ret;
}
int AND(int i, int j) {
    printf("and %d %d\n", i+1, j+1);
    fflush(stdout);

    int ret;
    scanf("%d", &ret);
    return ret;
}

void MAIN() {
    scanf("%d%d", &N, &K);

    int x[3] = {
	OR(0, 1),
	OR(1, 2),
	OR(2, 0),
    };
    int y[3] = {
	AND(0, 1),
	AND(1, 2),
	AND(2, 0),
    };

    REP (t, 30) {
	int o0 = x[0]>>t&1;
	int o1 = x[1]>>t&1;
	int o2 = x[2]>>t&1;
	int a0 = y[0]>>t&1;
	int a1 = y[1]>>t&1;
	int a2 = y[2]>>t&1;

	int p0, p1, p2;
	if (o0 == 0 && o1 == 0 && o2 == 0) {
	    p0 = p1 = p2 = 0;
	} else if (a0 == 1 && a1 == 1 && a2 == 1) {
	    p0 = p1 = p2 = 1;
	} else if (o0 + o1 + o2 == 2) {
	    p0 = p1 = p2 = 0;
	    if (o0 == 0) p2 = 1;
	    if (o1 == 0) p0 = 1;
	    if (o2 == 0) p1 = 1;
	} else if (a0 + a1 + a2 == 1) {
	    p0 = p1 = p2 = 1;
	    if (a0 == 1) p2 = 0;
	    if (a1 == 1) p0 = 0;
	    if (a2 == 1) p1 = 0;
	} else {
	    assert(false);
	    p0 = p1 = p2 = 0;
	}

	A[0] |= p0 << t;
	A[1] |= p1 << t;
	A[2] |= p2 << t;
    }
    for (int i=3; i<N; i++) {
	int oo = OR(0, i);
	int aa = AND(0, i);
	A[i] = oo ^ aa ^ A[0];
    }

    sort(A, A+N);
    int ans = A[K-1];
    printf("finish %d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}