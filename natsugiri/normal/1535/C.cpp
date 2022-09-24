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
char S[200011];

LL cur[3];
LL nxt[3];

void MAIN() {
    scanf("%s", S);
    N = strlen(S);

    LL ans = 0;
    memset(cur, 0, sizeof cur);

    REP (i, N) {
	memset(nxt, 0, sizeof nxt);
	if (S[i] == '0') {
	    nxt[0]++;
	    nxt[0] += cur[1] + cur[2];
	}
	if (S[i] == '1') {
	    nxt[1]++;
	    nxt[1] += cur[0] + cur[2];
	}
	if (S[i] == '?') {
	    nxt[2]++;
	    nxt[0] += cur[1];
	    nxt[1] += cur[0];
	    nxt[2] += cur[2];
	}

	REP (t, 3) {
	    ans += nxt[t];
	    cur[t] = nxt[t];
	}
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}