#include<set>
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

int N, C;
int A[100111];
LL dp[100111];

void MAIN() {
    scanf("%d%d", &N, &C);
    REP (i, N) scanf("%d", A+i);

    multiset<int> se;
    LL cur = 0;
    REP (i, N) {
	dp[i+1] = dp[i] + A[i];
	se.insert(A[i]);
	cur += A[i];
	if (i >= C) {
	    se.erase(se.find(A[i-C]));
	    cur -= A[i-C];
	}
	if (i+1 >= C) {
	    amin(dp[i+1], dp[i-C+1] + cur - *se.begin());
	}
//	eprintf("%lld\n" , cur);
    }

    printf("%lld\n", dp[N]);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}