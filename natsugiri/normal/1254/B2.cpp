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
LL A[1000011];
LL sums[1000011];

const LL INF = 1LL<<60;

LL solve(LL K) {
    if (K <= 1) return INF;

    LL cur = 0;
    LL cost = 0;
    vector<pair<LL, LL> > v;
    REP (i, N) {
	LL g = min(A[i], K - cur);
	if (g) {
	    v.emplace_back(g, i);
	    if (cur + g == K) {
		LL c = 0;
		LL mid = 0;
		EACH (e, v) {
		    c += e->first;
		    if (c*2 >= K) {
			mid = e->second;
			break;
		    }
		}

		EACH (e, v) {
		    cost += e->first * (abs(e->second - mid));
		}
		cur = (A[i]-g) % K;
		v.clear();
		if (cur) v.emplace_back(cur, i);
	    } else {
		assert(A[i] == g);
		cur += g;
	    }
	}
    }
    //eprintf("%lld %lld\n", cost, K);
    return cost;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld", A+i);
    LL sum = 0;
    REP (i, N) sum += A[i];
    if (sum <= 1) {
	puts("-1");
	return;
    }

    LL ans = INF;
    LL c = sum;
    for (LL k=2; k*k<=c; k++) if (c%k == 0) {
	amin(ans, solve(k));
	while (c % k == 0) c /= k;
    }
    if (c > 1) amin(ans, solve(c));

    if (ans == INF) puts("-1");
    else printf("%lld\n", ans);

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}