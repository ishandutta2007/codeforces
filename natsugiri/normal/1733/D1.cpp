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
LL X, Y;
char buf[3011];
int S[3011];

const int SIZE = 20;
LL mem[2][2][SIZE];
LL (*cur)[SIZE] = mem[0];
LL (*nxt)[SIZE] = mem[1];

void MAIN() {
    scanf("%d%lld%lld", &N, &X, &Y);
    
    scanf("%s", buf);
    REP (i, N) S[i] = buf[i] - '0';
    scanf("%s", buf);
    REP (i, N) S[i] ^= buf[i] - '0';

    // rprintf("%d", S, S+N);

    memset(cur, 0x3f, sizeof (mem[0]));
    const LL INF = cur[0][0];
    cur[0][0] = 0;

    REP (i, N) {
	memset(nxt, 0x3f, sizeof (mem[0]));

	REP (a, 2) REP (b, SIZE) {

	    if (i >= 2 && b + 2 < SIZE) amin(cur[a][b+2], cur[a][b]);

	    REP (cls, b+1) {
		int nb = b - cls;
		if (a) {
		    {
			int na = (1 + cls + S[i]) % 2;
			amin(nxt[na][nb], cur[a][b] + X + Y * cls);
		    }
		    if (nb+1 < SIZE) {
			int na = (cls + S[i]) % 2;
			amin(nxt[na][nb+1], cur[a][b] + Y * cls);
		    }
		} else {
		    int na = (cls + S[i]) % 2;
		    amin(nxt[na][nb], cur[a][b] + Y * cls);
		}
	    }
	}
	swap(cur, nxt);
    }

    LL ans = cur[0][0];
    if (ans == INF) {
	puts("-1");
    } else {
	printf("%lld\n", ans);
    }

}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}