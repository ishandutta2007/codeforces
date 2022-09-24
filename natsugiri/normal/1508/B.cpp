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
LL K;
LL pow2[100011];
void init() {
    pow2[0] = 1;
    REP (i, 100010) {
	pow2[i+1] = min(1LL<<60, pow2[i] * 2);
    }
}

void MAIN() {
    scanf("%d%lld", &N, &K);

    if (pow2[N-1] < K) {
	puts("-1");
    } else {
	VI ans, qu;
	int c = N;
	REP (i, N) {
	    c--;

	    LL p;
	    if (c == 0) p = 1;
	    else p = pow2[c-1];

	    qu.push_back(i+1);
	    if (p >= K) {
		while (qu.size()) {
		    ans.push_back(qu.back());
		    qu.pop_back();
		}
	    } else {
		K -= p;
	    }
	}
	rprintf("%d", ans.begin(), ans.end());
    }

}

int main() {
    init();
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}