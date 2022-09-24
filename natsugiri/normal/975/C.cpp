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

const int MAXN = 200011;
int N, Q;
LL A[MAXN];
LL sums[MAXN];

void MAIN() {
    scanf("%d%d", &N, &Q);
    REP (i, N) scanf("%lld", A+i);
    REP (i, N) sums[i+1] = sums[i] + A[i];

    LL cur = 0;

    REP ($, Q) {
	LL tmp;
	scanf("%lld", &tmp);
	cur += tmp;
	int ans;
	if (cur >= sums[N]) {
	    cur = 0;
	    ans = N;
	} else {
	    int k = upper_bound(sums, sums+N+1, cur) - sums;
	    k--;
	    ans = N - k;
	}
	
	printf("%d\n", ans);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}