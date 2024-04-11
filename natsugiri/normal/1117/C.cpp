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

LL SX, SY, TX, TY;
int N;
char S[100011];

LL DX, DY;

bool ok(LL mid) {
    LL cx = DX * mid;
    LL cy = DY * mid;
    return abs(TX - cx) + abs(TY - cy) <= N * mid;
}

void MAIN() {
    scanf("%lld%lld%lld%lld", &SX, &SY, &TX, &TY);
    TX -= SX;
    TY -= SY;
    SX = SY = 0;
    scanf("%d%s", &N, S);

    if (TX == 0 && TY == 0) {
	puts("0");
	return;
    }

    REP (i, N) {
	if (S[i] == 'U') DY++;
	if (S[i] == 'D') DY--;
	if (S[i] == 'R') DX++;
	if (S[i] == 'L') DX--;
    }

    LL lo = 0, hi = 1LL<<40;

    if (!ok(hi)) {
	puts("-1");

    } else {
	while (hi - lo > 1) {
	    LL mid = (lo + hi) / 2;
	    (ok(mid)? hi: lo) = mid;
	}

	LL cx = DX * lo;
	LL cy = DY * lo;
	LL ans = N * lo;
	REP (i, N) {
	    if (S[i] == 'U') cy++;
	    if (S[i] == 'D') cy--;
	    if (S[i] == 'R') cx++;
	    if (S[i] == 'L') cx--;
	    ans++;

	    if (abs(TX - cx) + abs(TY - cy) <= ans) {
		printf("%lld\n", ans);
		return;
	    }
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}