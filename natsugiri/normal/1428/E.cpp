#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<queue>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N, K;
LL A[100011];

int D[100011];

LL calc(LL a, LL d) {
    assert(a >= d);
    LL q = a / d, r = a % d;
    LL ret = 0;
    ret += q * q * (d - r);
    ret += (q+1) * (q+1) * r;
    return ret;
}

void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, N) scanf("%lld", A+i);
    sort(A, A+N);

    priority_queue<pair<LL, int> > Q;

    int cnt = N;
    LL ans = 0;
    REP (i, N) {
	D[i] = 1;
	LL cur = calc(A[i], D[i]);
	ans += cur;
	if (A[i] > D[i]) {
	    LL nxt = calc(A[i], D[i]+1);
	    Q.emplace(cur - nxt, i);
	}
    }

    while (cnt < K) {
	LL diff = Q.top().first;
	int idx = Q.top().second;
	Q.pop();
	ans -= diff;
	D[idx]++;
	cnt++;
	if (A[idx] > D[idx]) {
	    LL cur = calc(A[idx], D[idx]);
	    LL nxt = calc(A[idx], D[idx]+1);
	    Q.emplace(cur - nxt, idx);
	}
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}