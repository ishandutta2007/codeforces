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

int N, M;
char A[5011];
char B[5011];

int buf[2][5011];
int *cur = buf[0];
int *nxt = buf[1];

void MAIN() {
    scanf("%d%d%s%s", &N, &M, A, B);

    int ans = 0;
    cur[0] = 0;
    REP (i, N) {
	memset(nxt, 0, sizeof buf[0]);

	REP (j, M) {
	    if (A[i] == B[j]) {
		amax(ans, cur[j] + 2);
		amax(nxt[j+1], cur[j] + 2);
	    }
	    amax(nxt[j], cur[j] - 1);
	    amax(cur[j+1], cur[j] - 1);
	}

	swap(cur, nxt);
    }

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}