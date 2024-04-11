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
LL A[150000];
LL B[150000];

bool check() {
    A[N] = A[0];
    REP (i, N) {
	int right = i+1;
	if (A[right] <= 0) return false;
	if (B[i] != A[i] % A[right]) return false;
    }
    return true;
}

// 1 0 1 0 0
// 1 1 1 2 2
// l 2 1 2 2

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld", B+i);

//#ifdef LOCAL
//    long t = time(0);
//    eprintf("%ld\n", t);
//    srand(t);
//    N = 1000;
//    REP (i, N) A[i] = rand() % 180000+ 1;
//    REP (i, N) B[i] = A[i] % A[(i+1)%N];
//#endif

    int ma = *max_element(B, B+N);

    if (ma == 0) {
	REP (i, N) A[i] = 1;
    } else {
	int pos = -1;
	REP (i, N) {
	    int k = i-1;
	    if (k == -1) k = N-1;
	    if (B[i] == ma && B[k] < B[i]) {
		pos = i;
	    }
	}

	if (pos != -1) {
	    A[pos] = B[pos];
	    REP (i_, N-1) {
		int left = pos - 1;
		if (left == -1) left = N-1;
		int right = (pos + 1) % N;
		while (B[left] >= A[pos]) A[pos] += A[right];
		A[left] = A[pos] + B[left];
		pos = left;
	    }

	    int left = pos - 1;
	    if (left == -1) left = N-1;
	    if (B[left] >= A[pos]) {
		A[pos] += A[(pos+1)%N];
	    }
	}
    }

    if (check()) {
	puts("YES");
	rprintf("%lld", A, A+N);
    } else {
	puts("NO");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}