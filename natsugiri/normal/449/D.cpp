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

const LL MOD = 1e9+7;
LL powMod(LL x, LL y, LL m) {
    LL r = 1;
    for (; y; y>>=1) {
	if (y & 1) r = r * x % m;
	x = x * x % m;
    }
    return r;
}

int N;
int A[1000111];
int Z[1<<20];

int main() {
    scanf("%d", &N);
    REP (i, N) {
	scanf("%d", A+i);
	Z[A[i]]++;
    }

    REP (t, 20) REP (i, 1<<20) if (~i & (1<<t)) Z[i] += Z[i|(1<<t)];

    LL ans = powMod(2, N, MOD);
    REP (i, 1<<20) if (i) {
	int c = __builtin_popcount(i);
	if (c & 1) ans -= powMod(2, Z[i], MOD);
	else ans += powMod(2, Z[i], MOD);
    }

    ans %= MOD;
    if (ans < 0) ans += MOD;
    printf("%lld\n", ans);

    return 0;
}