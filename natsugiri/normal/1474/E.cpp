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

LL sq(LL x) { return x * x; }

int N;
int P[100011];
vector<pair<int, int> > ans;

void MAIN() {
    scanf("%d", &N);

    ans.clear();
    LL cst = 0;

    int L = 1, R = N-2;
    while (L <= R) {
	if (L <= R) {
	    ans.emplace_back(R, 0);
	    cst += sq(R);
	    R--;
	}
	if (L <= R) {
	    ans.emplace_back(L, N-1);
	    cst += sq(N-1-L);
	    L++;
	}
    }
    ans.emplace_back(0, N-1);
    cst += sq(N-1);
    REP (i, N) P[i] = i;

    for (int i=ans.size(); i--;) {
	assert(P[ans[i].first] == ans[i].first);
	swap(P[ans[i].first], P[ans[i].second]);
    }

    printf("%lld\n", cst);
    REP (i, N) P[i]++;
    rprintf("%d", P, P+N);
    printf("%d\n", (int)ans.size());
    REP (i, ans.size()) printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}