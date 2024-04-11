#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N;
int A[100011];
bool C[100011];
int L[100011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    REP (i, N) {
	L[i+1] = L[i];
	if (!C[A[i]]) L[i+1]++;
	C[A[i]] = true;
    }

    LL ans = 0;
    memset(C, 0, sizeof C);
    for (int i=N; i--;) {
	if (!C[A[i]]) {
	    ans += L[i];
	}
	C[A[i]] = true;
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}