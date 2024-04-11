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

int T[6] = { 4, 8, 15, 16, 23, 42 };
int query(int i, int j) {
    printf("? %d %d\n", i+1, j+1);
    fflush(stdout);
#ifdef LOCAL
    eprintf("%d\n", T[i] * T[j]);
    return T[i] * T[j];
#else
    int r;
    scanf("%d", &r);
    return r;
#endif
}

const int S[6] = { 4, 8, 15, 16, 23, 42 };
void solve(int a, int b, int *A) {
    REP (i, 6) REP (j, 6) if (i != j && a == S[i] * S[j]) {
	REP (k, 6) if (i != k && j != k && b == S[j] * S[k]) {
	    A[0] = S[i];
	    A[1] = S[j];
	    A[2] = S[k];
	    return;
	}
    }
}

int A[6];
void MAIN() {
#ifdef LOCAL
    srand(2);
    random_shuffle(T, T+6);
    rprintf("%d", T, T+6);
#endif
    int a = query(0, 1);
    int b = query(1, 2);
    int c = query(3, 4);
    int d = query(4, 5);

    solve(a, b, A);
    solve(c, d, A+3);
    printf("! ");
    rprintf("%d", A, A+6);
    fflush(stdout);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}