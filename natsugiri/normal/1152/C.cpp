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

LL gcd(LL x, LL y) {
    while (1) {
	if (x) y %= x; else return y;
	if (y) x %= y; else return x;
    }
}
LL lcm(LL x, LL y) {
    return x / gcd(x, y) * y;
}

LL A, B;
LL best = 1LL<<62;
LL best_k;
void solve(LL i) {
    LL k;
    if (A % i == 0) k = 0;
    else k = i - A % i;
    assert((A+k) % i == 0);
    assert((B+k) % i == 0);
    LL l = lcm(A+k, B+k);
    if (best > l || (best == l && best_k > k)) {
	best = l;
	best_k = k;
    }
}

void MAIN() {
    scanf("%lld%lld", &A, &B);

    if (A == B) {
	puts("0");
	return;
    }
    if (A > B) swap(A, B);

    LL D = B - A;
    for (LL i=1; i*i<=D; i++) {
	if (D % i == 0) {
	    solve(i);
	    solve(D/i);
	}
    }

    printf("%lld\n", best_k);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}