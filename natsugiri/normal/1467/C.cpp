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
VI A[3];
LL S[3];
int mi[3];

void MAIN() {
    REP (i, 3) {
	int n;
	scanf("%d", &n);
	A[i].resize(n);
    }
    REP (i, 3) {
	REP (j, A[i].size()) scanf("%d", &A[i][j]);
    }

    REP (i, 3) {
	EACH (e, A[i]) S[i] += *e;
	mi[i] = *min_element(A[i].begin(), A[i].end());
    }

    LL sum = S[0] + S[1] + S[2];
    LL ans = -(1LL<<60);
    REP (i, 3) {
	amax(ans, sum - 2 * S[i]);
    }

    REP (i, 3) REP (j, i) {
	amax(ans, sum - 2*mi[i] - 2*mi[j]);
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}