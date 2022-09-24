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


const int INF = 1<<29;
int N;
char A[100011];
char B[100011];

void MAIN() {
    scanf("%d%s%s", &N, A, B);
    int diff = 0;
    REP (i, N) if (A[i] != B[i]) diff++;

    int ans = INF;

    if (diff == 0) {
	ans = 0;
    } else {
	int a0 = count(A, A+N, '0');
	int a1 = N - a0;
	int b0 = count(B, B+N, '0');
	int b1 = N - b0;

	if (a0 == b0 && diff % 2 == 0) {
	    amin(ans, diff);
	}

	int same = N - diff;
	if (a0+1 == b1 && same % 2 == 1) {
	    amin(ans, same);
	}
    }


    if (ans == INF) {
	puts("-1");
    } else {
	printf("%d\n", ans);
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}