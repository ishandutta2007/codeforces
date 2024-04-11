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

int N, M, K;
LL X, S;
LL A[200111];
LL B[200111];
LL C[200111];
LL D[200111];

int main() {
    scanf("%d%d%d", &N, &M, &K);
    scanf("%lld%lld", &X, &S);
    REP (i, M) scanf("%lld", A+i);
    REP (i, M) scanf("%lld", B+i);
    REP (i, K) scanf("%lld", C+i);
    REP (i, K) scanf("%lld", D+i);


    LL ans = (LL)N * X;
    REP (i, K) if (D[i] <= S) {
	LL t = min((LL)N, C[i]);
	LL tmp = (N - t) * X;
	amin(ans, tmp);
    }
    REP (i, M) {
	if (B[i] <= S) {
	    LL rest = S - B[i];
	    int pos = upper_bound(D, D+K, rest) - D;

	    LL c;
	    if (pos > 0) {
		c = C[pos - 1];
	    } else {
		c = 0;
	    }
	    LL t = min((LL)N, c);
	    LL tmp = (N - t) * A[i];
	    amin(ans, tmp);
	}
    }

    printf("%lld\n", ans);

    return 0;
}