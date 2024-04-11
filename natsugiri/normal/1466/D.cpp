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
LL W[100011];
int deg[100011];
vector<pair<LL, int> > P;
LL ans[100011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld", W+i);
    memset(deg, 0, sizeof (int) * N);

    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	deg[x]++;
	deg[y]++;
    }

    LL sum = 0;
    REP (i, N) sum += W[i];

    P.clear();
    REP (i, N) if (deg[i] > 1) P.emplace_back(W[i], deg[i]);
    sort(P.begin(), P.end());

    ans[1] = sum;
    LL add = 0;
    for (int k=2; k<N; k++) {
	while (P.back().second == 1) P.pop_back();
	add += P.back().first;
	P.back().second--;
	ans[k] = sum + add;
    }
    rprintf("%lld", ans + 1, ans + N);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}