#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

const LL INF = 1LL<<60;
int N, Q;
LL C[31];

void MAIN() {
    scanf("%d%d", &N, &Q);
    REP (i, N) scanf("%lld", C+i);

    REP ($, Q) {
	char op[11];
	int x;
	LL k;

	scanf("%s%d%lld", op, &x, &k);
	if (*op == '1') {
	    C[x] = k;
	} else {
	    LL now = 0, grow = 0;
	    for (int y=0; y<=x; y++) {
		now += C[y];
		grow += ((1LL<<y) - 1) * C[y];
		amin(grow, k);
	    }

	    LL ans = INF;
	    if (now >= k) ans = 0;
	    else {
		k -= now;
		if (grow >= k) amin(ans, k);

		LL cost = 0;

		for (int y=x+1; y<N; y++) {
		    LL rate = 1LL<<(y-x);
		    LL g = min(C[y], k / rate);

		    k -= g * rate;
		    cost += g * (rate - 1);
		    grow += min(k, ((1LL<<x) - 1) * g) * rate;
		    amin(grow, k);


		    if (grow >= k) amin(ans, k + cost);

		    if (C[y] > g) {
			assert(k < grow + rate);
			LL tmp_k = k;
			LL tmp_grow = grow;
			LL tmp_cost = cost;

			while (1) {
			    //eprintf("%lld %lld %lld\n", tmp_k, tmp_grow, rate);
			    if (tmp_k <= tmp_grow) {
				amin(ans, tmp_k + tmp_cost);
				break;
			    }

			    if (tmp_k >= rate / 2) {
				tmp_k -= rate / 2;
				tmp_cost += rate / 2;
				tmp_grow += ((1LL<<x) - 1) * (rate / 2);
				amin(tmp_grow, k);
			    } else {
				tmp_cost++;
			    }
			    rate /= 2;
			}
		    }
		}
	    }

	    if (ans == INF) {
		puts("-1");
	    } else {
		printf("%lld\n", ans);
	    }
	}

    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}