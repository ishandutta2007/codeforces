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

const LL MOD = (1e9)+7;
int N;
int A[2][400011];
int P[400011];
bool use[400011];

void MAIN() {
    scanf("%d", &N);
    REP (t, 2) {
	REP (i, N) scanf("%d", A[t]+i), A[t][i]--;
    }

    REP (i, N) P[A[0][i]] = A[1][i];
    REP (i, N) use[i] = false;

    LL ans = 1;
    REP (i, N) if (!use[i]) {
	int x = i;
	while (!use[x]) {
	    use[x] = true;
	    x = P[x];
	}
	if (P[i] != i) {
	    ans += ans;
	    if (ans >= MOD) ans -= MOD;
	}
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}