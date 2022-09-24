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

LL N;
LL S;

bool ok(LL mid) {
    LL sum = 1;
    LL depth = 1;
    LL cur = 1;
    LL rest = N - 1;
    while (rest) {
	depth++;
	cur *= mid;
	LL g = min(rest, cur);
	sum += depth * g;
	rest -= g;
    }
    return sum <= S;
}

const int MAXN = 100011;
int P[MAXN];
int D[MAXN];
int deg[MAXN];
VI F[MAXN];

void MAIN() {
    scanf("%lld%lld", &N, &S);

#ifdef LOCAL
    N = 2000;
    S = N * (N + 1) / 2 / 2;
#endif

    if (N+N-1 > S || N*(N+1)/2 < S) {
	puts("No");
	return;
    }

    int lo = 0, hi = N;
    while (hi - lo > 1) {
	int mid = (lo + hi) / 2;
	(ok(mid)? hi: lo) = mid;
    }

    puts("Yes");
    P[0] = -1;
    D[0] = 1;
    for (int i=1; i<N; i++) {
	deg[i-1] = 1;
	P[i] = i-1;
	D[i] = i+1;
    }
    REP (i, N) F[D[i]].push_back(i);

    LL cur = N * (N+1) / 2;
    for (int i=N-1; i>0 && cur > S; i--) {

	if (deg[i]) continue;
	deg[P[i]]--;
	cur -= D[i];
	P[i] = -2;

	for (int d=max(1LL, S-cur-1); d<=N; d++) {
//	    if (cur + d + 1 < S) continue;
	    while (!F[d].empty()) {
		int v = F[d].back();
		if (D[v] != d || deg[v] >= hi) {
		    F[d].pop_back();
		    continue;
		}

		P[i] = v;
		D[i] = d+1;
		cur += d+1;
		deg[v]++;
		F[d+1].push_back(i);
		goto OUT;
	    }
	}
OUT:;

    }

    REP (i, N) P[i]++;
    rprintf("%d", P+1, P+N);
    eprintf("%lld %lld %d\n", cur, S, hi);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}