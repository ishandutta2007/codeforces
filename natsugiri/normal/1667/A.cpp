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
LL A[5111];
LL B[5111];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld", A+i);

    LL ans = 1LL<<60;
    REP (s, N) {
	LL tmp = 0;
	B[s] = 0;
	for (int i=s+1; i<N; i++) {
	    LL k = B[i-1] / A[i];
	    while (A[i] * k <= B[i-1]) k++;
	    B[i] = A[i] * k;
	    tmp += k;
	}
	for (int i=s-1; i>=0; i--) {
	    // A[i] * k < B[i+1];
	    LL k = B[i+1] / A[i] + 1;
	    while (A[i] * k >= B[i+1]) k--;
	    B[i] = A[i] * k;
	    assert(k <= 0);
	    tmp += abs(k);
	}
	
	amin(ans, tmp);
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}