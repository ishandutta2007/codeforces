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
char S[2][100011];
int cur[3];
int nxt[3];

void MAIN() {
    scanf("%d%s%s", &N, S[0], S[1]);

    memset(cur, 0xc0, sizeof cur);
    cur[0] = 0;
    REP (i, N) {
	memset(nxt, 0xc0, sizeof nxt);

	int s0 = S[0][i] - '0';
	int s1 = S[1][i] - '0';
	if (s0 == 0 && s1 == 0) {
	    amax(nxt[0], cur[0] + 1);
	    amax(nxt[1], cur[0]);
	    amax(nxt[0], cur[1] + 1);
	    amax(nxt[1], cur[1]);
	    amax(nxt[0], cur[2] + 2);
	} else if (s0 == 1 && s1 == 1) {
	    amax(nxt[2], cur[0]);
	    amax(nxt[0], cur[0]);
	    amax(nxt[0], cur[1] + 2);
	    amax(nxt[2], cur[2]);
	} else {
	    amax(nxt[0], cur[0] + 2);
	}

	REP (a, 3) cur[a] = nxt[a];
    }

    printf("%d\n", cur[0]);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}