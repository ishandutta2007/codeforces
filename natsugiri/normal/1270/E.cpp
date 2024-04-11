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

int N;
LL X[1011], Y[1011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld%lld", X+i, Y+i);

    while (1) {
	int cntX = 0;
	REP (i, N) if (X[i] % 2 == 0) cntX++;
	if (cntX == 0) {
	    REP (i, N) X[i]++;
	    cntX = N;
	}

	int cntY = 0;
	REP (i, N) if (Y[i] % 2 == 0) cntY++;
	if (cntY == 0) {
	    REP (i, N) Y[i]++;
	    cntY = N;
	}

	if (cntX == N && cntY == N) {
	    REP (i, N) {
		X[i] /= 2;
		Y[i] /= 2;
	    }
	    continue;
	}

	int ev = 0;
	REP (i, N) {
	    if ((X[i]+Y[i])%2 == 0) ev++;
	}

	if (ev == 0 || ev == N) {
	    REP (i, N) {
		LL tmp = X[i] + Y[i];
		Y[i] = X[i] - Y[i];
		X[i] = tmp;
	    }
	} else {
	    break;
	}
    }

    VI ans;
    REP (i, N) {
	if ((X[i]+Y[i]) % 2 == 0) ans.push_back(i+1);
    }
    printf("%d\n", (int)ans.size());
    rprintf("%d", ans.begin(), ans.end());

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}