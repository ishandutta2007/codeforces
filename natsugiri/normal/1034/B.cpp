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

LL N, M;

void MAIN() {
    scanf("%lld%lld", &N, &M);
    if (N > M) swap(N, M);
    LL ans;
    if (M <= 2) {
	ans = 0;
    } else if (M == 3) {
	if (N == 1) {
	    ans = 0;
	} else if (N == 2) {
	    ans = 4;
	} else {
	    ans = 8;
	}
    } else if (N == 1) {
	LL q = M/6, r = M%6;
	ans = q*6;
	if (r == 4) ans += 2;
	if (r == 5) ans += 4;
    } else if (N == 2 && M == 7) {
	// A..B..A
	// .AB.BA.
	ans = 12; //// ????????????
    } else {
	ans = M*N;
	if (ans & 1) ans--;
    }
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}