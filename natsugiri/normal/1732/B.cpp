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
char S[100011];

int buf[2][2];
int *cur = buf[0];
int *nxt = buf[1];

void MAIN() {
    scanf("%d%s", &N, S);

    memset(cur, 0x3f, sizeof buf[0]);
    cur[0] = 0;
    REP (i, N-1) {
	memset(nxt, 0x3f, sizeof buf[0]);

	REP (a, 2) {
	    int left = (S[i]-'0') ^ a;
	    int right = (S[i+1]-'0') ^ a;

	    if (left <= right) {
		amin(nxt[a], cur[a]);
	    }
	    if (left <= (right ^ 1)) {
		amin(nxt[a^1], cur[a]+1);
	    }
	}

	swap(cur, nxt);
    }

    int ans = min(cur[0], cur[1]);
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}