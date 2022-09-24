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
LL A[1000011];
LL Pistol, Laser, AWP;
LL D;

LL dp1[1000011];
LL dp2[1000011];

void MAIN() {
    scanf("%d", &N);
    scanf("%lld%lld%lld%lld", &Pistol, &Laser, &AWP, &D);
    REP (i, N) scanf("%lld", A+i);

    memset(dp1, 0x3f, sizeof dp1);
    memset(dp2, 0x3f, sizeof dp2);
    dp1[0] = -D;

    REP (i, N) {
	amin(dp1[i+1], D + dp1[i] + A[i] * Pistol + AWP);

	if (i+2 <= N) {
	    LL cst = dp1[i];
	    cst += D + min((A[i]+1) * Pistol, Laser);
	    cst += D + min((A[i+1]+1) * Pistol, Laser);
	    cst += D + Pistol;
	    cst += D + Pistol;
	    amin(dp1[i+2], cst);
	}

	if (i || i+2 <= N) { // always true;
	    LL cst = dp1[i];
	    cst += D + min((A[i]+1) * Pistol, Laser);
	    cst += D;
	    cst += D + Pistol;
	    amin(dp1[i+1], cst);
	}

	if (i+2 <= N) {
	    LL cst = 0;
	    cst += D + min((A[i]+1) * Pistol, Laser);
	    cst += D + Pistol;
	    // start dp2;
	    amin(dp2[i+1], cst + dp1[i]);
	    // keep dp2;
	    amin(dp2[i+1], cst + dp2[i]);

	    cst = 0;
	    cst += D + A[i] * Pistol + AWP;
	    cst += D;
	    amin(dp2[i+1], cst + dp2[i]);
	}
    }

    LL ans = dp1[N];
    if (N >= 2) {
	int i = N-1;
	LL cst = 0;
	cst += D + min((A[i]+1) * Pistol, Laser);
	cst += D;
	cst += D + Pistol;
	amin(ans, cst + dp2[i]);

	cst = 0;
	cst += D + A[i] * Pistol + AWP;
	amin(ans, cst + dp2[i]);
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}