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

int N;
int K;
LL S[1011];
int D[1011];

LL mul(LL x, LL y) {
    LL z = 0;
    REP (j, K) {
	LL x0 = x >> (2*j) & 3;
	LL y0 = y >> (2*j) & 3;
	assert(0 <= x0 && x0 <= 2);
	assert(0 <= y0 && y0 <= 2);
	LL m = (9 - x0 - y0) % 3;
	z |= m << (2*j);
    }
    return z;
}


void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, N) {
	LL x = 0;
	for (int j=K; j--;) {
	    LL m;
	    scanf("%lld", &m);
	    x |= m << (2*j);
	}
	S[i] = x;
    }
    sort(S, S+N);

    REP (i, N) for (int j=i+1; j<N; j++) {
	LL z = mul(S[i], S[j]);
	if (S[j] < z) {
	    auto it = lower_bound(S+j+1, S+N, z);
	    if (it != S+N && *it == z) {
		D[i]++;
		D[j]++;
		D[it-S]++;
	    }
	}
    }

    LL ans = 0;
    REP (i, N) {
	ans += (LL)D[i] * (D[i]-1) / 2;
    }
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}