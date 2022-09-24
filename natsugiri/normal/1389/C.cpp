#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
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
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}



int N;
char S[200011];
int D[10];
int C[10][10];

void MAIN() {
    scanf("%s", S);
    N = strlen(S);

    int ans = N;
    memset(D, 0, sizeof D);
    memset(C, 0, sizeof C);
    REP (i, N) {
	int k = S[i] - '0';
	D[k]++;
	REP (d, 10) if (k != d) {
	    if (C[k][d] % 2 == 0) C[k][d]++;
	    if (C[d][k] % 2 == 1) C[d][k]++;
	}
    }

    REP (k, 10) {
	amin(ans, N - D[k]);

	REP (d, 10) if (k != d) {
	    int a = C[k][d]/2*2;
	    amin(ans, N - a);
	}
    }

    printf("%d\n", ans);

}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}