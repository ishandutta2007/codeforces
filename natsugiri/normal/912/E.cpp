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
const LL INF = 1e18;

int N;
int P[16];
LL limit[16];
LL K;

void rec(int i, int n, LL val, vector<LL> &v) {
    if (i == n) {
	v.push_back(val);
	return;
    }
    for (;;) {
	rec(i+1, n, val, v);
	if (val > limit[i]) break;
	val *= P[i];
    }
}


void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", P+i);
    scanf("%lld", &K);

    if (N == 1) {
	LL ans = 1;
	REP (i, K-1) ans *= P[0];
	printf("%lld\n", ans);
    } else {
	sort(P, P+N);
	REP (i, min(N, 2)) swap(P[i], P[N-1-i]);

	REP (i, N) limit[i] = INF / P[i];

	int NX = N/2;
	vector<LL> v0, v1;
	rec(0, NX, 1, v0);
	rec(NX, N, 1, v1);

	sort(v0.begin(), v0.end());
	sort(v1.begin(), v1.end());

	LL lo = 0, hi = 1e18;
	while (hi - lo > 1) {
	    LL mid = (lo + hi) / 2;
	    LL cnt = 0;
	    EACH (e, v0) {
		if (*e > mid) break;
		cnt += upper_bound(v1.begin(), v1.end(), mid / *e) - v1.begin();
	    }

	    if (cnt < K) lo = mid;
	    else hi = mid;
	}

	printf("%lld\n", hi);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}