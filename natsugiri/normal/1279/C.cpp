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
int A[100011];
int B[100011];

bool out[100011];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d", A+i), A[i]--;
    REP (i, M) scanf("%d", B+i), B[i]--;

    REP (i, N) out[i] = 0;
    int outc = 0;
    int pos = 0;
    LL ans = 0;
    REP (j, M) {
	if (out[B[j]]) {
	    outc--;
	    ans++;
	} else {
	    while (!out[B[j]]) {
		out[A[pos]] = true;
		outc++;
		pos++;
	    }
	    outc--;
	    ans++;
	    ans += outc*2;
	}
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}