#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N, M;
ULL B;
struct Man {
    ULL x, k;
    int mask;
    bool operator<(const Man &y) const {
	return k < y.k;
    }
} F[111];


ULL dp[2][1<<20];
ULL *cur = dp[0], *nxt = dp[1];

int main() {
    scanf("%d%d%llu", &N, &M, &B);
    int al = 0;
    REP (i, N) {
	int m, t;
	scanf("%llu%llu%d", &F[i].x, &F[i].k, &m);
	F[i].mask = 0;
	REP (j, m) {
	    scanf("%d", &t);
	    t--;
	    F[i].mask |= 1<<t;
	}

	al |= F[i].mask;
    }

    sort(F, F+N);

    memset(dp, 0x3f, sizeof dp);
    const ULL INF = dp[0][0];
    ULL ans = dp[0][0];
    cur[0] = 0;


    REP (i, N) {
	memset(nxt, 0x3f, sizeof dp[0]);
	REP (s, 1<<M) if (cur[s] != INF) {
	    amin(nxt[s], cur[s]);
	    amin(nxt[s | F[i].mask], cur[s] + F[i].x);
	}

	amin(ans, nxt[(1<<M)-1] + F[i].k * B);
	swap(cur, nxt);
    }

    if (ans == INF) puts("-1");
    else printf("%llu\n", ans);

    return 0;
}