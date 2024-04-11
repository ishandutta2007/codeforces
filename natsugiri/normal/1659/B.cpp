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
int K;
char S[200011];
int F[200011];

void MAIN() {
    scanf("%d%d%s", &N, &K, S);
    REP (i, N) {
	F[i] = 0;
    }

    if (K % 2 == 1) {
	REP (i, N) S[i] = (S[i] == '0'? '1': '0');
    }

    REP (i, N) {
	if (K && S[i] == '0') {
	    K--;
	    F[i]++;
	    S[i] = '1';
	}
    }

    if (K % 2 == 1) {
	F[N-1]++;
	S[N-1] = '0';
	K--;
    }

    F[N-1] += K;
    puts(S);
    rprintf("%d", F, F+N);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}