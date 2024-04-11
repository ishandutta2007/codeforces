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
int A[5011];
int X;
LL P[5011];
LL ans[5011];
const LL INF = 1LL<<60;

void MAIN() {
    scanf("%d%d", &N, &X);
    REP (i, N) scanf("%d", A+i);
    REP (i, N+1) P[i] = -INF;

    REP (i, N) {
	LL sum = 0;
	for (int j=i; j<N; j++) {
	    sum += A[j];
	    amax(P[j-i+1], sum);
	}
    }

    REP (k, N+1) ans[k] = 0;
    REP (a, N+1) {
	for (int k=0; k<=N; k++) {
	    amax(ans[k], P[a] + (LL)min(a, k) * X);
	}
    }
    rprintf("%lld", ans, ans+N+1);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}