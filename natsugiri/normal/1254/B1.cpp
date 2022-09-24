#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

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

int N;
int A[100011];
int num;
int pos[100011];

const LL INF = 1LL<<60;
LL sums[100011];

LL solve(int K) {
    if (K <= 1) return INF;
    int base = 0;
    LL cost = 0;
    while (base < num) {
	LL p = pos[base+K/2];
	cost += sums[base+K] - sums[base+K/2] - p*(K-K/2);
	cost += p*(K/2) - (sums[base+K/2] - sums[base]);
	base += K;
    }
    return cost;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    num = 0;
    REP (i, N) num += A[i];
    int cnt = 0;
    REP (i, N) {
	if (A[i]) {
	    pos[cnt] = i;
	    cnt++;
	    sums[cnt] = sums[cnt-1] + i;
	}
    }

    if (num <= 1) {
	puts("-1");
	return;
    }

    LL ans = INF;
    for (int k=1; k*k<=num; k++) if (num % k == 0) {
	amin(ans, solve(k));
	amin(ans, solve(num / k));
    }
    if (ans == INF) puts("-1");
    else printf("%lld\n", ans);

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}