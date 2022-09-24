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
LL K;
int H[200011];

void MAIN() {
    scanf("%d%lld", &N, &K);
    REP (i, N) scanf("%d", H+i);
    sort(H, H+N);
    int h = H[0];
    REP (i, N) H[i] -= h;

    int prv = 0;
    LL ans = 0;
    LL has = 0;

    REP (i, N) {
	LL w = H[i] - prv;
	LL t = N-i;
	REP (x, w) {
	    if (has + t > K) {
		ans++;
		has = t;
	    } else {
		has += t;
	    }
	}
	prv = H[i];
    }

    if (has) ans++;

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}