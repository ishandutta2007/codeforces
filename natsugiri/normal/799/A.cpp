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

LL N, T, K, D;
void MAIN() {
    scanf("%lld%lld%lld%lld", &N, &T, &K, &D);

    LL t1 = (N + K - 1) / K * T;

    LL lo = 0, hi = t1 + 1;
    while (hi - lo > 1) {
	LL mid = (hi + lo) / 2;
	LL cnt = mid / T * K;
	if (mid >= D) { cnt += (mid - D) / T * K; }

	(cnt >= N ? hi: lo) = mid;
    }

    puts(hi < t1 ? "YES": "NO");
//    eprintf("%lld %lld\n", t1, hi);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}