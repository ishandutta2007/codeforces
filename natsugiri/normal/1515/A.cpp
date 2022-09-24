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
int X;
int A[111];
int sums[222];

void MAIN() {
    scanf("%d%d", &N, &X);
    REP (i, N) scanf("%d", A+i);
    sort(A, A+N);

    REP (i, 2*N) sums[i+1] = sums[i] + A[i%N];

    bool yes;
    int start = 0;
    if (sums[N] < X) {
	yes = true;
	start = 0;
    } else if (sums[N] == X) {
	yes = false;
    } else {
	yes = false;
	int k = 0;
	REP (i, N) {
	    while (sums[k] - sums[i] < X) k++;
	    if (sums[k] - sums[i] != X) {
		start = i;
		yes = true;
		break;
	    }
	}
    }

    if (yes) {
	puts("YES");
	REP (i, N) printf("%d%c", A[(i+start)%N], " \n"[i==N-1]);
    } else {
	puts("NO");
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}