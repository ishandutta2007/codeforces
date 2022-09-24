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
int K;
int Y[511];

int A[511] = {2, 1, 7, 5, 6};
void init() {
#ifdef LOCAL
    N = 498;
    K = 4;
    REP (i, N) A[i] = rand() % 1000000000;
#endif
}

int qcnt;
int query() {
    qcnt++;
    printf("?");
    REP (i, K) printf(" %d", Y[i]+1);
    puts("");
    fflush(stdout);

    int ret = 0;

#ifdef LOCAL
    REP (i, K) ret ^= A[Y[i]];
    eprintf("ret = %d\n", ret);
    sort(Y, Y+K);
    REP (i, K-1) assert(Y[i] != Y[i+1]);
    return ret;
#endif

    scanf("%d", &ret);
    return ret;
}

int dp[511];
int prv[511];
int use[511];

void answer(int ans) {
    printf("! %d\n", ans);
    fflush(stdout);

#ifdef LOCAL
    int tmp = 0;
    REP (i, N) tmp ^= A[i];
    eprintf("x %d\n", tmp);
    eprintf("qcnt %d\n", qcnt);
    assert(qcnt == dp[N]);
#endif
}

void MAIN() {
    scanf("%d%d", &N, &K);

    init();

    memset(dp, 0x3f, sizeof dp);
    memset(prv, -1, sizeof prv);
    dp[0] = 0;
    REP (i, N) if (dp[i] <= N) {
	if (i + K <= N && dp[i] + 1 < dp[i+K]) {
	    dp[i+K] = dp[i] + 1;
	    prv[i+K] = 0;
	}
	for (int m=1; m<K; m++) {
	    int need = K + K - m;
	    int add = need - m;
	    if (need <= N && i + add <= N && dp[i] + 2 < dp[i+add]) {
		dp[i+add] = dp[i] + 2;
		prv[i+add] = m;
	    }
	}
    }

    eprintf("D = %d\n", dp[N]);

    if (dp[N] > 10000) {
	puts("-1");
    } else {
	int rest = N;
	int ans = 0;
	while (rest) {
	    if (prv[rest] == 0) {
		int cnt = 0;
		REP (i, N) if (!use[i]) {
		    Y[cnt++] = i;
		    use[i] = true;
		    if (cnt == K) break;
		}
		assert(cnt == K);
		ans ^= query();
		rest -= K;
	    } else {
		int m = prv[rest];
		int need = K + K - m;
		int add = need - m;

		int cnt = 0;
		REP (i, N) if (!use[i]) {
		    if (cnt < K-m) use[i] = 2;
		    else if (cnt < 2*(K-m)) use[i] = 4;
		    cnt++;
		    if (cnt == 2*(K-m)) break;
		}

		for (int t=2; t<=4; t+=2) {
		    cnt = 0;
		    REP (i, N) if (use[i] == t) {
			Y[cnt++] = i;
		    }

		    REP (i, N) if (cnt < K && use[i] != 2 && use[i] != 4) {
			Y[cnt++] = i;
		    }

		    assert(cnt == K);

		    ans ^= query();
		}

		REP (i, N) if (use[i] == 2 || use[i] == 4) use[i] = 1;

		rest -= add;
	    }
	}

	answer(ans);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}