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

int N, P, L, R;

void MAIN() {
    scanf("%d%d%d%d", &N, &P, &L, &R);

    int ans = 0;
    if (abs(P-L) < abs(P-R)) {
	if (1 < L) {
	    ans += abs(P-L);
	    ans++;
	    P = L;
	}
	if (R < N) {
	    ans += abs(P-R);
	    ans++;
	    P = R;
	}
    } else {
	if (R < N) {
	    ans += abs(P-R);
	    ans++;
	    P = R;
	}
	if (1 < L) {
	    ans += abs(P-L);
	    ans++;
	    P = L;
	}
    }

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}