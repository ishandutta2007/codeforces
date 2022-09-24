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

int N;
LL X[5011], Y[5011];

LL sq(LL x) { 
    return x * x;
}

LL dist(int a, int b) {
    return sq(X[a] - X[b]) + sq(Y[a] - Y[b]);
}
VI ans;
bool use[5011];


void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld%lld", X+i, Y+i);

    int p = 0;
    REP (i, N) if (X[p] > X[i]) p = i;
    ans.push_back(p);
    use[p] = true;

    REP (t, N-1) {
	int q = -1;
	LL d = -1;
	REP (j, N) if (!use[j]) {
	    LL tmp = dist(ans.back(), j);
	    if (tmp > d) {
		d = tmp;
		q = j;
	    }
	}

	ans.push_back(q);
	use[q] = true;
    }

    EACH (e, ans) (*e)++;
    rprintf("%d", ans.begin(), ans.end());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}