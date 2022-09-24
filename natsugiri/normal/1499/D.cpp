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

int factors[20000011];
void init() {
    for (int i=2; i<20000011; i++) {
	assert(factors[i] <= 30);
	if (factors[i]) continue;
	for (int j=i; j<20000011; j+=i) {
	    factors[j]++;
	}
    }
}

LL C, D, X;
LL ans;

void solve(LL h) {
    if ((h + D) % C == 0) {
	LL ab = (h + D) / C;
	// eprintf("[%lld] %lld\n", ab, h);
	assert(1 <= ab);
	assert(ab <= 20000000);
	ans += 1LL<<factors[ab];
    }
}

void MAIN() {
    scanf("%lld%lld%lld", &C, &D, &X);
    ans = 0;
    for (LL i=1; i*i<=X; i++) if (X % i == 0) {
	solve(i);
	if (i * i < X) solve(X/i);
    }

    printf("%lld\n", ans);
}

int main() {
    init();
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}