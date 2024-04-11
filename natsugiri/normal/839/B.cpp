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

int N, K;
int A[10011];

void MAIN() {
    scanf("%d%d", &K, &N);
    REP (i, N) scanf("%d", A+i);

    int f = K;
    int t = K + K;
    REP (i, N) {
	int a = A[i] / 4;
	int g = min(f, a);
	f -= g;
	A[i] -= g * 4;
    }
    REP (i, N) {
	int a = A[i] / 2;
	int g = min(t, a);
	t -= g;
	A[i] -= g * 2;
    }

    int o = t;
    REP (i, N) {
	int a = A[i] / 2;
	int g = min(f, a);
	f -= g;
	o += g;
	A[i] -= g * 2;
    }

    o += f + f;
    REP (i, N) {
	int g = min(o, A[i]);
	o -= g;
	A[i] -= g;
    }

    if (*max_element(A, A+N) > 0) puts("NO");
    else puts("YES");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}