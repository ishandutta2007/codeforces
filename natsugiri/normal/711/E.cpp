#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }


const LL MOD = 1e6 + 3;
const LL inv2 = (MOD + 1) / 2;


LL powMod(LL x, LL y, LL m) {
    x %= m;
    LL r = 1;
    for (; y; y>>=1) {
	if (y&1) r = r * x % m;
	x = x * x % m;
    }
    return r;
}

LL F(LL x) {
    LL r = 0;
    x >>= 1;
    for (;x ; x>>=1) {
	r += x;
	r %= MOD - 1;
    }
    return r;
}

LL N, K;

int main() {

    scanf("%lld%lld", &N, &K);

    if (N <= 60 && (1ll<<N) < K) {
	puts("1 1");
	return 0;
    }

    LL B = powMod(2, N, MOD);
    LL d = powMod(B, K-1, MOD);

    LL z = 1;
    z = powMod(inv2, F(K-1), MOD);
    d = d * z % MOD;


    LL g = 0;
    if (K >= 2 * MOD) g = 0;
    else {
	g = 1;
	REP (i, K-1) {
	    g = g * (B - i - 1) % MOD;
	}
	g = (g + MOD) * z % MOD;
    }

    printf("%lld %lld\n",
	    (d - g + MOD) % MOD,
	    d);


    return 0;
}