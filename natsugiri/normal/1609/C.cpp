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

const int MAX = 10000011;
int min_factor[MAX];
vector<int>prime;
bool init_prime() {
    assert("Call once" && prime.empty());
    for (int i=2; i<MAX; i+=2) min_factor[i] = 2;
    for (int i=3; i*i<MAX; i++) {
	if (min_factor[i] == 0) {
	    min_factor[i] = i;
	    for (int j=i*i; j<MAX; j+=i)
		if (min_factor[j] == 0) min_factor[j] = i;
	}
    }
    for (int i=2; i<MAX; i++) {
	if (min_factor[i] == 0) min_factor[i] = i;
	if (min_factor[i] == i) prime.push_back(i);
    }
    return true;
}

bool is_prime(int n) {
    return min_factor[n] == n;
}

int N, E;
VI X[200011];

void MAIN() {
    scanf("%d%d", &N, &E);
    REP (i, E) X[i].clear();

    REP (i, N) {
	int a;
	scanf("%d", &a);

	if (a == 1) {
	    X[i % E].push_back(1);
	} else if (is_prime(a)) {
	    X[i % E].push_back(2);
	} else {
	    X[i % E].push_back(0);
	}
    }

    LL ans = 0;
    REP (e, E) {
	int l = 0;
	REP (i, X[e].size()) {
	    if (X[e][i] == 2) {
		int r = i+1;
		while (r < (int)X[e].size() && X[e][r] == 1) r++;

		ans += (LL)(i-l+1) * (LL)(r-i) - 1;
		l = i+1;
	    } else if (X[e][i] == 0) {
		l = i+1;
	    }
	}
    }

    printf("%lld\n", ans);
}

int main() {
    init_prime();

    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}