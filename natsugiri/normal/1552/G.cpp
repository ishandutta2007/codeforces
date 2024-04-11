#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
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
template<class T> void sort_unique(vector<T> &v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}

int N;
int K;
VI J[10];
LL J_MASK[10];
LL SUMS[11];
VI STK[40];


void MAIN() {
#ifdef LOCALx
    N = 40;
    K = 10;
    REP (i, K-1) {
	REP (t, 4) {
	    J[i].push_back(i*4+t);
	}
    }
    REP (t, 40) J[9].push_back(t+0);

#else
    scanf("%d%d", &N, &K);
    REP (i, K) {
	int len;
	scanf("%d", &len);
	J[i].resize(len);
	REP (j, len) {
	    int x;
	    scanf("%d", &x);
	    J[i][j] = x-1;
	}
    }
#endif

    REP (i, K) {
	EACH (e, J[i]) {
	    STK[*e].push_back(i);
	    J_MASK[i] |= 1LL<<*e;
	}

	SUMS[i+1] = SUMS[i] | J_MASK[i];
    }

    bool yes = true;

    if (N >= 2) {
	REP (i, N) if (STK[i].empty()) {
	    yes = false;
	}
    }

    if (yes) {
	vector<LL> cur, nxt;
	cur.push_back(0);

	REP (t, K) {
	    nxt.clear();
	    LL NEW_MASK = J_MASK[t] & ~SUMS[t];
	    int q = __builtin_popcountll(NEW_MASK);

	    EACH (e, cur) {
		LL key = *e;
		int one = __builtin_popcountll(key & J_MASK[t]);
		key &= ~J_MASK[t];
		REP (c, J[t].size()+1) {
		    if (c >= one) nxt.push_back(key);

		    if (c == one + q) break;
		    if (c == (int)J[t].size()) break;

		    int pos = J[t].rbegin()[c];
		    key |= 1LL<<pos;
		}
	    }

	    sort_unique(nxt);
	    swap(cur, nxt);
	}

//	EACH (e, cur) {
//	    REP (i, N) {
//		eprintf("%lld", (*e)>>i&1);
//	    }
//	    eprintf("\n");
//	}

	EACH (e, cur) {
	    REP (i, N-1) {
		int left = (*e)>>i&1;
		int right = (*e)>>(i+1)&1;
		if (left > right) yes = false;
	    }
	}
    }

    puts(yes? "ACCEPTED": "REJECTED");

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}