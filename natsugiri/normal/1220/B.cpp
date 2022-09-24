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

int gcd(int x, int y) {
    while (1) {
	if (x) y %= x; else return y;
	if (y) x %= y; else return x;
    }
}

int N;
int M[1011][1011];
int A[1011];

bool test(int a) {
    A[0] = a;
    for (int j=1; j<N; j++) A[j] = M[0][j] / a;
    REP (i, N) REP (j, i) if ((LL)A[i] * A[j] != M[i][j]) return false;
    return true;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) REP (j, N) scanf("%d", &M[i][j]);

    int g = 0;
    REP (j, N) g = gcd(g, M[0][j]);

    for (int a=1; a*a<=g; a++) if (g % a == 0) {
	if (test(a)) break;
	if (test(g/a)) break;
    }
    rprintf("%d", A, A+N);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}