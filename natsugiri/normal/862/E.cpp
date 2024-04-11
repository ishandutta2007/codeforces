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

int N, M, Q;
LL A[100111];
LL B[100111];
LL sumB[100111];
vector<LL> Z;
void output(LL g) {
    int k = lower_bound(Z.begin(), Z.end(), g) - Z.begin();

    LL ans = 1LL<<60;
    if (k < (int)Z.size()) amin(ans, abs(g - Z[k]));
    if (k) amin(ans, abs(g - Z[k-1]));
    printf("%lld\n", ans);
}


void MAIN() {
    scanf("%d%d%d", &N, &M, &Q);
    REP (i, N) scanf("%lld", A+i);
    REP (i, M) scanf("%lld", B+i);

    LL sumA = 0;
    REP (i, N) {
	if (i & 1) sumA -= A[i];
	else sumA += A[i];
    }

    REP (i, M) sumB[i+1] = B[i] - sumB[i];
    for (int i=N; i<=M; i++) {
	if (N & 1) Z.push_back(sumB[i] + sumB[i-N]);
	else Z.push_back(-sumB[i] + sumB[i-N]);
    }

    sort(Z.begin(), Z.end());
    
    output(sumA);
    REP ($, Q) {
	int l, r;
	LL x;
	scanf("%d%d%lld", &l, &r, &x);
	l--;
	if ((r-l)%2) {
	    if (l & 1) sumA -= x;
	    else sumA += x;
	}
	output(sumA);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}