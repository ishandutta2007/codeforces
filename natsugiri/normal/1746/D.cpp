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

int N, K;
VI G[200011];
LL S[200011];
vector<pair<LL, LL> > dp[200011];

LL calc(LL v, LL k) {
    if (k == 0) {
	return 0;
    }

    if (G[v].empty()) {
	return S[v] * k;
    }

    EACH (e, dp[v]) if (e->first == k) return e->second;

    LL qu = k / G[v].size();
    LL re = k % G[v].size();

    vector<LL> diff;
    LL sum = 0;

    EACH (e, G[v]) {
	LL val = calc(*e, qu);
	sum += val;
	if (re) {
	    diff.push_back(calc(*e, qu+1) - val);
	}
    }

    if (re) {
	sort(diff.begin(), diff.end());
	reverse(diff.begin(), diff.end());
	REP (i, re) sum += diff[i];
    }

    sum += S[v] * k;
    dp[v].emplace_back(k, sum);
    return sum;
}

void MAIN() {
#ifdef LOCAL
    N = 200000;
    K = 1000000000;
    REP (i, N) {
	G[i].clear();
	dp[i].clear();
    }
    for (int i=1; i<N; i++) {
	int p = rand() % i;
	G[p].push_back(i);
    }
    REP (i, N) S[i] = rand() % 10000;


#else
    scanf("%d%d", &N, &K);
    REP (i, N) {
	G[i].clear();
	dp[i].clear();
    }
    REP (i, N-1) {
	int p;
	scanf("%d", &p);
	p--;
	G[p].push_back(i+1);
    }
    REP (i, N) scanf("%lld", S+i);
#endif

    LL ans = calc(0, K);
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}