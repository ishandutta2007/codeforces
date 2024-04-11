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
char C;
char S[300011];
bool X[300011];

void MAIN() {
    scanf("%d %c%s", &N, &C, S);

    memset(X, 0, sizeof (bool) * (N+1));

    REP (i, N) if (S[i] != C) {
	X[i+1] = true;
    }
    for (int i=1; i<=N; i++) if (!X[i]) {
	for (int j=i; j<=N; j+=i) if (X[j]) {
	    X[i] = true;
	    break;
	}
    }

    if (!X[1]) {
	puts("0");
	return;
    } else {
	for (int i=1; i<=N; i++) if (!X[i]) {
	    puts("1");
	    printf("%d\n", i);
	    return;
	}

	puts("2");
	printf("%d %d\n", N-1, N);
	return;
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}