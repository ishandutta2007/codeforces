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

int query(int a, int b) {
    printf("? %d %d\n", a, b);
    fflush(stdout);
#ifdef LOCAL
    int x = 1e9;
    int ret = __gcd(x + a, x + b);
    printf("ret = %d\n", ret);
    return ret;
#endif
    int g;
    scanf("%d", &g);
    return g;
}

void MAIN() {
    LL x = 0;
    for (LL a=1, s=0; s<30; a+=a, s++) {
	LL q = query(a-x, a*3-x);

	if (~q >> s & 1) {
	    x |= 1LL<<s;
	}
    }

    printf("! %lld\n", x);
    fflush(stdout);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}