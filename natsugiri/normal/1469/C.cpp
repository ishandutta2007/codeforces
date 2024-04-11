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

int N, K;
int H[200011];
LL high[200011], low[200011];

void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, N) scanf("%d", H+i);

    REP (i, N) {
	low[i] = H[i];
	high[i] = (LL)H[i] + K - 1;
    }
    high[0] = H[0];
    high[N-1] = H[N-1];

    REP (i, N-1) {
	amin(high[i+1], high[i] + K - 1);
	amax(low[i+1], low[i] - K + 1);
    }
    for (int i=N-2; i>=0; i--) {
	amin(high[i], high[i+1] + K - 1);
	amax(low[i], low[i+1] - K + 1);
    }

    bool yes = true;
    if (high[0] != H[0]) yes = false;
    if (high[N-1] != H[N-1]) yes = false;
    if (low[0] != H[0]) yes = false;
    if (low[N-1] != H[N-1]) yes = false;
    REP (i, N) {
	if (high[i] < low[i]) yes = false;
    }
    REP (i, N-1) {
	if (high[i] + K - 1 < low[i+1]) yes = false;
	if (low[i] > high[i+1] + K - 1) yes = false;
    }
    puts(yes? "YES": "NO");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}