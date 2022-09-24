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

LL N, M, K;

bool yes = false;;
void P(LL x) {
    puts("YES");
    printf("0 0\n");
    printf("%lld 0\n", x);
    printf("0 %lld\n", N*M*2/K/x);
    yes = true;
}

void MAIN() {
    scanf("%lld%lld%lld", &N, &M, &K);
    LL g = __gcd(N*M, K);
    if (g == K) {
	LL A = N*M/K;
	LL x = __gcd(N, A);
	LL y = __gcd(M, A);
	if (false) {
	} else if (A/x*2 <= M) {
	    P(x);
	} else if (A/y*2 <= N) {
	    P(A/y*2);
	} else if (x*2 <= N && A/x <= M) {
	    P(x*2);
	} else if (y*2 <= M && A/y <= N) {
	    P(A/y);
	}
    } else if (g*2 == K) {
	LL A = N*M/g;
	LL x = __gcd(N, A);
	LL y = __gcd(M, A);
	if (false) {
	} else if (A/x <= M) {
	    P(x);
	} else if (A/y <= N) {
	    P(A/y);
	}
    }

    if (!yes) puts("NO");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}