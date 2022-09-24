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

const LL INF = 1LL<<60;
LL safe_mul(LL x, LL y) {
    if (x == 0 || y == 0) return 0;
    if (x >= INF/y) return INF+1;
    return x * y;

}

int N;
LL K;
vector<pair<LL, int> > P;

void MAIN() {
    scanf("%d%lld", &N, &K);
//    N = 200000; K = 1;
    REP (i, N) {
	int x;
	scanf("%d", &x);
//	x = 2;
	if (!P.empty() && P.back().first == 1 && x == 1) {
	    P.back().second++;
	} else {
	    P.emplace_back(x, 1);
	}
    }

    LL ans = 0;
    REP (i, P.size()) {
	REP (k, P[i].second) {
	    LL p = 1, s = 0;
	    for (int j=i; j<(int)P.size(); j++) {
		if (P[j].first == 1) {
		    int rest;
		    if (j == i) {
			rest = P[j].second - k;
		    } else {
			rest = P[j].second;
		    }
		    if (p > s*K && p <= (s+rest)*K && p%K == 0) {
			ans++;
		    }
		    s += rest;
		} else {
		    p = safe_mul(p, P[j].first);
		    if (p >= INF) break;
		    s += P[j].first;

		    if (p == s*K) {
			ans++;
		    }
		}
//		eprintf("%lld %lld\n", p, s);
	    }
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