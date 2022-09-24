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

int N, Q;
char S[200011];

int sums[3][3][200011];

void MAIN() {
    scanf("%d%d%s", &N, &Q, S);

    REP (a, 3) REP (t, 3) {
	REP (i, N) {
	    sums[a][t][i+1] = sums[a][t][i];
	    if (S[i]-'a' == a && i % 3 == t) sums[a][t][i+1]++;
	}
    }
    REP ($, Q) {
	int l, r;
	scanf("%d%d", &l, &r);
	l--;

	int cst = N;
	int alpha[3] = {0, 1, 2};
	do {
	    int hit = 0;
	    REP (t, 3) {
		int a = alpha[t];
		hit += sums[a][t][r] - sums[a][t][l];
	    }
	    amin(cst, r-l-hit);
	} while (next_permutation(alpha, alpha+3));

	printf("%d\n", cst);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}