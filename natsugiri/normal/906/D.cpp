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

LL phi(LL n) {
    if (n==0) return 0;
    LL r=n;
    for (LL i=2; i*i<=n; i++) {
	if (n%i==0) {
	    r-=r/i;
	    for (;n%i==0;) n/=i;
	}
    }
    if (n>1) r-=r/n;
    return r;
}

LL powMod2(LL x, LL y, LL mod, LL low) {
    if (x >= low) x = (x-low) % mod + low;
    LL r = 1;
    for (; y; y>>=1) {
	if (y & 1) {
	    r *= x;
	    if (r >= low) r = (r-low) % mod + low;
	}
	x *= x;
	if (x >= low) x = (x-low) % mod + low;
    }
    return r;
}


int N;
LL MOD;
int A[100111];

LL MODA[100111];
int L, R;
int Q;

LL rec(int pos, int mod_pos, LL low) {
    LL mod = MODA[mod_pos];
    if (mod == 1) {
	if (A[pos] >= low) return low;
	else return A[pos];
    }
    if (pos == R-1) {
	if (A[pos] >= low) return (A[pos] - low) % mod + low;
	else return A[pos];
    }

    LL e = rec(pos+1, mod_pos+1, mod);
    return powMod2(A[pos], e, mod, low);
}

void MAIN() {
    scanf("%d%lld", &N, &MOD);
    REP (i, N) scanf("%d", A+i);

    MODA[0] = MOD;
    for (int i=0; ; i++) {
	MODA[i+1] = phi(MODA[i]);
	if (MODA[i+1] == 1) break;
    }

    scanf("%d", &Q);
    REP ($, Q) {
	scanf("%d%d", &L, &R);
	L--;
	LL ans = rec(L, 0, 0);
	ans %= MOD;
	if (ans < 0) ans += MOD;
	printf("%lld\n", ans);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}