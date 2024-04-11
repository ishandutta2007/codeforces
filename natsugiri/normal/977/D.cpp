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
struct Data {
    LL a;
    int c2, c3;

    bool operator<(const Data &y) const {
	return c2 != y.c2 ? c2 < y.c2 :
	    c3 > y.c3;
    }
} D[222];


void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	LL x;
	scanf("%lld", &x);
	D[i].a = x;
	D[i].c2 = D[i].c3 = 0;
	while (x % 2 == 0) {
	    D[i].c2++;
	    x /= 2;
	}
	while (x % 3 == 0) {
	    D[i].c3++;
	    x /= 3;
	}
    }

    sort(D, D+N);

    REP (i, N) printf("%lld%c", D[i].a, " \n"[i==N-1]);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}