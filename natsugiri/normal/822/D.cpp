#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

const LL MOD =  1e9+7;
int T, L, R;
LL F[5000011];

void MAIN() {
    scanf("%d%d%d", &T, &L, &R);

    memset(F, 0x3f, sizeof F);
    F[1] = 0;
    for (int i=1; i<=R; i++) {
	LL s = 1;
	for (int j=i+i, d=2; j<=R; j+=i, d++) {
//	    amin(F[j], F[i] + (LL)d * (d-1) / 2 * i);
	    amin(F[j], F[i] + s * i);
	    s += d;
	}
    }

    LL ans = 0;
    LL tt = 1;
    for (int i=L; i<=R; i++) {
	(ans += F[i] % MOD * tt) %= MOD;
	(tt *= T) %= MOD;

    }
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}