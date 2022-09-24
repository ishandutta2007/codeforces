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

int N, X;
int A[100011];

void MAIN() {
    scanf("%d%d", &N, &X);
    REP (i, N) scanf("%d", A+i);

    LL sum = 0;
    REP (i, N) sum += A[i];
    int ans = -1;
    if (sum % X) {
	ans = N;
    } else {
	VI guess;
	REP (i, N) if (A[i] % X) {
	    guess.push_back(N-1-i);
	    break;
	}
	for (int i=N; i--;) if (A[i] % X) {
	    guess.push_back(i);
	}
	if (guess.empty()) ans = -1;
	else {
	    ans = guess[0];
	    EACH (e, guess) amax(ans, *e);
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