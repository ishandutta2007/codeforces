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

int N, M;
LL tri(LL x) {
    return x * (x-1) / 2;
}

void MAIN() {
    scanf("%d%d", &N, &M);
    LL b1 = tri(N);
    LL b2 = tri((N+1)/2) + tri(N+1-(N+1)/2);
    long double ans = 0;
    REP (i, M) {
	int x, d;
	scanf("%d%d", &x, &d);

	ans += (long double)x * N;
	if (d > 0) {
	    ans += b1 * d;
	} else if (d < 0) {
	    ans += b2 * d;
	}
    }

    printf("%.12f\n", (double)(ans / N));
}


int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}