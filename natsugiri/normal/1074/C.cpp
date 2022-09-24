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

int N;
pair<LL, LL> P[300011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld%lld", &P[i].first, &P[i].second);

    LL ans = 0;
    REP (a, 2) {
	REP (b, 2) {
	    sort(P, P+N);
	    LL x_low = P[0].first, y_low = P[0].second;
	    REP (i, N) {
		if (x_low < P[i].first && y_low < P[i].second) {
		    LL tmp = (P[i].first - x_low + P[i].second - y_low) * 2;
		    amax(ans, tmp);
		}
		amin(x_low, P[i].first);
		amin(y_low, P[i].second);
	    }
	    REP (i, N) P[i].first = -P[i].first;
	}
	REP (i, N) P[i].second = -P[i].second;
    }

    LL ansx;
    {
	LL x_low, x_high, y_low, y_high;
	x_low = x_high = P[0].first;
	y_low = y_high = P[0].second;
	REP (i, N) {
	    amin(x_low, P[i].first);
	    amax(x_high, P[i].first);
	    amin(y_low, P[i].second);
	    amax(y_high, P[i].second);
	}
	ansx = (x_high - x_low + y_high - y_low) * 2;
    }

    for (int i=3; i<=N; i++) {
	LL t = (i == 3? ans: ansx);
	printf("%lld%c", t, " \n"[i==N]);
    }

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}