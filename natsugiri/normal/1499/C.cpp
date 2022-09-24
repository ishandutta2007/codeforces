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
LL C[100011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld", C+i);

    LL ans = 1LL<<60;
    LL sum[2] = {};
    LL cnt[2] = {};
    LL mi[2] = {1LL<<60, 1LL<<60};

    REP (i, N) {
	sum[i%2] += C[i];
	cnt[i%2]++;
	amin(mi[i%2], C[i]);

	if (i >= 1) {
	    LL tmp = 0;
	    tmp += sum[0] + mi[0] * (N - cnt[0]);
	    tmp += sum[1] + mi[1] * (N - cnt[1]);
	    amin(ans, tmp);
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