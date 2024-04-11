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

LL D, R;
int N;

inline LL sq(LL x) { return x * x; }
inline LL sqsum(LL x, LL y) { return x * x + y * y; }


void MAIN() {

    scanf("%lld%lld%d", &R, &D, &N);

    int ans = 0;
    REP (i, N) {
	LL x, y, r;
	scanf("%lld%lld%lld", &x, &y, &r);
	if (r*2 > D) continue;
	LL s = sqsum(x, y);
	if (s <= sq(r)) continue;
	if (s > sq(R-r) || s < sq((R-D)+r)) continue;
	ans++;
    }

    printf("%d\n", ans);

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}