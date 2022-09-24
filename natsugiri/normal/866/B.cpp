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

int N, S;
LL D[100111], A[100111], B[100111];
pair<LL, LL> P[100111];
LL M;
LL base;

LL calc(LL x) {
    // type A: x
    // type B: M-x

    LL sa = x * S;
    LL sb = (M-x) * S;
    LL ret = base;
    int l=0, r=N-1;

    if (sa < 0 || sb < 0) return base;

    while (l <= r && P[l].first <= 0 && P[l].second <= sa) {
	sa -= P[l].second;
	l++;
    }

    while (l <= r && P[r].first >= 0 && P[r].second <= sb) {
	ret += P[r].first * P[r].second;
	sb -= P[r].second;
	r--;
    }

    while (l < r && P[l].second <= sa) {
	sa -= P[l].second;
	l++;
    }

    while (l < r && P[r].second <= sb) {
	ret += P[r].first * P[r].second;
	sb -= P[r].second;
	r--;
    }

    if (l == r) {
	LL d = P[l].second;
	if (P[l].first <= 0) {
	    LL g = min(sa, d);
	    d -= g;
	    sa -= g;
	} else {
	    LL g = min(sb, d);
	    ret += P[l].first * g;
	    d -= g;
	    sb -= g;
	}

	{
	    LL g = min(sa, d);
	    d -= g;
	    sa -= g;
	}
	{
	    LL g = min(sb, d);
	    ret += P[l].first * g;
	    d -= g;
	    sb -= g;
	}
    }

    return ret;
}

void MAIN() {
    scanf("%d%d", &N, &S);
    REP (i, N) scanf("%lld%lld%lld", D+i, A+i, B+i);

    LL sum = 0;
    LL sumA = 0, sumB = 0;
    REP (i, N) {
	sum += D[i];
	if (A[i] > B[i]) sumA += D[i];
	if (A[i] < B[i]) sumB += D[i];
    }
    M = (sum + S - 1) / S;

    base = 0;

    REP (i, N) {
	base += D[i] * A[i];
	P[i] = make_pair(B[i] - A[i], D[i]);
    }

    sort(P, P+N);

    LL ans = base;

    amax(ans, calc((sumA + S - 1) / S));
    amax(ans, calc(M - (sumB + S - 1) / S));
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}