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
int A[100011];
int cpy[100011];

int slow() {
    REP (t, N-1) {
	sort(A, A+N-t);
	REP (i, N-t-1) A[i] = A[i+1] - A[i];
    }
    return *A;
}

int fast() {
    int *a = A;
    int tail = N;
    int zero = 0;

    REP (t, N-1) {
	sort(a, a+tail);
	while (tail && *a == 0) {
	    zero++;
	    tail--;
	    a++;
	}

	if (zero) {
	    zero--;
	    tail++;
	    a--;
	    *a = 0;
	}
	REP (i, tail) a[i] = a[i+1] - a[i];

	tail--;
    }

    if (zero) {
	return 0;
    } else {
	return *a;
    }
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    int a = fast();
    printf("%d\n", a);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}