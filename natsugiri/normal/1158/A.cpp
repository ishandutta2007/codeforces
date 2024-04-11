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

int N, M;
int B[100011];
int G[100011];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d", B+i);
    REP (i, M) scanf("%d", G+i);

    sort(B, B+N);
    sort(G, G+M);
    if (B[N-1] > G[0]) {
	puts("-1");
    } else {
	LL ans = 0;
	REP (i, N) ans += B[i];
	ans *= M;
	if (B[N-1] == G[0]) {
	    REP (i, M) {
		ans += G[i];
		ans -= B[N-1];
	    }
	} else {
	    REP (i, M) {
		ans += G[i];
		if (i) ans -= B[N-1];
		else ans -= B[N-2];
	    }
	}

	printf("%lld\n", ans);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}