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

const int INF = 1<<29;
int N;
int X;
int A[511];
int B[511];
int C[511];
int D[511];

void MAIN() {
    scanf("%d%d", &N, &X);
    REP (i, N) scanf("%d", A+i);

    A[N] = X;

    REP (i, N+1) B[i] = A[i];
    sort(B, B+N+1);

    int ans = INF;
    REP (s, N+1) {
	int len = 0;
	REP (i, N+1) {
	    if (i == s) C[N] = B[i];
	    else C[len++] = B[i];
	}

	REP (i, N+1) D[i] = A[i];

	int cnt = 0;
	REP (i, N) {
	    if (C[i] != D[i]) {
		if (C[i] == D[N] && D[i] > D[N]) {
		    swap(D[i], D[N]);
		    cnt++;
		} else {
		    cnt = INF;
		    break;
		}
	    }
	}

	amin(ans, cnt);
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